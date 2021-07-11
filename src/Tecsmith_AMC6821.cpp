/*!
 * @file Tecsmith_AMC6821.cpp
 *
 * @mainpage Tecsmith AMC6821 Fan control module
 *
 * @section intro_sec Introduction
 *
 *   I2C Driver for the Library for the AMC6821 Fan control module
 *
 *   This is a library is written to work with the AMC6821 Breakout, http://c1k.it/amc6
 *
 * @section dependencies Dependencies
 *
 *   This library depends on the Adafruit BusIO library, https://github.com/adafruit/Adafruit_BusIO
 *
 * @section author Author
 *
 *   Vino Rodrigues for Tecsmith Australia
 *
 * @section license License
 *
 *   MIT (@see: ../LICENSE.md)
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
 * @brief Reads two bytes
 *
 * **Note:** The low byte should be read first. This method causes the high
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
 * @brief // TODO
 */
bool Tecsmith_AMC6821::write2(uint8_t addrL, uint8_t addrH, uint16_t data) {
  return false;  // TODO
}

/**
 * @brief Writes bit on or off based on a mask
 */
bool Tecsmith_AMC6821::writeBit(uint8_t addr, uint8_t mask, bool on) {
  uint8_t val = on ? mask : 0;
  return write(addr, val, mask);
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
bool Tecsmith_AMC6821::begin(uint8_t i2c_address, TwoWire *wire, amc6821_conf1_fdrc_t mode) {
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

  return _init(mode);
}

bool Tecsmith_AMC6821::begin(TwoWire *wire, amc6821_conf1_fdrc_t mode) {
  return begin(AMC6821_I2CADDR_DEFAULT, wire, mode);
}

bool Tecsmith_AMC6821::begin(amc6821_conf1_fdrc_t mode) {
  return begin(AMC6821_I2CADDR_DEFAULT, &Wire, mode);
}

/**
 * @brief Sends a reset command to the chip.  Similar to `setReset`, but adds a 100 mil delay
 */
bool Tecsmith_AMC6821::reset() {
  bool started;
  started = getStartMonitor();
  if (started) stop();
  writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_RST, true);  // reset is immediate, with no response
  delay(100);  // Include a short delay to allow the chip to cycle.
  if (started) start();
  return true;
}

/**
 * @brief Sends a start command to the chip
 */
bool Tecsmith_AMC6821::start() {
  bool started = getStartMonitor();
  if (started) {
    stop();
    delay(100);
  }
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_START, true);
}

/**
 * @brief Sends a stop command to the chip
 */
bool Tecsmith_AMC6821::stop() {
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_START, false);
}

// ---------- Identification Registers ----------

/**
 * @brief Get Device ID, should be 0x21
 */
uint8_t Tecsmith_AMC6821::getDeviceID() {
  return read(AMC6821_REG_DEV_ID);
}

/**
 * @brief Get Company ID, should be 0x49
 */
uint8_t Tecsmith_AMC6821::getCompanyID() {
  return read(AMC6821_REG_COMP_ID);
}

/**
 * @brief Get the chip revision number
 */
uint8_t Tecsmith_AMC6821::getPartRevision() {
  return read(AMC6821_REG_CONF3) & AMC6821_MASK_CONF3_REV;
}

// ---------- Configuration Registers ----------

/**
 * @brief Retrive the Configuration Register byte
 * @param no
 *        Register number, from 1 to 4
 */
uint8_t Tecsmith_AMC6821::getConfig(byte no) {
  return read(_confAddr(no));
}

/**
 * @brief Get the START bit
 */
bool Tecsmith_AMC6821::getStartMonitor() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_START);
}

/**
 * @brief Get the INT-EN bit
 */
bool Tecsmith_AMC6821::getGlobalIntEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_FAN_INT_EN);
}

/**
 * @brief Get the FANIE bit
 */
bool Tecsmith_AMC6821::getRPMIntEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_FANIE);
}

