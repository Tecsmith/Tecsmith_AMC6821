/*!
 *  @file Tecsmith_AMC6821.h
 *
 * 	I2C Driver for the Tecsmith AMC6821 fan controll module.
 *
 *  This is a library is written to work with the AMC6821 Breakout, http://c1k.it/amc6
 *
 *	MIT license (@see: ../LICENSE.md)
 */

#ifndef _TECSMITH_AMC6821_H
#define _TECSMITH_AMC6821_H

#include "Arduino.h"
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#define AMC6821_I2CADDR_DEFAULT 0x18  ///< AMC6821 default i2c address


// *** following table from page 33 of the AMC6821 Spec Sheet, 2007 Revision
// Identification registers
#define AMC6821_REG_DEV_ID          0x3D
#define AMC6821_REG_COMP_ID         0x3E

// Configuration Registers
#define AMC6821_REG_CONF1           0x00
#define AMC6821_REG_CONF2           0x01
#define AMC6821_REG_CONF3           0x3F
#define AMC6821_REG_CONF4           0x04
#define AMC6821_REG_STAT1           0x02
#define AMC6821_REG_STAT2           0x03

// Temperature Monitoring
#define AMC6821_REG_TEMP_LBYTE      0x06  // see p. 45
#define AMC6821_REG_LTEMP_HI        0x0A
#define AMC6821_REG_RTEMP_HI        0x0B  // see p. 46
#define AMC6821_REG_LTEMP_LIMIT_MAX 0x14
#define AMC6821_REG_LTEMP_LIMIT_MIN 0x15
#define AMC6821_REG_LTHERM_LIMIT    0x16
#define AMC6821_REG_RTEMP_LIMIT_MAX 0x18
#define AMC6821_REG_RTEMP_LIMIT_MIN 0x19  // see p. 47
#define AMC6821_REG_RTHERM_LIMIT    0x1A
#define AMC6821_REG_LTEMP_CRIT      0x1B
#define AMC6821_REG_PSV_TEMP        0x1C
#define AMC6821_REG_RTEMP_CRIT      0x1D

// PWM Controler
#define AMC6821_REG_FAN_CHARS       0x20
#define AMC6821_REG_DCY_LOW_TEMP    0x21
#define AMC6821_REG_DCY             0x22
#define AMC6821_REG_DCY_RAMP        0x23
#define AMC6821_REG_LTEMP_FAN_CTRL  0x24
#define AMC6821_REG_RTEMP_FAN_CTRL  0x25

// TACH (RPM) Measurement
#define AMC6821_REG_TDATA_LOW       0x08
#define AMC6821_REG_TDATA_HI        0x09
#define AMC6821_REG_TACH_LLIMITL    0x10
#define AMC6821_REG_TACH_LLIMITH    0x11
#define AMC6821_REG_TACH_HLIMITL    0x12
#define AMC6821_REG_TACH_HLIMITH    0x13
#define AMC6821_REG_TACH_SETTINGL   0x1E
#define AMC6821_REG_TACH_SETTINGH   0x1F

#define AMC6821_FAN_RPM_NUMERATOR   (100000 * 60)  // see p.18, Equation 2

// Identification
#define AMC6821_DEVICE_ID  0x21
#define AMC6821_COMPANY_ID 0x49

// Device configuration and status registers (bits)
// Configuration register 1
#define AMC6821_CONF1_START        0x01
#define AMC6821_CONF1_FAN_INT_EN   0x02
#define AMC6821_CONF1_FANIE        0x04
#define AMC6821_CONF1_PWMINV       0x08
#define AMC6821_CONF1_FAN_FAULT_EN 0x10
#define AMC6821_CONF1_FDRC0        0x20
#define AMC6821_CONF1_FDRC1        0x40
#define AMC6821_CONF1_THERMOVIE    0x80

typedef enum {  // see p.36, Table 15
  AMC6821_CONF1_FDRC_SOFTWARE_DCY = 0x00,
  AMC6821_CONF1_FDRC_SOFTWARE_RPM = 0x20,
  AMC6821_CONF1_FDRC_AUTO_REMOTE  = 0x40,  // default
  AMC6821_CONF1_FDRC_MAX_SPEED    = 0x60,
} amc6821_conf1_fdrc_t;
#define AMC6821_MASK_CONF1_FDRC    0x60  // see AMC6821_CONF1_FDRC{x}

