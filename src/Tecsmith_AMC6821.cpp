/*!
 * @file Tecsmith_AMC6821.cpp
 *
 * @mainpage Tecsmith AMC6821 Fan control module
 *
 * @section intro_sec Introduction
 *
 *   I2C Driver for the Library for the AMC6821 Fan control module
 *
 *   This is a library for the Tecsmith AMC6821 breakout:
 *   http://c1k.it/amc6
 *
 * @section dependencies Dependencies
 *
 *   This library depends on the Adafruit BusIO library
 *
 *   This library depends on the Adafruit Unified Sensor library  // ?????
 *
 * @section author Author
 *
 *   Vino Rodrigues for Tecsmith Australia
 *
 * @section license License
 *
 *   MIT (@see: LICENSE.md)
 *
 * @section  HISTORY
 *
 *   v2.0 - First release in this format
 *
 */

#include "Arduino.h"
#include <Wire.h>

#include "Tecsmith_AMC6821.h"

// ---------- Class functions ----------

/**
 * @brief Construct a new Tecsmith_AMC6821::Tecsmith_AMC6821 object
 */
Tecsmith_AMC6821::Tecsmith_AMC6821(void) {}

/**
 * @brief Destroy the Tecsmith_AMC6821::Tecsmith_AMC6821 object
 */
Tecsmith_AMC6821::~Tecsmith_AMC6821(void) {}

// ---------- Helpers ----------

/**
 * @brief Reads one byte
 */
uint8_t Tecsmith_AMC6821::read(uint8_t addr) {
  Adafruit_BusIO_Register slot = Adafruit_BusIO_Register(i2c_dev, addr);
  return slot.read();
}

/**
 * @brief Writes one byte, preserving prior bits in optional mask
 */
bool Tecsmith_AMC6821::write(uint8_t addr, uint8_t data, uint8_t mask) {
  Adafruit_BusIO_Register slot = Adafruit_BusIO_Register(i2c_dev, addr);

  if (mask == 0xFF) {
    return slot.write(data);
  } else {
    uint8_t val = slot.read();
    val &= ~mask;  // and not mask
    val |= data & mask;  // or (data and mask)
    return slot.write(val);
  }
}

/**
 * @brief Reads two bytes
 *
 * WARNING: The low byte should be read first. This method causes the high
 * byte to be frozen until both the high and low byte registers have been
 * read from, preventing erroneous TACH readings.
 */
uint16_t Tecsmith_AMC6821::read2(uint8_t addrL, uint8_t addrH) {
  Adafruit_BusIO_Register lsb = Adafruit_BusIO_Register(i2c_dev, addrL);
  Adafruit_BusIO_Register msb = Adafruit_BusIO_Register(i2c_dev, addrH);
  uint8_t lo = lsb.read();
  uint8_t hi = msb.read();
  if ((0xFF == hi) && (0xFF == lo)) return 0;  // usually 0xFFFF indicates invalid value
  return (hi << 8) | lo;
}

/**
 */
bool Tecsmith_AMC6821::write2(uint8_t addrL, uint8_t addrH, uint16_t data) {
  return false;  // TODO
}

// ---------- * ----------

/*!
 * @brief  Sets up the hardware and initializes I2C
 * @param  i2c_address
 *         The I2C address to be used.
 * @param  wire
 *         The Wire object to be used for I2C connections.
 * @return True if initialization was successful, otherwise false.
 */
bool Tecsmith_AMC6821::begin(uint8_t i2c_address, TwoWire *wire) {
  if (i2c_dev) {
    delete i2c_dev; // remove old interface
  }

  i2c_dev = new Adafruit_I2CDevice(i2c_address, wire);

  if (!i2c_dev->begin()) {
    Serial.println("Address not found");
    return false;
  }

  // make sure we're talking to the right chip
  if ((getDeviceID() != AMC6821_DEVICE_ID) ||
      (getCompanyID() != AMC6821_COMPANY_ID)) {
    Serial.println("Wrong device ID");
    return false;
  }

  return _init();
}