/**
 * @brief Get the PWMINV bit
 */
bool Tecsmith_AMC6821::getPWMInvert() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_PWMINV);
}

/**
 * @brief Get the FAN-Fault-EN bit
 */
bool Tecsmith_AMC6821::getFanFaultPinEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_FAN_FAULT_EN);
}

/**
 * @brief Get the Fan Control Mode enum (FDRC1 & FDRC0 bits)
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
 * @brief Get the THERMOVIE bit
 */
bool Tecsmith_AMC6821::getThermIntEnable() {
  return !!(read(AMC6821_REG_CONF1) & AMC6821_CONF1_THERMOVIE);
}

/**
 * @brief Get the PWM-EN bit
 */
bool Tecsmith_AMC6821::getPWMOutEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_PWM_EN);
}

/**
 * @brief Get the TACH-MODE bit
 */
bool Tecsmith_AMC6821::getTachMode() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_TACH_MODE);
}

/**
 * @brief Get the TACH-EN bit
 */
bool Tecsmith_AMC6821::getTachEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_TACH_EN);
}

/**
 * @brief Get the RTFIE bit
 */
bool Tecsmith_AMC6821::getRemoteFailureIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_RTFIE);
}

/**
 * @brief Get the LTOIE bit
 */
bool Tecsmith_AMC6821::getLTIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_LTOIE);
}

/**
 * @brief Get the RTOIE bit
 */
bool Tecsmith_AMC6821::getRTIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_RTOIE);
};

/**
 * @brief Get the PSVIE bit
 */
bool Tecsmith_AMC6821::getLPSVIntEnable() {
  return !!(read(AMC6821_REG_CONF2) & AMC6821_CONF2_PSVIE);
}

/**
 * @brief Get the THERM-FAN-EN bit
 */
bool Tecsmith_AMC6821::getTermFanEnable() {
  return !!(read(AMC6821_REG_CONF3) & AMC6821_CONF3_THERM_FAN_EN);
}

/**
 * @brief Get the OVREN bit
 */
bool Tecsmith_AMC6821::getOVREnable() {
  return !!(read(AMC6821_REG_CONF4) & AMC6821_CONF4_OVREN);
}

/**
 * @brief Get the TACH-FAST bit
 */
bool Tecsmith_AMC6821::getTachReadingFast() {
  return !!(read(AMC6821_REG_CONF4) & AMC6821_CONF4_TACH_FAST);
}

/**
 * @brief Get the PSPR bit
 */
bool Tecsmith_AMC6821::getPulseNumber() {
  return !!(read(AMC6821_REG_CONF4) & AMC6821_CONF4_PSPR);
}

// ----------

/**
 * @brief Set the START bit, calls `start` or `stop`
 */
bool Tecsmith_AMC6821::setStartMonitor(bool on) {
  if (on) {
    return start();
  } else {
    return stop();
  }
}

/**
 * @brief Set the INT-EN bit
 */
bool Tecsmith_AMC6821::setGlobalIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_FAN_INT_EN, on);
}

/**
 * @brief Set the FANIE bit
 */
bool Tecsmith_AMC6821::setRPMIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_FANIE, on);
}

/**
 * @brief Set the PWMINV bit
 */
bool Tecsmith_AMC6821::setPWMInvert(bool on) {
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_PWMINV, on);
}

/**
 * @brief Set the FAN-Fault-EN bit
 */
bool Tecsmith_AMC6821::setFanFaultPinEnable(bool on) {
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_FAN_FAULT_EN, on);
}

/**
 * @brief Set the fan control mode (FDRC0 & FDRC1), stoping monitoring if already started
 */
bool Tecsmith_AMC6821::setFanControlMode(amc6821_conf1_fdrc_t mode) {
  bool started = getStartMonitor();
  if (started) {
    setStartMonitor(false);
    delay(10);
  }
  bool ret = _setMode(mode);
  if (started) setStartMonitor(true);
  return ret;
}