// Configuration register 2
#define AMC6821_CONF2_PWM_EN    0x01
#define AMC6821_CONF2_TACH_MODE 0x02
#define AMC6821_CONF2_TACH_EN   0x04
#define AMC6821_CONF2_RTFIE     0x08
#define AMC6821_CONF2_LTOIE     0x10
#define AMC6821_CONF2_RTOIE     0x20
#define AMC6821_CONF2_PSVIE     0x40
#define AMC6821_CONF2_RST       0x80

// Configuration register 3
#define AMC6821_CONF3_THERM_FAN_EN 0x80
#define AMC6821_MASK_CONF3_REV     0x0F

// Configuration register 4
#define AMC6821_CONF4_OVREN     0x10
#define AMC6821_CONF4_TACH_FAST 0x20
#define AMC6821_CONF4_PSPR      0x40
#define _AMC6821_CONF4_MODE     0x80

// Status register 1
#define AMC6821_STAT1_RPM_ALARM 0x01
#define AMC6821_STAT1_FANS      0x02
#define AMC6821_STAT1_RTH       0x04
#define AMC6821_STAT1_RTL       0x08
#define AMC6821_STAT1_R_THERM   0x10
#define AMC6821_STAT1_RTF       0x20
#define AMC6821_STAT1_LTH       0x40
#define AMC6821_STAT1_LTL       0x80

// Status register 2
#define AMC6821_STAT2_RTC      0x08
#define AMC6821_STAT2_LTC      0x10
#define AMC6821_STAT2_LPSV     0x20
#define AMC6821_STAT2_L_THERM  0x40
#define AMC6821_STAT2_THERM_IN 0x80

/*!
 *    @brief  Class that stores state and functions for
 *            interacting with the AMC6821 fan controller.
 */
class Tecsmith_AMC6821 {
  public:
    Tecsmith_AMC6821();
    ~Tecsmith_AMC6821();

    uint8_t read(uint8_t addr);
    uint16_t read2(uint8_t addrL, uint8_t addrH);

    bool write(uint8_t addr, uint8_t data, uint8_t mask = 0xFF);
    bool write2(uint8_t addrL, uint8_t addrH, uint16_t data);
    bool writeBit(uint8_t addr, uint8_t mask, bool on = true);

    bool begin(uint8_t i2c_addr = AMC6821_I2CADDR_DEFAULT,
               TwoWire *wire = &Wire,
               amc6821_conf1_fdrc_t mode = AMC6821_CONF1_FDRC_AUTO_REMOTE);
    bool begin(TwoWire *wire, amc6821_conf1_fdrc_t mode = AMC6821_CONF1_FDRC_AUTO_REMOTE);
    bool begin(amc6821_conf1_fdrc_t mode);

    bool reset();  // called by begin
    bool start();  // called by begin
    bool stop();

    // Identification Registers

    uint8_t getDeviceID();
    uint8_t getCompanyID();
    uint8_t getPartRevision();

    // Configuration Registers

    uint8_t getConfig(byte no = 1);

    bool getStartMonitor();
    bool getGlobalIntEnable();
    bool getRPMIntEnable();
    bool getPWMInvert();
    bool getFanFaultPinEnable();
    amc6821_conf1_fdrc_t getFanControlMode();
    bool getThermIntEnable();

    bool getPWMOutEnable();
    bool getTachMode();
    bool getTachEnable();
    bool getRemoteFailureIntEnable();
    bool getLTIntEnable();
    bool getRTIntEnable();
    bool getLPSVIntEnable();

    bool getTermFanEnable();

    bool getOVREnable();
    bool getTachReadingFast();
    bool getPulseNumber();

    bool setStartMonitor(bool on = true);
    bool setGlobalIntEnable(bool on = true);
    bool setRPMIntEnable(bool on = true);
    bool setPWMInvert(bool on = true);
    bool setFanFaultPinEnable(bool on = true);
    bool setFanControlMode(amc6821_conf1_fdrc_t mode);
    bool setThermIntEnable(bool on = true);

    bool setPWMOutEnable(bool on = true);
    bool setTachMode(bool on = true);
    bool setTachEnable(bool on = true);
    bool setRemoteFailureIntEnable(bool on = true);
    bool setLTIntEnable(bool on = true);
    bool setRTIntEnable(bool on = true);
    bool setLPSVIntEnable(bool on = true);
    bool setReset(bool on = true);