/**
 * @brief Does all the hard work after begin
 */
bool Tecsmith_AMC6821::_init() {
  reset();
  return start();
}

/**
 * @brief Sends a reset command to the chip.
 */
bool Tecsmith_AMC6821::reset() {
  bool ret;
  ret = write(AMC6821_REG_CONF2, AMC6821_CONF2_RST, AMC6821_CONF2_RST);
  delay(100);  // Include a short delay to allow the chip to cycle.
  return ret;
}

/**
 * @brief Sends a start command to the chip
 */
bool Tecsmith_AMC6821::start() {
  return write(AMC6821_REG_CONF1, AMC6821_CONF1_START, AMC6821_CONF1_START);
}

/**
 * @brief Sends a stop command to the chip
 */
bool Tecsmith_AMC6821::stop() {
  return write(AMC6821_REG_CONF1, 0, AMC6821_CONF1_START);
}

// ---------- Identification Registers ----------

/**
 * @brief
 */
uint8_t Tecsmith_AMC6821::getDeviceID() {
  return read(AMC6821_REG_DEV_ID);
}

/**
 * @brief
 */
uint8_t Tecsmith_AMC6821::getCompanyID() {
  return read(AMC6821_REG_COMP_ID);
}

/**
 */
uint8_t Tecsmith_AMC6821::getPartRevision() {
  return read(AMC6821_REG_CONF3) & AMC6821_MASK_CONF3_REV;
}

// ---------- Configuration Registers ----------

/**
 * @brief
 */
uint8_t Tecsmith_AMC6821::getConfig(byte no) {
  return read(_confAddr(no));
}

/**
 */
bool Tecsmith_AMC6821::getStartMonitor() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_START);
}

/**
 */
bool Tecsmith_AMC6821::getGlobalIntEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_FAN_INT_EN);
}

/**
 */
bool Tecsmith_AMC6821::getRPMIntEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_FANIE);
}

/**
 */
bool Tecsmith_AMC6821::getPWMInvert() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_PWMINV);
}

/**
 */
bool Tecsmith_AMC6821::getFanFaultPinEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_FAN_FAULT_EN);
}

/**
 */
amc6821_conf1_fdrc_t Tecsmith_AMC6821::getFanControlMode() {
  uint8_t reg = (read(AMC6821_REG_CONF1) & AMC6821_MASK_CONF1_FDRC) >> 5;
  switch (reg) {
    case 0: return AMC6821_CONF1_FDRC_SOFTWARE_DCY; break;
    case 1: return AMC6821_CONF1_FDRC_SOFTWARE_RPM; break;
    case 3: return AMC6821_CONF1_FDRC_MAX_SPEED; break;
    default: return AMC6821_CONF1_FDRC_AUTO_REMOTE; break;
  }
}

/**
 */
bool Tecsmith_AMC6821::getThermIntEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_THERMOVIE);
}

/**
 */
bool Tecsmith_AMC6821::getPWMOutEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_PWM_EN);
}

/**
 */
bool Tecsmith_AMC6821::getTachMode() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_TACH_MODE);
}

/**
 */
bool Tecsmith_AMC6821::getTachEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_TACH_EN);
}

/**
 */
bool Tecsmith_AMC6821::getRemoteFailureIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_RTFIE);
}

/**
 */
bool Tecsmith_AMC6821::getLTIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_LTOIE);
}

/**
 */
bool Tecsmith_AMC6821::getRTIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_RTOIE);
};

/**
 */
bool Tecsmith_AMC6821::getLPSVIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_PSVIE);
}

/**
 */
bool Tecsmith_AMC6821::getTermFanEnable() {
  return !!(read(AMC6821_REG_CONF3) & AMC6821_CONF3_THERM_FAN_EN);
}

/**
 */
bool Tecsmith_AMC6821::getOVREnable() {
  return !!(read(AMC6821_REG_CONF4) & AMC6821_CONF4_OVREN);
}

/**
 */
bool Tecsmith_AMC6821::getTachReadingFast() {
  return !!(read(AMC6821_REG_CONF4) & AMC6821_CONF4_TACH_FAST);
}