/**
 * @brief Set the THERMOVIE bit
 */
bool Tecsmith_AMC6821::setThermIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF1, AMC6821_CONF1_THERMOVIE, on);
}

/**
 * @brief Set the PWM-EN bit
 */
bool Tecsmith_AMC6821::setPWMOutEnable(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_PWM_EN, on);
}

/**
 * @brief Set the TACH-MODE bit
 */
bool Tecsmith_AMC6821::setTachMode(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_TACH_MODE, on);
}

/**
 * @brief Set the TACH-EN bit
 */
bool Tecsmith_AMC6821::setTachEnable(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_TACH_EN, on);
}

/**
 * @brief Set the RTFIE bit
 */
bool Tecsmith_AMC6821::setRemoteFailureIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_RTFIE, on);
}

/**
 * @brief Set the LTOIE bit
 */
bool Tecsmith_AMC6821::setLTIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_LTOIE, on);
}

/**
 * @brief Set the RTOIE bit
 */
bool Tecsmith_AMC6821::setRTIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_RTOIE, on);
}

/**
 * @brief Set the PSVIE bit
 */
bool Tecsmith_AMC6821::setLPSVIntEnable(bool on) {
  return writeBit(AMC6821_REG_CONF2, AMC6821_CONF2_PSVIE, on);
}

/**
 * @brief Set the RST bit, can only set to true.
 */
bool Tecsmith_AMC6821::setReset(bool on) {
  if (!on) return false;
  return reset();
}

/**
 * @brief Set the THERM-FAN-EN bit
 */
bool Tecsmith_AMC6821::setThermFanEnable(bool on) {
  return writeBit(AMC6821_REG_CONF3, AMC6821_CONF3_THERM_FAN_EN, on);
}

/**
 * @brief Set the OVREN bit
 */
bool Tecsmith_AMC6821::setOVREnable(bool on) {
  return _writeBit_Conf4(AMC6821_REG_CONF4, AMC6821_CONF4_OVREN, on);
}

/**
 * @brief Set the TACH-FAST bit
 */
bool Tecsmith_AMC6821::setTachReadingFast(bool on) {
  return _writeBit_Conf4(AMC6821_REG_CONF4, AMC6821_CONF4_TACH_FAST, on);
}

/**
 * @brief Set the PSPR bit
 */
bool Tecsmith_AMC6821::setPulseNumber(bool on) {
  return _writeBit_Conf4(AMC6821_REG_CONF4, AMC6821_CONF4_PSPR, on);
}

// ---------- Status Registers ----------

/**
 * @brief Retrive the Status Register byte
 * @param no
 *        Register number, from 1 to 2
 */
uint8_t Tecsmith_AMC6821::getStatus(byte no) {
  return read(_statAddr(no));
}

/**
 * @brief Get the RPM-ALARM bit
 */
bool Tecsmith_AMC6821::getFanFast() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RPM_ALARM);
}

/**
 * @brief Get the FANS bit
 */
bool Tecsmith_AMC6821::getFanSlow() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_FANS);
}

/**
 * @brief Get the RTH bit
 */
bool Tecsmith_AMC6821::getRTHigh() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RTH);
}

/**
 * @brief Get the RTL bit
 */
bool Tecsmith_AMC6821::getRTLow() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RTL);
}

/**
 * @brief Get the R-THERM bit
 */
bool Tecsmith_AMC6821::getRTOverTherm() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_R_THERM);
}

/**
 * @brief Get the RTF bit
 */
bool Tecsmith_AMC6821::getRTFailure() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_RTF);
}

/**
 * @brief Get the LTH bit
 */
bool Tecsmith_AMC6821::getLTHigh() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_LTH);
}

/**
 * @brief Get the LTL bit
 */
bool Tecsmith_AMC6821::getLTLow() {
  return !!(read(AMC6821_REG_STAT1) & AMC6821_STAT1_LTL);
}