    bool setThermFanEnable(bool on = true);

    bool setOVREnable(bool on = true);
    bool setTachReadingFast(bool on = true);
    bool setPulseNumber(bool on = true);

    // Status Registers

    uint8_t getStatus(byte no = 1);

    bool getFanFast();
    bool getFanSlow();
    bool getRTHigh();
    bool getRTLow();
    bool getRTOverTherm();
    bool getRTFailure();
    bool getLTHigh();
    bool getLTLow();
    bool getRTOverCritical();
    bool getLTOverCritical();
    bool getLTBelowTherm();
    bool getLTOverTherm();
    bool getThermInput();

    // Temperature Monitoring

    int8_t getLocalTemp();
    int8_t getRemoteTemp();
    int32_t getLocalMilliTemp();  // returns 1*1000 of current temp
    int32_t getRemoteMilliTemp();  // returns 1*1000 of current temp

    int8_t getLocalHighTempLimit();
    int8_t getLocalLowTempLimit();
    int8_t getLocalThermLimit();
    int8_t getRemoteHighTempLimit();
    int8_t getRemoteLowTempLimit();
    int8_t getRemoteThermLimit();
    int8_t getLocalCriticalTemp();
    int8_t getPassiveCoolingTemp();
    int8_t getRemoteCriticalTemp();

    // bool setLocalHighTempLimit(int8_t value);
    // bool setLocalLowTempLimit(int8_t value);
    // bool setLocalThermLimit(int8_t value);
    // bool setRemoteHighTempLimit(int8_t value);
    // bool setRemoteLowTempLimit(int8_t value);
    // bool setRemoteThermLimit(int8_t value);
    // bool setLocalCriticalTemp(int8_t value);
    // bool setPassiveCoolingTemp(int8_t value);
    // bool setRemoteCriticalTemp(int8_t value);

    // PWM Controller

    uint8_t getFanCharacteristics();
    uint8_t getDutyCycleLowTemp();
    uint8_t getDutyCycle();
    int8_t getDutyCycleP();
    uint8_t getDutyCycleRamp();
    uint8_t getLocalTempFanControl();
    uint8_t getRemoteTempFanControl();

    // bool setFanCharacteristics(uint8_t value);
    // bool setDutyCycleLowTemp(uint8_t value);
    bool setDutyCycle(uint8_t value);
    bool setDutyCycleP(int8_t percentage);
    // bool setDutyCycleRamp(uint8_t value);
    // bool setLocalTempFanControl(uint8_t value);
    // bool setRemoteTempFanControl(uint8_t value);

    // TACH (RPM) Measurement

    /* Returns clock pulses (100MHz clock) counted during one fan revolution
     * to get RPM use:  `= (100000 * 60) / {result}`
     */
    uint16_t getTachData();
    uint16_t getTachLowLimit();
    uint16_t getTachHighLimit();
    uint16_t getTachSetting();

    uint16_t getTachDataRPM();
    uint16_t getTachLowLimitRPM();
    uint16_t getTachHighLimitRPM();
    uint16_t getTachSettingRPM();


    //// uint16_t perMinute(uint16_t value);
    //// uint16_t getTechDataRPM();
    //// uint16_t getTachLowLimitRPM();
    //// uint16_t getTachHighLimitRPM();
    //// uint16_t getTachSettingRPM();

    // bool setTachLowLimit(uint16_t value);
    // bool setTachLowLimitRPM(uint16_t value);
    // bool setTachHighLimit(uint16_t value);
    // bool setTachHighLimitRPM(uint16_t value);
    // bool setTachSetting(uint16_t value);
    // bool setTachSettingRPM(uint16_t value);

    static float toFahrenheit(float celsius);
    static float toCelsius(float fahrenheit);

  private:
    int8_t _toInt8(uint8_t x);
    uint16_t _toRPM(uint16_t x);

    uint8_t _confAddr(byte no);
    uint8_t _statAddr(byte no);

    bool _init(amc6821_conf1_fdrc_t mode = AMC6821_CONF1_FDRC_AUTO_REMOTE);
    bool _setMode(amc6821_conf1_fdrc_t mode);

    bool _writeBit_Conf4(uint8_t addr, uint8_t mask, bool on);

    Adafruit_I2CDevice *i2c_dev = NULL;  ///< Pointer to I2C bus interface
};

#endif