/**
 */
bool Tecsmith_AMC6821::getPulseNumber() {
  return !!(read(AMC6821_REG_CONF4) & AMC6821_CONF4_PSPR);
}

/**
 */
bool Tecsmith_AMC6821::setStartMonitor(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setGlobalIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setRPMIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setPWMInvert(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setFanFaultPinEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setFanControlMode(amc6821_conf1_fdrc_t mode) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setThermIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setPWMOutEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setTachMode(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setTachEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setRemoteFailureIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setLTIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setRTIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setLPSVIntEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setReset() { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setTermFanEnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setOVREnable(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setTachReadingFast(bool on) { return false;  /* // TODO */ }

/**
 */
bool Tecsmith_AMC6821::setPulseNumber(bool on) { return false;  /* // TODO */ }

// ---------- Status Registers ----------

/**
 * @brief
 */
uint8_t Tecsmith_AMC6821::getStatus(byte no) {
  return read(_statAddr(no));
}

/**
 */
bool Tecsmith_AMC6821::getFanFast() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RPM_ALARM);
}

/**
 */
bool Tecsmith_AMC6821::getFanSlow() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_FANS);
}

/**
 */
bool Tecsmith_AMC6821::getRTHigh() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RTH);
}

/**
 */
bool Tecsmith_AMC6821::getRTLow() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RTL);
}

/**
 */
bool Tecsmith_AMC6821::getRTOverTherm() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_R_THERM);
}

/**
 */
bool Tecsmith_AMC6821::getRTFailure() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RTF);
}

/**
 */
bool Tecsmith_AMC6821::getLTHigh() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_LTH);
}

/**
 */
bool Tecsmith_AMC6821::getLTLow() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_LTL);
}

/**
 */
bool Tecsmith_AMC6821::getRTOverCritical() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_RTC);
}

/**
 */
bool Tecsmith_AMC6821::getLTOverCritical() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_LTC);
}

/**
 */
bool Tecsmith_AMC6821::getLTBelowTherm() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_LPSV);
}

/**
 */
bool Tecsmith_AMC6821::getLTOverTherm() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_L_THERM);
}

/**
 */
bool Tecsmith_AMC6821::getThermInput() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_THERM_IN);
}

// ---------- Temperature Monitoring ----------

/**
 * @brief
 */
int8_t Tecsmith_AMC6821::getLocalTemp() {
  return _toInt8( read(AMC6821_REG_LTEMP_HI) );
}

/**
 * @brief
 */
int8_t Tecsmith_AMC6821::getRemoteTemp() {
  return _toInt8( read(AMC6821_REG_RTEMP_HI) );
}

/**
 * @brief
 */
int32_t Tecsmith_AMC6821::getLocalMilliTemp() {
  int32_t res;
  res = ((read(AMC6821_REG_TEMP_LBYTE) & 0xE0) >> 5);  // mask, then shift right 5
  res = res * 125;
  res = res + (getLocalTemp() * 1000);
  getRemoteTemp();  // dummy read to enable LBYTE again, see p. 13
  return res;
}

/**
 * @brief
 */
int32_t Tecsmith_AMC6821::getRemoteMilliTemp() {
  int32_t res;
  res = (read(AMC6821_REG_TEMP_LBYTE) & 0x07);  // mask
  res = res * 125;
  return res + (getRemoteTemp() * 1000);
}

int8_t Tecsmith_AMC6821::getLocalHighTempLimit() {
  return read(AMC6821_REG_LTEMP_LIMIT_MAX);
}

int8_t Tecsmith_AMC6821::getLocalLowTempLimit() {
  return read(AMC6821_REG_LTEMP_LIMIT_MIN);
}

int8_t Tecsmith_AMC6821::getLocalThermLimit() {
  return read(AMC6821_REG_LTHERM_LIMIT);
}

int8_t Tecsmith_AMC6821::getRemoteHighTempLimit() {
  return read(AMC6821_REG_RTEMP_LIMIT_MAX);
}

