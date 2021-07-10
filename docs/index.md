# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821) | Class that stores state and functions for interacting with the AMC6821 fan controller.

# class `Tecsmith_AMC6821` 

Class that stores state and functions for interacting with the AMC6821 fan controller.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726)`()` | Construct a new [Tecsmith_AMC6821::Tecsmith_AMC6821](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726) object.
`public  `[`~Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821_1a1904256c63506b85b5391b5e1d0376e9)`()` | Destroy the [Tecsmith_AMC6821::Tecsmith_AMC6821](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726) object.
`public uint8_t `[`read`](#class_tecsmith___a_m_c6821_1a1065eb8b7784e4f2132133497a10d4b7)`(uint8_t addr)` | Reads one byte.
`public uint16_t `[`read2`](#class_tecsmith___a_m_c6821_1acd0e2678852e6901dd24a8d42f3983e8)`(uint8_t addrL,uint8_t addrH)` | Reads two bytes.
`public bool `[`write`](#class_tecsmith___a_m_c6821_1a4c005b600345946f6304eff8571a1a26)`(uint8_t addr,uint8_t data,uint8_t mask)` | Writes one byte, preserving prior bits in optional mask.
`public bool `[`write2`](#class_tecsmith___a_m_c6821_1aca6b03d9ff0d30f182d84102f973e963)`(uint8_t addrL,uint8_t addrH,uint16_t data)` | // TODO
`public bool `[`writeBit`](#class_tecsmith___a_m_c6821_1a89bf6fd42109f1a0a7d272b7170f77a8)`(uint8_t addr,uint8_t mask,bool on)` | Writes bit on or off based on a mask.
`public bool `[`begin`](#class_tecsmith___a_m_c6821_1a933a201f931242acd2355fbd90a60df6)`(uint8_t i2c_addr,TwoWire * wire,amc6821_conf1_fdrc_t mode)` | Sets up the hardware and initializes I2C.
`public bool `[`begin`](#class_tecsmith___a_m_c6821_1ad79acf494b04ba745c30a0e9aa4308d8)`(TwoWire * wire,amc6821_conf1_fdrc_t mode)` | 
`public bool `[`begin`](#class_tecsmith___a_m_c6821_1a6abe414b87b7a52ec135dd45adef3fd0)`(amc6821_conf1_fdrc_t mode)` | 
`public bool `[`reset`](#class_tecsmith___a_m_c6821_1a8f4ac3380656f8a6a68caddd34c0ccab)`()` | Sends a reset command to the chip. Similar to `setReset`, but adds a 100 mil delay.
`public bool `[`start`](#class_tecsmith___a_m_c6821_1a9fa03a47ffa95f4b6a95a43c333e8fa9)`()` | Sends a start command to the chip.
`public bool `[`stop`](#class_tecsmith___a_m_c6821_1af04c1c473596f1338eb812ce22e14c27)`()` | Sends a stop command to the chip.
`public uint8_t `[`getDeviceID`](#class_tecsmith___a_m_c6821_1a06d0b99c178e3d1f6326b180600bd638)`()` | Get Device ID, should be 0x21.
`public uint8_t `[`getCompanyID`](#class_tecsmith___a_m_c6821_1a8cac8c856b122e00baa5e5e80466e0f4)`()` | Get Company ID, should be 0x49.
`public uint8_t `[`getPartRevision`](#class_tecsmith___a_m_c6821_1a7011b9f6263f416aa9e41e4ea789d67d)`()` | Get the chip revision number.
`public uint8_t `[`getConfig`](#class_tecsmith___a_m_c6821_1a975e6a6b4239885742ec2c0afb86c62e)`(byte no)` | Retrive the Configuration Register byte.
`public bool `[`getStartMonitor`](#class_tecsmith___a_m_c6821_1a4db57d335278bad1a6a7136eaac162f1)`()` | Get the START bit.
`public bool `[`getGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a4ec3cb3b620eda1f69025b976be3f745)`()` | Get the INT-EN bit.
`public bool `[`getRPMIntEnable`](#class_tecsmith___a_m_c6821_1a704df85dbc3fd69ff9c59bdfbaf92f18)`()` | Get the FANIE bit.
`public bool `[`getPWMInvert`](#class_tecsmith___a_m_c6821_1a9e5ffdcdf4f9149411b1e75938f22363)`()` | Get the PWMINV bit.
`public bool `[`getFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a42d5bd43fce219b3213eabcf18cd939a)`()` | Get the FAN-Fault-EN bit.
`public amc6821_conf1_fdrc_t `[`getFanControlMode`](#class_tecsmith___a_m_c6821_1a03ea5ddd36e336f3654793e56a065835)`()` | Get the Fan Control Mode enum (FDRC1 & FDRC0 bits)
`public bool `[`getThermIntEnable`](#class_tecsmith___a_m_c6821_1a42d5b193a9e28fb3624a9994550cf3bd)`()` | Get the THERMOVIE bit.
`public bool `[`getPWMOutEnable`](#class_tecsmith___a_m_c6821_1af8e6333e67570550e53904ed9adc8408)`()` | Get the PWM-EN bit.
`public bool `[`getTachMode`](#class_tecsmith___a_m_c6821_1ab5c9a5a9d121aadf0cbe42154f1bb705)`()` | Get the TACH-MODE bit.
`public bool `[`getTachEnable`](#class_tecsmith___a_m_c6821_1a338bd6df8670552bea9da86026d9c27c)`()` | Get the TACH-EN bit.
`public bool `[`getRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1abd6b7acba7405eec7bb367341a956e30)`()` | Get the RTFIE bit.
`public bool `[`getLTIntEnable`](#class_tecsmith___a_m_c6821_1abc09649eaa5adaec0d9703a9e62d5d04)`()` | Get the LTOIE bit.
`public bool `[`getRTIntEnable`](#class_tecsmith___a_m_c6821_1a685a899c04f3ee09e3035bc1fda322fb)`()` | Get the RTOIE bit.
`public bool `[`getLPSVIntEnable`](#class_tecsmith___a_m_c6821_1aedae174724a0e0b4ec44d6392953568a)`()` | Get the PSVIE bit.
`public bool `[`getTermFanEnable`](#class_tecsmith___a_m_c6821_1aa4629fbdcad09192ec2e8814d9fa9801)`()` | Get the THERM-FAN-EN bit.
`public bool `[`getOVREnable`](#class_tecsmith___a_m_c6821_1aa492f48a51e40d3c771ac4f98aff6cc2)`()` | Get the OVREN bit.
`public bool `[`getTachReadingFast`](#class_tecsmith___a_m_c6821_1af007d8510cead3adbfa7b205c6d79599)`()` | Get the TACH-FAST bit.
`public bool `[`getPulseNumber`](#class_tecsmith___a_m_c6821_1a61a9754bbb52c3a6a46687cee36c06ee)`()` | Get the PSPR bit.
`public bool `[`setStartMonitor`](#class_tecsmith___a_m_c6821_1ac420bc0ee9bb0f514c3736466d19b227)`(bool on)` | Set the START bit, calls `start` or `stop`
`public bool `[`setGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a6ecee7342ca22543b429a288405dcfeb)`(bool on)` | Set the INT-EN bit.
`public bool `[`setRPMIntEnable`](#class_tecsmith___a_m_c6821_1a01fa700f7a04005af70f284d070dc914)`(bool on)` | Set the FANIE bit.
`public bool `[`setPWMInvert`](#class_tecsmith___a_m_c6821_1a2e4db48877028a788f84e2ee38d334ad)`(bool on)` | Set the PWMINV bit.
`public bool `[`setFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a9d23940b744414f9e1750b06416f3104)`(bool on)` | Set the FAN-Fault-EN bit.
`public bool `[`setFanControlMode`](#class_tecsmith___a_m_c6821_1a374de01255a7adbe640ca093a19d4b0e)`(amc6821_conf1_fdrc_t mode)` | Set the fan control mode (FDRC0 & FDRC1), stoping monitoring if already started.
`public bool `[`setThermIntEnable`](#class_tecsmith___a_m_c6821_1a37ebeed4a406000386588a9dd5d554f3)`(bool on)` | Set the THERMOVIE bit.
`public bool `[`setPWMOutEnable`](#class_tecsmith___a_m_c6821_1a9212bdbfd125bb3342b714f63422f059)`(bool on)` | Set the PWM-EN bit.
`public bool `[`setTachMode`](#class_tecsmith___a_m_c6821_1a6ef32e9fa76ac14ea8ff5bdd1238ff2e)`(bool on)` | Set the TACH-MODE bit.
`public bool `[`setTachEnable`](#class_tecsmith___a_m_c6821_1ad31c17f04ca79a872025b5c81ed4386c)`(bool on)` | Set the TACH-EN bit.
`public bool `[`setRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1ab9f606abc434bc86e0c36543c6d5c1d4)`(bool on)` | Set the RTFIE bit.
`public bool `[`setLTIntEnable`](#class_tecsmith___a_m_c6821_1a1e8028e6d2ca6877561d3f84ce8fcb11)`(bool on)` | Set the LTOIE bit.
`public bool `[`setRTIntEnable`](#class_tecsmith___a_m_c6821_1aaaae58f60e31acb2a68886a6f7f22de3)`(bool on)` | Set the RTOIE bit.
`public bool `[`setLPSVIntEnable`](#class_tecsmith___a_m_c6821_1ab01d5fe6dabbb1ea3d5793134a2b284f)`(bool on)` | Set the PSVIE bit.
`public bool `[`setReset`](#class_tecsmith___a_m_c6821_1a6d255abd8b81afd71040ce9b40aa4c18)`(bool on)` | Set the RST bit, can only set to true.
`public bool `[`setThermFanEnable`](#class_tecsmith___a_m_c6821_1af20afd489544f887dece422e960f7f69)`(bool on)` | Set the THERM-FAN-EN bit.
`public bool `[`setOVREnable`](#class_tecsmith___a_m_c6821_1a15ac80d9c13df6af30ec784f68a040bc)`(bool on)` | Set the OVREN bit.
`public bool `[`setTachReadingFast`](#class_tecsmith___a_m_c6821_1a8c99df85e5d581cd83ce784ef6dc0d88)`(bool on)` | Set the TACH-FAST bit.
`public bool `[`setPulseNumber`](#class_tecsmith___a_m_c6821_1a0bce22939aae76e134c6ee8038b5e48b)`(bool on)` | Set the PSPR bit.
`public uint8_t `[`getStatus`](#class_tecsmith___a_m_c6821_1af838168e598d2a0214dc2c52d9dd8ca4)`(byte no)` | Retrive the Status Register byte.
`public bool `[`getFanFast`](#class_tecsmith___a_m_c6821_1adce845795961541bd9b9fbc6c627b22b)`()` | Get the RPM-ALARM bit.
`public bool `[`getFanSlow`](#class_tecsmith___a_m_c6821_1aa1dd63f6c4d50cf9c605022f2d4998e7)`()` | Get the FANS bit.
`public bool `[`getRTHigh`](#class_tecsmith___a_m_c6821_1a273ab7a903bf37b9cbfe4758f3614dca)`()` | Get the RTH bit.
`public bool `[`getRTLow`](#class_tecsmith___a_m_c6821_1a1973cc6ce0250af32f0acbcdaf389ef8)`()` | Get the RTL bit.
`public bool `[`getRTOverTherm`](#class_tecsmith___a_m_c6821_1a4a794e4cfe783083a05a4a97f1e46876)`()` | Get the R-THERM bit.
`public bool `[`getRTFailure`](#class_tecsmith___a_m_c6821_1a2f6287d321ea35ca7b6fc4baba2e8ce1)`()` | Get the RTF bit.
`public bool `[`getLTHigh`](#class_tecsmith___a_m_c6821_1a71c0f9eb8a8324af43ae3a8ad0721fce)`()` | Get the LTH bit.
`public bool `[`getLTLow`](#class_tecsmith___a_m_c6821_1a17d5100d26e2f7c6f8f24ad74dac333f)`()` | Get the LTL bit.
`public bool `[`getRTOverCritical`](#class_tecsmith___a_m_c6821_1a6b019dbff62e0ccff3619ded4103029e)`()` | Get the RTC (Remote Over Critical) bit.
`public bool `[`getLTOverCritical`](#class_tecsmith___a_m_c6821_1ab838c76e6bb967012b6ece973c6e060c)`()` | Get the LTC (Local Over Critical) bit.
`public bool `[`getLTBelowTherm`](#class_tecsmith___a_m_c6821_1ae8da7da6e1b0b1792f353e3af85de4ef)`()` | Get the LPSV (Local Temp Below Therm) bit.
`public bool `[`getLTOverTherm`](#class_tecsmith___a_m_c6821_1af173502594c0a90d94c1ac8ede2ea599)`()` | Get the L-THERM (Local Temp Over Therm) bit.
`public bool `[`getThermInput`](#class_tecsmith___a_m_c6821_1af449bc004d4c2b4d2c579132499cfc29)`()` | Get the THERM-IN (Therm Input) bit.
`public int8_t `[`getLocalTemp`](#class_tecsmith___a_m_c6821_1acdc8554e62e645df61e4303ce78ec1ee)`()` | Get the local (on chip) temperature in degrees celsius.
`public int8_t `[`getRemoteTemp`](#class_tecsmith___a_m_c6821_1a4b7fe610c8a5718c625ac13474e7ec9f)`()` | Get the remote temperature in degrees celsius.
`public int32_t `[`getLocalMilliTemp`](#class_tecsmith___a_m_c6821_1a4de9164804011815c15f0e65e0b8f033)`()` | Get the local (on chip) temperature in milli-degrees celsius (divide by 1000 to get float value, in 0.125°C increments)
`public int32_t `[`getRemoteMilliTemp`](#class_tecsmith___a_m_c6821_1a0d767540121c93130e2452f2f82450eb)`()` | Get the remote temperature in milli-degrees celsius (divide by 1000 to get float value, in 0.125°C increments)
`public int8_t `[`getLocalHighTempLimit`](#class_tecsmith___a_m_c6821_1a03c9a8bfd85a3d895873ce644ab9705a)`()` | // TODO doc
`public int8_t `[`getLocalLowTempLimit`](#class_tecsmith___a_m_c6821_1a4665d6045821c703c0ead141cc9f024a)`()` | // TODO doc
`public int8_t `[`getLocalThermLimit`](#class_tecsmith___a_m_c6821_1a9705d7ee363a901ab89552fc4fb26e7e)`()` | // TODO doc
`public int8_t `[`getRemoteHighTempLimit`](#class_tecsmith___a_m_c6821_1ae94939cc6daa0a6ec8b50952785d5810)`()` | // TODO doc
`public int8_t `[`getRemoteLowTempLimit`](#class_tecsmith___a_m_c6821_1a2c7394e26dd1cb496527046b841083ce)`()` | // TODO doc
`public int8_t `[`getRemoteThermLimit`](#class_tecsmith___a_m_c6821_1ae00baa1a2307d7c6c55d09a8a415d70b)`()` | // TODO doc
`public int8_t `[`getLocalCriticalTemp`](#class_tecsmith___a_m_c6821_1ad0518343273070d5e90675a2468672c4)`()` | // TODO doc
`public int8_t `[`getPassiveCoolingTemp`](#class_tecsmith___a_m_c6821_1a07ee0aa9d8b8378b55f7e4637f3a6201)`()` | // TODO doc
`public int8_t `[`getRemoteCriticalTemp`](#class_tecsmith___a_m_c6821_1a56d95cceffecbc5d51205841a4d54284)`()` | // TODO doc
`public uint8_t `[`getFanCharacteristics`](#class_tecsmith___a_m_c6821_1a7fed6e2ca8932dd0fadc910c42151df4)`()` | // TODO doc
`public uint8_t `[`getDutyCycleLowTemp`](#class_tecsmith___a_m_c6821_1a037c112093c9f3d67742b3735b06c8bf)`()` | // TODO doc
`public uint8_t `[`getDutyCycle`](#class_tecsmith___a_m_c6821_1a36c7a1162a0244ad6b4a4912e723ce14)`()` | Get the DCY (duty cycle), where 0x00 = 0% and 0xFF = 100%.
`public int8_t `[`getDutyCycleP`](#class_tecsmith___a_m_c6821_1a71649bf36ac75853286feeefb70b3339)`()` | Get the DCY (duty cycle) in Percentage, where 0 = 0% and 100 = 100%.
`public uint8_t `[`getDutyCycleRamp`](#class_tecsmith___a_m_c6821_1a6a05f6d20a3f38b2d01e3ad2263ca58d)`()` | // TODO doc
`public uint8_t `[`getLocalTempFanControl`](#class_tecsmith___a_m_c6821_1a5eb68ac6477ea5fef04762adc548b0ef)`()` | // TODO doc
`public uint8_t `[`getRemoteTempFanControl`](#class_tecsmith___a_m_c6821_1a7efa03021ee65a1072851edf49959c46)`()` | // TODO doc
`public bool `[`setDutyCycle`](#class_tecsmith___a_m_c6821_1a32cd57a4c5d0c88eb23942b979b5091f)`(uint8_t value)` | Set the DCY (duty cycle), where 0x00 = 0% and 0xFF = 100%.
`public bool `[`setDutyCycleP`](#class_tecsmith___a_m_c6821_1a325e6c16a1f0c1a0df1f26515a3bf6f5)`(int8_t percentage)` | 
`public uint16_t `[`getTachData`](#class_tecsmith___a_m_c6821_1ac3636e82a5172f1424088e9fffc1f4ac)`()` | // TODO doc
`public uint16_t `[`getTachLowLimit`](#class_tecsmith___a_m_c6821_1a3375d4ed47bee34d10d1f6b4e8e902d3)`()` | // TODO doc
`public uint16_t `[`getTachHighLimit`](#class_tecsmith___a_m_c6821_1a91b37c73fc9589d5f06703e3e6612887)`()` | // TODO doc
`public uint16_t `[`getTachSetting`](#class_tecsmith___a_m_c6821_1a3838e483f470f75ac81e1907e7bd21dd)`()` | // TODO doc
`public uint16_t `[`getTachDataRPM`](#class_tecsmith___a_m_c6821_1a762a7e9a0689064875310ab4d30e4c9e)`()` | // TODO doc
`public uint16_t `[`getTachLowLimitRPM`](#class_tecsmith___a_m_c6821_1a7d2c980b3d5de1365682157e1f17ac17)`()` | // TODO doc
`public uint16_t `[`getTachHighLimitRPM`](#class_tecsmith___a_m_c6821_1a23b93c9dcd6f8a234717c15eb1271b80)`()` | // TODO doc
`public uint16_t `[`getTachSettingRPM`](#class_tecsmith___a_m_c6821_1a6158d06943555f89dd04223b36276224)`()` | // TODO doc

## Members

#### `public  `[`Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726)`()` 

Construct a new [Tecsmith_AMC6821::Tecsmith_AMC6821](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726) object.

#### `public  `[`~Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821_1a1904256c63506b85b5391b5e1d0376e9)`()` 

Destroy the [Tecsmith_AMC6821::Tecsmith_AMC6821](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726) object.

#### `public uint8_t `[`read`](#class_tecsmith___a_m_c6821_1a1065eb8b7784e4f2132133497a10d4b7)`(uint8_t addr)` 

Reads one byte.

#### `public uint16_t `[`read2`](#class_tecsmith___a_m_c6821_1acd0e2678852e6901dd24a8d42f3983e8)`(uint8_t addrL,uint8_t addrH)` 

Reads two bytes.

**Note:** The low byte should be read first. This method causes the high byte to be frozen until both the high and low byte registers have been read from, preventing erroneous TACH readings.

#### `public bool `[`write`](#class_tecsmith___a_m_c6821_1a4c005b600345946f6304eff8571a1a26)`(uint8_t addr,uint8_t data,uint8_t mask)` 

Writes one byte, preserving prior bits in optional mask.

#### `public bool `[`write2`](#class_tecsmith___a_m_c6821_1aca6b03d9ff0d30f182d84102f973e963)`(uint8_t addrL,uint8_t addrH,uint16_t data)` 

// TODO

#### `public bool `[`writeBit`](#class_tecsmith___a_m_c6821_1a89bf6fd42109f1a0a7d272b7170f77a8)`(uint8_t addr,uint8_t mask,bool on)` 

Writes bit on or off based on a mask.

#### `public bool `[`begin`](#class_tecsmith___a_m_c6821_1a933a201f931242acd2355fbd90a60df6)`(uint8_t i2c_addr,TwoWire * wire,amc6821_conf1_fdrc_t mode)` 

Sets up the hardware and initializes I2C.

#### Parameters
* `i2c_address` The I2C address to be used. 

* `wire` The Wire object to be used for I2C connections. 

#### Returns
True if initialization was successful, otherwise false.

#### `public bool `[`begin`](#class_tecsmith___a_m_c6821_1ad79acf494b04ba745c30a0e9aa4308d8)`(TwoWire * wire,amc6821_conf1_fdrc_t mode)` 

#### `public bool `[`begin`](#class_tecsmith___a_m_c6821_1a6abe414b87b7a52ec135dd45adef3fd0)`(amc6821_conf1_fdrc_t mode)` 

#### `public bool `[`reset`](#class_tecsmith___a_m_c6821_1a8f4ac3380656f8a6a68caddd34c0ccab)`()` 

Sends a reset command to the chip. Similar to `setReset`, but adds a 100 mil delay.

#### `public bool `[`start`](#class_tecsmith___a_m_c6821_1a9fa03a47ffa95f4b6a95a43c333e8fa9)`()` 

Sends a start command to the chip.

#### `public bool `[`stop`](#class_tecsmith___a_m_c6821_1af04c1c473596f1338eb812ce22e14c27)`()` 

Sends a stop command to the chip.

#### `public uint8_t `[`getDeviceID`](#class_tecsmith___a_m_c6821_1a06d0b99c178e3d1f6326b180600bd638)`()` 

Get Device ID, should be 0x21.

#### `public uint8_t `[`getCompanyID`](#class_tecsmith___a_m_c6821_1a8cac8c856b122e00baa5e5e80466e0f4)`()` 

Get Company ID, should be 0x49.

#### `public uint8_t `[`getPartRevision`](#class_tecsmith___a_m_c6821_1a7011b9f6263f416aa9e41e4ea789d67d)`()` 

Get the chip revision number.

#### `public uint8_t `[`getConfig`](#class_tecsmith___a_m_c6821_1a975e6a6b4239885742ec2c0afb86c62e)`(byte no)` 

Retrive the Configuration Register byte.

#### Parameters
* `no` Register number, from 1 to 4

#### `public bool `[`getStartMonitor`](#class_tecsmith___a_m_c6821_1a4db57d335278bad1a6a7136eaac162f1)`()` 

Get the START bit.

#### `public bool `[`getGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a4ec3cb3b620eda1f69025b976be3f745)`()` 

Get the INT-EN bit.

#### `public bool `[`getRPMIntEnable`](#class_tecsmith___a_m_c6821_1a704df85dbc3fd69ff9c59bdfbaf92f18)`()` 

Get the FANIE bit.

#### `public bool `[`getPWMInvert`](#class_tecsmith___a_m_c6821_1a9e5ffdcdf4f9149411b1e75938f22363)`()` 

Get the PWMINV bit.

#### `public bool `[`getFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a42d5bd43fce219b3213eabcf18cd939a)`()` 

Get the FAN-Fault-EN bit.

#### `public amc6821_conf1_fdrc_t `[`getFanControlMode`](#class_tecsmith___a_m_c6821_1a03ea5ddd36e336f3654793e56a065835)`()` 

Get the Fan Control Mode enum (FDRC1 & FDRC0 bits)

#### `public bool `[`getThermIntEnable`](#class_tecsmith___a_m_c6821_1a42d5b193a9e28fb3624a9994550cf3bd)`()` 

Get the THERMOVIE bit.

#### `public bool `[`getPWMOutEnable`](#class_tecsmith___a_m_c6821_1af8e6333e67570550e53904ed9adc8408)`()` 

Get the PWM-EN bit.

#### `public bool `[`getTachMode`](#class_tecsmith___a_m_c6821_1ab5c9a5a9d121aadf0cbe42154f1bb705)`()` 

Get the TACH-MODE bit.

#### `public bool `[`getTachEnable`](#class_tecsmith___a_m_c6821_1a338bd6df8670552bea9da86026d9c27c)`()` 

Get the TACH-EN bit.

#### `public bool `[`getRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1abd6b7acba7405eec7bb367341a956e30)`()` 

Get the RTFIE bit.

#### `public bool `[`getLTIntEnable`](#class_tecsmith___a_m_c6821_1abc09649eaa5adaec0d9703a9e62d5d04)`()` 

Get the LTOIE bit.

#### `public bool `[`getRTIntEnable`](#class_tecsmith___a_m_c6821_1a685a899c04f3ee09e3035bc1fda322fb)`()` 

Get the RTOIE bit.

#### `public bool `[`getLPSVIntEnable`](#class_tecsmith___a_m_c6821_1aedae174724a0e0b4ec44d6392953568a)`()` 

Get the PSVIE bit.

#### `public bool `[`getTermFanEnable`](#class_tecsmith___a_m_c6821_1aa4629fbdcad09192ec2e8814d9fa9801)`()` 

Get the THERM-FAN-EN bit.

#### `public bool `[`getOVREnable`](#class_tecsmith___a_m_c6821_1aa492f48a51e40d3c771ac4f98aff6cc2)`()` 

Get the OVREN bit.

#### `public bool `[`getTachReadingFast`](#class_tecsmith___a_m_c6821_1af007d8510cead3adbfa7b205c6d79599)`()` 

Get the TACH-FAST bit.

#### `public bool `[`getPulseNumber`](#class_tecsmith___a_m_c6821_1a61a9754bbb52c3a6a46687cee36c06ee)`()` 

Get the PSPR bit.

#### `public bool `[`setStartMonitor`](#class_tecsmith___a_m_c6821_1ac420bc0ee9bb0f514c3736466d19b227)`(bool on)` 

Set the START bit, calls `start` or `stop`

#### `public bool `[`setGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a6ecee7342ca22543b429a288405dcfeb)`(bool on)` 

Set the INT-EN bit.

#### `public bool `[`setRPMIntEnable`](#class_tecsmith___a_m_c6821_1a01fa700f7a04005af70f284d070dc914)`(bool on)` 

Set the FANIE bit.

#### `public bool `[`setPWMInvert`](#class_tecsmith___a_m_c6821_1a2e4db48877028a788f84e2ee38d334ad)`(bool on)` 

Set the PWMINV bit.

#### `public bool `[`setFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a9d23940b744414f9e1750b06416f3104)`(bool on)` 

Set the FAN-Fault-EN bit.

#### `public bool `[`setFanControlMode`](#class_tecsmith___a_m_c6821_1a374de01255a7adbe640ca093a19d4b0e)`(amc6821_conf1_fdrc_t mode)` 

Set the fan control mode (FDRC0 & FDRC1), stoping monitoring if already started.

#### `public bool `[`setThermIntEnable`](#class_tecsmith___a_m_c6821_1a37ebeed4a406000386588a9dd5d554f3)`(bool on)` 

Set the THERMOVIE bit.

#### `public bool `[`setPWMOutEnable`](#class_tecsmith___a_m_c6821_1a9212bdbfd125bb3342b714f63422f059)`(bool on)` 

Set the PWM-EN bit.

#### `public bool `[`setTachMode`](#class_tecsmith___a_m_c6821_1a6ef32e9fa76ac14ea8ff5bdd1238ff2e)`(bool on)` 

Set the TACH-MODE bit.

#### `public bool `[`setTachEnable`](#class_tecsmith___a_m_c6821_1ad31c17f04ca79a872025b5c81ed4386c)`(bool on)` 

Set the TACH-EN bit.

#### `public bool `[`setRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1ab9f606abc434bc86e0c36543c6d5c1d4)`(bool on)` 

Set the RTFIE bit.

#### `public bool `[`setLTIntEnable`](#class_tecsmith___a_m_c6821_1a1e8028e6d2ca6877561d3f84ce8fcb11)`(bool on)` 

Set the LTOIE bit.

#### `public bool `[`setRTIntEnable`](#class_tecsmith___a_m_c6821_1aaaae58f60e31acb2a68886a6f7f22de3)`(bool on)` 

Set the RTOIE bit.

#### `public bool `[`setLPSVIntEnable`](#class_tecsmith___a_m_c6821_1ab01d5fe6dabbb1ea3d5793134a2b284f)`(bool on)` 

Set the PSVIE bit.

#### `public bool `[`setReset`](#class_tecsmith___a_m_c6821_1a6d255abd8b81afd71040ce9b40aa4c18)`(bool on)` 

Set the RST bit, can only set to true.

#### `public bool `[`setThermFanEnable`](#class_tecsmith___a_m_c6821_1af20afd489544f887dece422e960f7f69)`(bool on)` 

Set the THERM-FAN-EN bit.

#### `public bool `[`setOVREnable`](#class_tecsmith___a_m_c6821_1a15ac80d9c13df6af30ec784f68a040bc)`(bool on)` 

Set the OVREN bit.

#### `public bool `[`setTachReadingFast`](#class_tecsmith___a_m_c6821_1a8c99df85e5d581cd83ce784ef6dc0d88)`(bool on)` 

Set the TACH-FAST bit.

#### `public bool `[`setPulseNumber`](#class_tecsmith___a_m_c6821_1a0bce22939aae76e134c6ee8038b5e48b)`(bool on)` 

Set the PSPR bit.

#### `public uint8_t `[`getStatus`](#class_tecsmith___a_m_c6821_1af838168e598d2a0214dc2c52d9dd8ca4)`(byte no)` 

Retrive the Status Register byte.

#### Parameters
* `no` Register number, from 1 to 2

#### `public bool `[`getFanFast`](#class_tecsmith___a_m_c6821_1adce845795961541bd9b9fbc6c627b22b)`()` 

Get the RPM-ALARM bit.

#### `public bool `[`getFanSlow`](#class_tecsmith___a_m_c6821_1aa1dd63f6c4d50cf9c605022f2d4998e7)`()` 

Get the FANS bit.

#### `public bool `[`getRTHigh`](#class_tecsmith___a_m_c6821_1a273ab7a903bf37b9cbfe4758f3614dca)`()` 

Get the RTH bit.

#### `public bool `[`getRTLow`](#class_tecsmith___a_m_c6821_1a1973cc6ce0250af32f0acbcdaf389ef8)`()` 

Get the RTL bit.

#### `public bool `[`getRTOverTherm`](#class_tecsmith___a_m_c6821_1a4a794e4cfe783083a05a4a97f1e46876)`()` 

Get the R-THERM bit.

#### `public bool `[`getRTFailure`](#class_tecsmith___a_m_c6821_1a2f6287d321ea35ca7b6fc4baba2e8ce1)`()` 

Get the RTF bit.

#### `public bool `[`getLTHigh`](#class_tecsmith___a_m_c6821_1a71c0f9eb8a8324af43ae3a8ad0721fce)`()` 

Get the LTH bit.

#### `public bool `[`getLTLow`](#class_tecsmith___a_m_c6821_1a17d5100d26e2f7c6f8f24ad74dac333f)`()` 

Get the LTL bit.

#### `public bool `[`getRTOverCritical`](#class_tecsmith___a_m_c6821_1a6b019dbff62e0ccff3619ded4103029e)`()` 

Get the RTC (Remote Over Critical) bit.

#### `public bool `[`getLTOverCritical`](#class_tecsmith___a_m_c6821_1ab838c76e6bb967012b6ece973c6e060c)`()` 

Get the LTC (Local Over Critical) bit.

#### `public bool `[`getLTBelowTherm`](#class_tecsmith___a_m_c6821_1ae8da7da6e1b0b1792f353e3af85de4ef)`()` 

Get the LPSV (Local Temp Below Therm) bit.

#### `public bool `[`getLTOverTherm`](#class_tecsmith___a_m_c6821_1af173502594c0a90d94c1ac8ede2ea599)`()` 

Get the L-THERM (Local Temp Over Therm) bit.

#### `public bool `[`getThermInput`](#class_tecsmith___a_m_c6821_1af449bc004d4c2b4d2c579132499cfc29)`()` 

Get the THERM-IN (Therm Input) bit.

#### `public int8_t `[`getLocalTemp`](#class_tecsmith___a_m_c6821_1acdc8554e62e645df61e4303ce78ec1ee)`()` 

Get the local (on chip) temperature in degrees celsius.

#### `public int8_t `[`getRemoteTemp`](#class_tecsmith___a_m_c6821_1a4b7fe610c8a5718c625ac13474e7ec9f)`()` 

Get the remote temperature in degrees celsius.

#### `public int32_t `[`getLocalMilliTemp`](#class_tecsmith___a_m_c6821_1a4de9164804011815c15f0e65e0b8f033)`()` 

Get the local (on chip) temperature in milli-degrees celsius (divide by 1000 to get float value, in 0.125°C increments)

#### `public int32_t `[`getRemoteMilliTemp`](#class_tecsmith___a_m_c6821_1a0d767540121c93130e2452f2f82450eb)`()` 

Get the remote temperature in milli-degrees celsius (divide by 1000 to get float value, in 0.125°C increments)

#### `public int8_t `[`getLocalHighTempLimit`](#class_tecsmith___a_m_c6821_1a03c9a8bfd85a3d895873ce644ab9705a)`()` 

// TODO doc

#### `public int8_t `[`getLocalLowTempLimit`](#class_tecsmith___a_m_c6821_1a4665d6045821c703c0ead141cc9f024a)`()` 

// TODO doc

#### `public int8_t `[`getLocalThermLimit`](#class_tecsmith___a_m_c6821_1a9705d7ee363a901ab89552fc4fb26e7e)`()` 

// TODO doc

#### `public int8_t `[`getRemoteHighTempLimit`](#class_tecsmith___a_m_c6821_1ae94939cc6daa0a6ec8b50952785d5810)`()` 

// TODO doc

#### `public int8_t `[`getRemoteLowTempLimit`](#class_tecsmith___a_m_c6821_1a2c7394e26dd1cb496527046b841083ce)`()` 

// TODO doc

#### `public int8_t `[`getRemoteThermLimit`](#class_tecsmith___a_m_c6821_1ae00baa1a2307d7c6c55d09a8a415d70b)`()` 

// TODO doc

#### `public int8_t `[`getLocalCriticalTemp`](#class_tecsmith___a_m_c6821_1ad0518343273070d5e90675a2468672c4)`()` 

// TODO doc

#### `public int8_t `[`getPassiveCoolingTemp`](#class_tecsmith___a_m_c6821_1a07ee0aa9d8b8378b55f7e4637f3a6201)`()` 

// TODO doc

#### `public int8_t `[`getRemoteCriticalTemp`](#class_tecsmith___a_m_c6821_1a56d95cceffecbc5d51205841a4d54284)`()` 

// TODO doc

#### `public uint8_t `[`getFanCharacteristics`](#class_tecsmith___a_m_c6821_1a7fed6e2ca8932dd0fadc910c42151df4)`()` 

// TODO doc

#### `public uint8_t `[`getDutyCycleLowTemp`](#class_tecsmith___a_m_c6821_1a037c112093c9f3d67742b3735b06c8bf)`()` 

// TODO doc

#### `public uint8_t `[`getDutyCycle`](#class_tecsmith___a_m_c6821_1a36c7a1162a0244ad6b4a4912e723ce14)`()` 

Get the DCY (duty cycle), where 0x00 = 0% and 0xFF = 100%.

#### `public int8_t `[`getDutyCycleP`](#class_tecsmith___a_m_c6821_1a71649bf36ac75853286feeefb70b3339)`()` 

Get the DCY (duty cycle) in Percentage, where 0 = 0% and 100 = 100%.

#### `public uint8_t `[`getDutyCycleRamp`](#class_tecsmith___a_m_c6821_1a6a05f6d20a3f38b2d01e3ad2263ca58d)`()` 

// TODO doc

#### `public uint8_t `[`getLocalTempFanControl`](#class_tecsmith___a_m_c6821_1a5eb68ac6477ea5fef04762adc548b0ef)`()` 

// TODO doc

#### `public uint8_t `[`getRemoteTempFanControl`](#class_tecsmith___a_m_c6821_1a7efa03021ee65a1072851edf49959c46)`()` 

// TODO doc

#### `public bool `[`setDutyCycle`](#class_tecsmith___a_m_c6821_1a32cd57a4c5d0c88eb23942b979b5091f)`(uint8_t value)` 

Set the DCY (duty cycle), where 0x00 = 0% and 0xFF = 100%.

#### `public bool `[`setDutyCycleP`](#class_tecsmith___a_m_c6821_1a325e6c16a1f0c1a0df1f26515a3bf6f5)`(int8_t percentage)` 

#### `public uint16_t `[`getTachData`](#class_tecsmith___a_m_c6821_1ac3636e82a5172f1424088e9fffc1f4ac)`()` 

// TODO doc

#### `public uint16_t `[`getTachLowLimit`](#class_tecsmith___a_m_c6821_1a3375d4ed47bee34d10d1f6b4e8e902d3)`()` 

// TODO doc

#### `public uint16_t `[`getTachHighLimit`](#class_tecsmith___a_m_c6821_1a91b37c73fc9589d5f06703e3e6612887)`()` 

// TODO doc

#### `public uint16_t `[`getTachSetting`](#class_tecsmith___a_m_c6821_1a3838e483f470f75ac81e1907e7bd21dd)`()` 

// TODO doc

#### `public uint16_t `[`getTachDataRPM`](#class_tecsmith___a_m_c6821_1a762a7e9a0689064875310ab4d30e4c9e)`()` 

// TODO doc

#### `public uint16_t `[`getTachLowLimitRPM`](#class_tecsmith___a_m_c6821_1a7d2c980b3d5de1365682157e1f17ac17)`()` 

// TODO doc

#### `public uint16_t `[`getTachHighLimitRPM`](#class_tecsmith___a_m_c6821_1a23b93c9dcd6f8a234717c15eb1271b80)`()` 

// TODO doc

#### `public uint16_t `[`getTachSettingRPM`](#class_tecsmith___a_m_c6821_1a6158d06943555f89dd04223b36276224)`()` 

// TODO doc

Generated by [Moxygen](https://sourcey.com/moxygen)