/**
 * @brief Get the RTC (Remote Over Critical) bit
 */
bool Tecsmith_AMC6821::getRTOverCritical() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_RTC);
}

/**
 * @brief Get the LTC (Local Over Critical) bit
 */
bool Tecsmith_AMC6821::getLTOverCritical() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_LTC);
}

/**
 * @brief Get the LPSV (Local Temp Below Therm) bit
 */
bool Tecsmith_AMC6821::getLTBelowTherm() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_LPSV);
}

/**
 * @brief Get the L-THERM (Local Temp Over Therm) bit
 */
bool Tecsmith_AMC6821::getLTOverTherm() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_L_THERM);
}

/**
 * @brief Get the THERM-IN (Therm Input) bit
 */
bool Tecsmith_AMC6821::getThermInput() {
  return !!(read(AMC6821_REG_STAT2) & AMC6821_STAT2_THERM_IN);
}

// ---------- Temperature Monitoring ----------

/**
 * @brief Get the local (on chip) temperature in degrees celsius
 */
int8_t Tecsmith_AMC6821::getLocalTemp() {
  return _toInt8( read(AMC6821_REG_LTEMP_HI) );
}

/**
 * @brief Get the remote temperature in degrees celsius
 */
int8_t Tecsmith_AMC6821::getRemoteTemp() {
  return _toInt8( read(AMC6821_REG_RTEMP_HI) );
}

/**
 * @brief Get the local (on chip) temperature in milli-degrees celsius
 *        (divide by 1000 to get float value, in 0.125°C increments)
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
 * @brief Get the remote temperature in milli-degrees celsius
 *        (divide by 1000 to get float value, in 0.125°C increments)
 */