int8_t Tecsmith_AMC6821::getRemoteLowTempLimit() {
  return read(AMC6821_REG_RTEMP_LIMIT_MIN);
}

int8_t Tecsmith_AMC6821::getRemoteThermLimit() {
  return read(AMC6821_REG_RTHERM_LIMIT);
}

int8_t Tecsmith_AMC6821::getLocalCriticalTemp() {
  return read(AMC6821_REG_LTEMP_CRIT);
}

int8_t Tecsmith_AMC6821::getPassiveCoolingTemp() {
  return read(AMC6821_REG_PSV_TEMP);
}

int8_t Tecsmith_AMC6821::getRemoteCriticalTemp() {
  return read(AMC6821_REG_RTEMP_CRIT);
}

// ---------- PWM Controler ----------

/**
 */
uint8_t Tecsmith_AMC6821::getFanCharacteristics() {
  return read(AMC6821_REG_FAN_CHARS);
}

/**
 */
uint8_t Tecsmith_AMC6821::getDutyCycleLowTemp() {
  return read(AMC6821_REG_DCY_LOW_TEMP);
}

/**
 */
uint8_t Tecsmith_AMC6821::getDutyCycle() {
  return read(AMC6821_REG_DCY);
}

/**
 */
uint8_t Tecsmith_AMC6821::getDutyCycleRamp() {
  return read(AMC6821_REG_DCY_RAMP);
}

/**
 */
uint8_t Tecsmith_AMC6821::getLocalTempFanControl() {
  return read(AMC6821_REG_LTEMP_FAN_CTRL);
}

/**
 */
uint8_t Tecsmith_AMC6821::getRemoteTempFanControl() {
  return read(AMC6821_REG_RTEMP_FAN_CTRL);
}

// ---------- TACH (RPM) Measurement ----------

/**
 */
uint16_t Tecsmith_AMC6821::getTachData() {
  return read2(AMC6821_REG_TDATA_LOW, AMC6821_REG_TDATA_HI);
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachLowLimit() {
  return read2(AMC6821_REG_TACH_LLIMITL, AMC6821_REG_TACH_LLIMITH);
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachHighLimit() {
  return read2(AMC6821_REG_TACH_HLIMITL, AMC6821_REG_TACH_HLIMITH);
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachSetting() {
  return read2(AMC6821_REG_TACH_SETTINGL, AMC6821_REG_TACH_SETTINGH);
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachDataRPM() {
  return _toRPM( getTachData() );
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachLowLimitRPM() {
  return _toRPM( getTachLowLimit() );
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachHighLimitRPM() {
  return _toRPM( getTachHighLimit() );
}

/**
 */
uint16_t Tecsmith_AMC6821::getTachSettingRPM() {
  return _toRPM( getTachSetting() );
}

// ---------- Privates ----------

/**
 * @brief Converts unsigned byte to signed byte
 */
int8_t Tecsmith_AMC6821::_toInt8(uint8_t x) {
  return ( x ^ 0x80 ) - 0x80;
}

/**
 * @brief Converts bit data to RPM for TACH functions
 */
uint16_t Tecsmith_AMC6821::_toRPM(uint16_t x) {
  if (0 == x) return 0;  // protect against div by zero
  unsigned long ret = AMC6821_FAN_RPM_NUMERATOR / x;
  return (uint16_t) ret;
}

/**
 * @brief Get the config address by number
 */
uint8_t Tecsmith_AMC6821::_confAddr(byte no) {
  switch (no) {
    case 1: return AMC6821_REG_CONF1; break;
    case 2: return AMC6821_REG_CONF2; break;
    case 3: return AMC6821_REG_CONF3; break;
    default: return AMC6821_REG_CONF4;
  }
  return -1;
}

/**
 * @brief Get the status address by number
 */
uint8_t Tecsmith_AMC6821::_statAddr(byte no) {
  switch (no) {
    case 1: return AMC6821_REG_STAT1; break;
    default: return AMC6821_REG_STAT2;
  }
  return -1;
}