int32_t Tecsmith_AMC6821::getRemoteMilliTemp() {
  int32_t res;
  res = (read(AMC6821_REG_TEMP_LBYTE) & 0x07);  // mask
  res = res * 125;
  return res + (getRemoteTemp() * 1000);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getLocalHighTempLimit() {
  return read(AMC6821_REG_LTEMP_LIMIT_MAX);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getLocalLowTempLimit() {
  return read(AMC6821_REG_LTEMP_LIMIT_MIN);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getLocalThermLimit() {
  return read(AMC6821_REG_LTHERM_LIMIT);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getRemoteHighTempLimit() {
  return read(AMC6821_REG_RTEMP_LIMIT_MAX);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getRemoteLowTempLimit() {
  return read(AMC6821_REG_RTEMP_LIMIT_MIN);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getRemoteThermLimit() {
  return read(AMC6821_REG_RTHERM_LIMIT);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getLocalCriticalTemp() {
  return read(AMC6821_REG_LTEMP_CRIT);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getPassiveCoolingTemp() {
  return read(AMC6821_REG_PSV_TEMP);
}

/**
 * @brief // TODO doc
 */
int8_t Tecsmith_AMC6821::getRemoteCriticalTemp() {
  return read(AMC6821_REG_RTEMP_CRIT);
}

// ---------- PWM Controler ----------

/**
 * @brief // TODO doc
 */
uint8_t Tecsmith_AMC6821::getFanCharacteristics() {
  return read(AMC6821_REG_FAN_CHARS);
}

/**
 * @brief // TODO doc
 */
uint8_t Tecsmith_AMC6821::getDutyCycleLowTemp() {
  return read(AMC6821_REG_DCY_LOW_TEMP);
}

/**
 * @brief Get the DCY (duty cycle), where 0x00 = 0% and 0xFF = 100%
 */
uint8_t Tecsmith_AMC6821::getDutyCycle() {
  return read(AMC6821_REG_DCY);
}

/**
 * @brief Get the DCY (duty cycle) in Percentage, where 0 = 0% and 100 = 100%
 */
int8_t Tecsmith_AMC6821::getDutyCycleP() {
  float f = (read(AMC6821_REG_DCY) / 255.0) * 100;
  return f;
}

/**
 * @brief // TODO doc
 */
uint8_t Tecsmith_AMC6821::getDutyCycleRamp() {
  return read(AMC6821_REG_DCY_RAMP);
}

/**
 * @brief // TODO doc
 */
uint8_t Tecsmith_AMC6821::getLocalTempFanControl() {
  return read(AMC6821_REG_LTEMP_FAN_CTRL);
}

/**
 * @brief // TODO doc
 */
uint8_t Tecsmith_AMC6821::getRemoteTempFanControl() {
  return read(AMC6821_REG_RTEMP_FAN_CTRL);
}

// ----------

/**
 * @brief Set the DCY (duty cycle), where 0x00 = 0% and 0xFF = 100%
 */
bool Tecsmith_AMC6821::setDutyCycle(uint8_t value) {
  return write(AMC6821_REG_DCY, value);
}

bool Tecsmith_AMC6821::setDutyCycleP(int8_t percentage) {
  if ((percentage < 0) || (percentage > 100)) return false;
  float f = (percentage / 100.0) * 255;
  return write(AMC6821_REG_DCY, f);
}


// ---------- TACH (RPM) Measurement ----------

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachData() {
  return read2(AMC6821_REG_TDATA_LOW, AMC6821_REG_TDATA_HI);
}

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachLowLimit() {
  return read2(AMC6821_REG_TACH_LLIMITL, AMC6821_REG_TACH_LLIMITH);
}

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachHighLimit() {
  return read2(AMC6821_REG_TACH_HLIMITL, AMC6821_REG_TACH_HLIMITH);
}

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachSetting() {
  return read2(AMC6821_REG_TACH_SETTINGL, AMC6821_REG_TACH_SETTINGH);
}

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachDataRPM() {
  return _toRPM( getTachData() );
}

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachLowLimitRPM() {
  return _toRPM( getTachLowLimit() );
}

/**
 * @brief // TODO doc
 */
uint16_t Tecsmith_AMC6821::getTachHighLimitRPM() {
  return _toRPM( getTachHighLimit() );
}

/**
 * @brief // TODO doc
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

/**
 * @brief // TODO doc
 */
float Tecsmith_AMC6821::toFahrenheit(float celsius) {
  return (celsius * 1.8) + 32;
}

/**
 * @brief // TODO doc
 */
float Tecsmith_AMC6821::toCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 0.5556;
}

/**
 * @brief Does all the hard work after begin
 */
bool Tecsmith_AMC6821::_init(amc6821_conf1_fdrc_t mode) {
  bool ret = reset();
  if (AMC6821_CONF1_FDRC_AUTO_REMOTE != mode)
    ret = _setMode(mode);
  return ret;
}

/**
 * @brief Set the operation mode flags in the Config register
 */
bool Tecsmith_AMC6821::_setMode(amc6821_conf1_fdrc_t mode) {
  uint8_t m;
  switch (mode) {
    case AMC6821_CONF1_FDRC_SOFTWARE_DCY: m = 0x00; break;
    case AMC6821_CONF1_FDRC_SOFTWARE_RPM: m = 0x01; break;
    case AMC6821_CONF1_FDRC_MAX_SPEED: m = 0x03; break;
    default: m = 0x02; break;  // AMC6821_CONF1_FDRC_AUTO_REMOTE
  }
  m = m << 5;
  return write(AMC6821_REG_CONF1, m, AMC6821_MASK_CONF1_FDRC);
}

/**
 * @brief Same as `writeBit()`, but always set's bit 0x80 as required by the spec.
 */
bool Tecsmith_AMC6821::_writeBit_Conf4(uint8_t addr, uint8_t mask, bool on) {
  uint8_t val = on ? mask : 0;
  val = val | _AMC6821_CONF4_MODE;
  return write(addr, val, mask | _AMC6821_CONF4_MODE);
}
