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
`public bool `[`write`](#class_tecsmith___a_m_c6821_1a4c005b600345946f6304eff8571a1a26)`(uint8_t addr,uint8_t data,uint8_t mask)` | Writes one byte, preserving prior bits in optional mask.
`public uint16_t `[`read2`](#class_tecsmith___a_m_c6821_1acd0e2678852e6901dd24a8d42f3983e8)`(uint8_t addrL,uint8_t addrH)` | Reads two bytes.
`public bool `[`write2`](#class_tecsmith___a_m_c6821_1aca6b03d9ff0d30f182d84102f973e963)`(uint8_t addrL,uint8_t addrH,uint16_t data)` | 
`public bool `[`begin`](#class_tecsmith___a_m_c6821_1a3b4cc41c383b957fc0fc000451fdc4c4)`(uint8_t i2c_addr,TwoWire * wire)` | Sets up the hardware and initializes I2C.
`public bool `[`reset`](#class_tecsmith___a_m_c6821_1a8f4ac3380656f8a6a68caddd34c0ccab)`()` | Sends a reset command to the chip.
`public bool `[`start`](#class_tecsmith___a_m_c6821_1a9fa03a47ffa95f4b6a95a43c333e8fa9)`()` | Sends a start command to the chip.
`public bool `[`stop`](#class_tecsmith___a_m_c6821_1af04c1c473596f1338eb812ce22e14c27)`()` | Sends a stop command to the chip.
`public uint8_t `[`getDeviceID`](#class_tecsmith___a_m_c6821_1a06d0b99c178e3d1f6326b180600bd638)`()` | 
`public uint8_t `[`getCompanyID`](#class_tecsmith___a_m_c6821_1a8cac8c856b122e00baa5e5e80466e0f4)`()` | 
`public uint8_t `[`getPartRevision`](#class_tecsmith___a_m_c6821_1a7011b9f6263f416aa9e41e4ea789d67d)`()` | 
`public uint8_t `[`getConfig`](#class_tecsmith___a_m_c6821_1a975e6a6b4239885742ec2c0afb86c62e)`(byte no)` | 
`public bool `[`getStartMonitor`](#class_tecsmith___a_m_c6821_1a4db57d335278bad1a6a7136eaac162f1)`()` | 
`public bool `[`getGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a4ec3cb3b620eda1f69025b976be3f745)`()` | 
`public bool `[`getRPMIntEnable`](#class_tecsmith___a_m_c6821_1a704df85dbc3fd69ff9c59bdfbaf92f18)`()` | 
`public bool `[`getPWMInvert`](#class_tecsmith___a_m_c6821_1a9e5ffdcdf4f9149411b1e75938f22363)`()` | 
`public bool `[`getFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a42d5bd43fce219b3213eabcf18cd939a)`()` | 
`public amc6821_conf1_fdrc_t `[`getFanControlMode`](#class_tecsmith___a_m_c6821_1a03ea5ddd36e336f3654793e56a065835)`()` | 
`public bool `[`getThermIntEnable`](#class_tecsmith___a_m_c6821_1a42d5b193a9e28fb3624a9994550cf3bd)`()` | 
`public bool `[`getPWMOutEnable`](#class_tecsmith___a_m_c6821_1af8e6333e67570550e53904ed9adc8408)`()` | 
`public bool `[`getTachMode`](#class_tecsmith___a_m_c6821_1ab5c9a5a9d121aadf0cbe42154f1bb705)`()` | 
`public bool `[`getTachEnable`](#class_tecsmith___a_m_c6821_1a338bd6df8670552bea9da86026d9c27c)`()` | 
`public bool `[`getRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1abd6b7acba7405eec7bb367341a956e30)`()` | 
`public bool `[`getLTIntEnable`](#class_tecsmith___a_m_c6821_1abc09649eaa5adaec0d9703a9e62d5d04)`()` | 
`public bool `[`getRTIntEnable`](#class_tecsmith___a_m_c6821_1a685a899c04f3ee09e3035bc1fda322fb)`()` | 
`public bool `[`getLPSVIntEnable`](#class_tecsmith___a_m_c6821_1aedae174724a0e0b4ec44d6392953568a)`()` | 
`public bool `[`getTermFanEnable`](#class_tecsmith___a_m_c6821_1aa4629fbdcad09192ec2e8814d9fa9801)`()` | 
`public bool `[`getOVREnable`](#class_tecsmith___a_m_c6821_1aa492f48a51e40d3c771ac4f98aff6cc2)`()` | 
`public bool `[`getTachReadingFast`](#class_tecsmith___a_m_c6821_1af007d8510cead3adbfa7b205c6d79599)`()` | 
`public bool `[`getPulseNumber`](#class_tecsmith___a_m_c6821_1a61a9754bbb52c3a6a46687cee36c06ee)`()` | 
`public bool `[`setStartMonitor`](#class_tecsmith___a_m_c6821_1ac420bc0ee9bb0f514c3736466d19b227)`(bool on)` | 
`public bool `[`setGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a6ecee7342ca22543b429a288405dcfeb)`(bool on)` | 
`public bool `[`setRPMIntEnable`](#class_tecsmith___a_m_c6821_1a01fa700f7a04005af70f284d070dc914)`(bool on)` | 
`public bool `[`setPWMInvert`](#class_tecsmith___a_m_c6821_1a2e4db48877028a788f84e2ee38d334ad)`(bool on)` | 
`public bool `[`setFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a9d23940b744414f9e1750b06416f3104)`(bool on)` | 
`public bool `[`setFanControlMode`](#class_tecsmith___a_m_c6821_1a374de01255a7adbe640ca093a19d4b0e)`(amc6821_conf1_fdrc_t mode)` | 
`public bool `[`setThermIntEnable`](#class_tecsmith___a_m_c6821_1a37ebeed4a406000386588a9dd5d554f3)`(bool on)` | 
`public bool `[`setPWMOutEnable`](#class_tecsmith___a_m_c6821_1a9212bdbfd125bb3342b714f63422f059)`(bool on)` | 
`public bool `[`setTachMode`](#class_tecsmith___a_m_c6821_1a6ef32e9fa76ac14ea8ff5bdd1238ff2e)`(bool on)` | 
`public bool `[`setTachEnable`](#class_tecsmith___a_m_c6821_1ad31c17f04ca79a872025b5c81ed4386c)`(bool on)` | 
`public bool `[`setRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1ab9f606abc434bc86e0c36543c6d5c1d4)`(bool on)` | 
`public bool `[`setLTIntEnable`](#class_tecsmith___a_m_c6821_1a1e8028e6d2ca6877561d3f84ce8fcb11)`(bool on)` | 
`public bool `[`setRTIntEnable`](#class_tecsmith___a_m_c6821_1aaaae58f60e31acb2a68886a6f7f22de3)`(bool on)` | 
`public bool `[`setLPSVIntEnable`](#class_tecsmith___a_m_c6821_1ab01d5fe6dabbb1ea3d5793134a2b284f)`(bool on)` | 
`public bool `[`setReset`](#class_tecsmith___a_m_c6821_1a5e53ba08704654c53d9f95c744d4ec9b)`()` | 
`public bool `[`setTermFanEnable`](#class_tecsmith___a_m_c6821_1aa8d16db1763e73efcdc1274909b58e47)`(bool on)` | 
`public bool `[`setOVREnable`](#class_tecsmith___a_m_c6821_1a15ac80d9c13df6af30ec784f68a040bc)`(bool on)` | 
`public bool `[`setTachReadingFast`](#class_tecsmith___a_m_c6821_1a8c99df85e5d581cd83ce784ef6dc0d88)`(bool on)` | 
`public bool `[`setPulseNumber`](#class_tecsmith___a_m_c6821_1a0bce22939aae76e134c6ee8038b5e48b)`(bool on)` | 
`public uint8_t `[`getStatus`](#class_tecsmith___a_m_c6821_1af838168e598d2a0214dc2c52d9dd8ca4)`(byte no)` | 
`public bool `[`getFanFast`](#class_tecsmith___a_m_c6821_1adce845795961541bd9b9fbc6c627b22b)`()` | 
`public bool `[`getFanSlow`](#class_tecsmith___a_m_c6821_1aa1dd63f6c4d50cf9c605022f2d4998e7)`()` | 
`public bool `[`getRTHigh`](#class_tecsmith___a_m_c6821_1a273ab7a903bf37b9cbfe4758f3614dca)`()` | 
`public bool `[`getRTLow`](#class_tecsmith___a_m_c6821_1a1973cc6ce0250af32f0acbcdaf389ef8)`()` | 
`public bool `[`getRTOverTherm`](#class_tecsmith___a_m_c6821_1a4a794e4cfe783083a05a4a97f1e46876)`()` | 
`public bool `[`getRTFailure`](#class_tecsmith___a_m_c6821_1a2f6287d321ea35ca7b6fc4baba2e8ce1)`()` | 
`public bool `[`getLTHigh`](#class_tecsmith___a_m_c6821_1a71c0f9eb8a8324af43ae3a8ad0721fce)`()` | 
`public bool `[`getLTLow`](#class_tecsmith___a_m_c6821_1a17d5100d26e2f7c6f8f24ad74dac333f)`()` | 
`public bool `[`getRTOverCritical`](#class_tecsmith___a_m_c6821_1a6b019dbff62e0ccff3619ded4103029e)`()` | 
`public bool `[`getLTOverCritical`](#class_tecsmith___a_m_c6821_1ab838c76e6bb967012b6ece973c6e060c)`()` | 
`public bool `[`getLTBelowTherm`](#class_tecsmith___a_m_c6821_1ae8da7da6e1b0b1792f353e3af85de4ef)`()` | 
`public bool `[`getLTOverTherm`](#class_tecsmith___a_m_c6821_1af173502594c0a90d94c1ac8ede2ea599)`()` | 
`public bool `[`getThermInput`](#class_tecsmith___a_m_c6821_1af449bc004d4c2b4d2c579132499cfc29)`()` | 
`public int8_t `[`getLocalTemp`](#class_tecsmith___a_m_c6821_1acdc8554e62e645df61e4303ce78ec1ee)`()` | 
`public int8_t `[`getRemoteTemp`](#class_tecsmith___a_m_c6821_1a4b7fe610c8a5718c625ac13474e7ec9f)`()` | 
`public int32_t `[`getLocalMilliTemp`](#class_tecsmith___a_m_c6821_1a4de9164804011815c15f0e65e0b8f033)`()` | 
`public int32_t `[`getRemoteMilliTemp`](#class_tecsmith___a_m_c6821_1a0d767540121c93130e2452f2f82450eb)`()` | 
`public int8_t `[`getLocalHighTempLimit`](#class_tecsmith___a_m_c6821_1a03c9a8bfd85a3d895873ce644ab9705a)`()` | 
`public int8_t `[`getLocalLowTempLimit`](#class_tecsmith___a_m_c6821_1a4665d6045821c703c0ead141cc9f024a)`()` | 
`public int8_t `[`getLocalThermLimit`](#class_tecsmith___a_m_c6821_1a9705d7ee363a901ab89552fc4fb26e7e)`()` | 
`public int8_t `[`getRemoteHighTempLimit`](#class_tecsmith___a_m_c6821_1ae94939cc6daa0a6ec8b50952785d5810)`()` | 
`public int8_t `[`getRemoteLowTempLimit`](#class_tecsmith___a_m_c6821_1a2c7394e26dd1cb496527046b841083ce)`()` | 
`public int8_t `[`getRemoteThermLimit`](#class_tecsmith___a_m_c6821_1ae00baa1a2307d7c6c55d09a8a415d70b)`()` | 
`public int8_t `[`getLocalCriticalTemp`](#class_tecsmith___a_m_c6821_1ad0518343273070d5e90675a2468672c4)`()` | 
`public int8_t `[`getPassiveCoolingTemp`](#class_tecsmith___a_m_c6821_1a07ee0aa9d8b8378b55f7e4637f3a6201)`()` | 
`public int8_t `[`getRemoteCriticalTemp`](#class_tecsmith___a_m_c6821_1a56d95cceffecbc5d51205841a4d54284)`()` | 
`public uint8_t `[`getFanCharacteristics`](#class_tecsmith___a_m_c6821_1a7fed6e2ca8932dd0fadc910c42151df4)`()` | 
`public uint8_t `[`getDutyCycleLowTemp`](#class_tecsmith___a_m_c6821_1a037c112093c9f3d67742b3735b06c8bf)`()` | 
`public uint8_t `[`getDutyCycle`](#class_tecsmith___a_m_c6821_1a36c7a1162a0244ad6b4a4912e723ce14)`()` | 
`public uint8_t `[`getDutyCycleRamp`](#class_tecsmith___a_m_c6821_1a6a05f6d20a3f38b2d01e3ad2263ca58d)`()` | 
`public uint8_t `[`getLocalTempFanControl`](#class_tecsmith___a_m_c6821_1a5eb68ac6477ea5fef04762adc548b0ef)`()` | 
`public uint8_t `[`getRemoteTempFanControl`](#class_tecsmith___a_m_c6821_1a7efa03021ee65a1072851edf49959c46)`()` | 
`public uint16_t `[`getTachData`](#class_tecsmith___a_m_c6821_1ac3636e82a5172f1424088e9fffc1f4ac)`()` | 
`public uint16_t `[`getTachLowLimit`](#class_tecsmith___a_m_c6821_1a3375d4ed47bee34d10d1f6b4e8e902d3)`()` | 
`public uint16_t `[`getTachHighLimit`](#class_tecsmith___a_m_c6821_1a91b37c73fc9589d5f06703e3e6612887)`()` | 
`public uint16_t `[`getTachSetting`](#class_tecsmith___a_m_c6821_1a3838e483f470f75ac81e1907e7bd21dd)`()` | 
`public uint16_t `[`getTachDataRPM`](#class_tecsmith___a_m_c6821_1a762a7e9a0689064875310ab4d30e4c9e)`()` | 
`public uint16_t `[`getTachLowLimitRPM`](#class_tecsmith___a_m_c6821_1a7d2c980b3d5de1365682157e1f17ac17)`()` | 
`public uint16_t `[`getTachHighLimitRPM`](#class_tecsmith___a_m_c6821_1a23b93c9dcd6f8a234717c15eb1271b80)`()` | 
`public uint16_t `[`getTachSettingRPM`](#class_tecsmith___a_m_c6821_1a6158d06943555f89dd04223b36276224)`()` | 

## Members

#### `public  `[`Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726)`()` 

Construct a new [Tecsmith_AMC6821::Tecsmith_AMC6821](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726) object.

#### `public  `[`~Tecsmith_AMC6821`](#class_tecsmith___a_m_c6821_1a1904256c63506b85b5391b5e1d0376e9)`()` 

Destroy the [Tecsmith_AMC6821::Tecsmith_AMC6821](#class_tecsmith___a_m_c6821_1ae3396cb9ac30464ea96f051185bfa726) object.

#### `public uint8_t `[`read`](#class_tecsmith___a_m_c6821_1a1065eb8b7784e4f2132133497a10d4b7)`(uint8_t addr)` 

Reads one byte.

#### `public bool `[`write`](#class_tecsmith___a_m_c6821_1a4c005b600345946f6304eff8571a1a26)`(uint8_t addr,uint8_t data,uint8_t mask)` 

Writes one byte, preserving prior bits in optional mask.

#### `public uint16_t `[`read2`](#class_tecsmith___a_m_c6821_1acd0e2678852e6901dd24a8d42f3983e8)`(uint8_t addrL,uint8_t addrH)` 

Reads two bytes.

WARNING: The low byte should be read first. This method causes the high byte to be frozen until both the high and low byte registers have been read from, preventing erroneous TACH readings.

#### `public bool `[`write2`](#class_tecsmith___a_m_c6821_1aca6b03d9ff0d30f182d84102f973e963)`(uint8_t addrL,uint8_t addrH,uint16_t data)` 

#### `public bool `[`begin`](#class_tecsmith___a_m_c6821_1a3b4cc41c383b957fc0fc000451fdc4c4)`(uint8_t i2c_addr,TwoWire * wire)` 

Sets up the hardware and initializes I2C.

#### Parameters
* `i2c_address` The I2C address to be used. 

* `wire` The Wire object to be used for I2C connections. 

#### Returns
True if initialization was successful, otherwise false.

#### `public bool `[`reset`](#class_tecsmith___a_m_c6821_1a8f4ac3380656f8a6a68caddd34c0ccab)`()` 

Sends a reset command to the chip.

#### `public bool `[`start`](#class_tecsmith___a_m_c6821_1a9fa03a47ffa95f4b6a95a43c333e8fa9)`()` 

Sends a start command to the chip.

#### `public bool `[`stop`](#class_tecsmith___a_m_c6821_1af04c1c473596f1338eb812ce22e14c27)`()` 

Sends a stop command to the chip.

#### `public uint8_t `[`getDeviceID`](#class_tecsmith___a_m_c6821_1a06d0b99c178e3d1f6326b180600bd638)`()` 

#### `public uint8_t `[`getCompanyID`](#class_tecsmith___a_m_c6821_1a8cac8c856b122e00baa5e5e80466e0f4)`()` 

#### `public uint8_t `[`getPartRevision`](#class_tecsmith___a_m_c6821_1a7011b9f6263f416aa9e41e4ea789d67d)`()` 

#### `public uint8_t `[`getConfig`](#class_tecsmith___a_m_c6821_1a975e6a6b4239885742ec2c0afb86c62e)`(byte no)` 

#### `public bool `[`getStartMonitor`](#class_tecsmith___a_m_c6821_1a4db57d335278bad1a6a7136eaac162f1)`()` 

#### `public bool `[`getGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a4ec3cb3b620eda1f69025b976be3f745)`()` 

#### `public bool `[`getRPMIntEnable`](#class_tecsmith___a_m_c6821_1a704df85dbc3fd69ff9c59bdfbaf92f18)`()` 

#### `public bool `[`getPWMInvert`](#class_tecsmith___a_m_c6821_1a9e5ffdcdf4f9149411b1e75938f22363)`()` 

#### `public bool `[`getFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a42d5bd43fce219b3213eabcf18cd939a)`()` 

#### `public amc6821_conf1_fdrc_t `[`getFanControlMode`](#class_tecsmith___a_m_c6821_1a03ea5ddd36e336f3654793e56a065835)`()` 

#### `public bool `[`getThermIntEnable`](#class_tecsmith___a_m_c6821_1a42d5b193a9e28fb3624a9994550cf3bd)`()` 

#### `public bool `[`getPWMOutEnable`](#class_tecsmith___a_m_c6821_1af8e6333e67570550e53904ed9adc8408)`()` 

#### `public bool `[`getTachMode`](#class_tecsmith___a_m_c6821_1ab5c9a5a9d121aadf0cbe42154f1bb705)`()` 

#### `public bool `[`getTachEnable`](#class_tecsmith___a_m_c6821_1a338bd6df8670552bea9da86026d9c27c)`()` 

#### `public bool `[`getRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1abd6b7acba7405eec7bb367341a956e30)`()` 

#### `public bool `[`getLTIntEnable`](#class_tecsmith___a_m_c6821_1abc09649eaa5adaec0d9703a9e62d5d04)`()` 

#### `public bool `[`getRTIntEnable`](#class_tecsmith___a_m_c6821_1a685a899c04f3ee09e3035bc1fda322fb)`()` 

#### `public bool `[`getLPSVIntEnable`](#class_tecsmith___a_m_c6821_1aedae174724a0e0b4ec44d6392953568a)`()` 

#### `public bool `[`getTermFanEnable`](#class_tecsmith___a_m_c6821_1aa4629fbdcad09192ec2e8814d9fa9801)`()` 

#### `public bool `[`getOVREnable`](#class_tecsmith___a_m_c6821_1aa492f48a51e40d3c771ac4f98aff6cc2)`()` 

#### `public bool `[`getTachReadingFast`](#class_tecsmith___a_m_c6821_1af007d8510cead3adbfa7b205c6d79599)`()` 

#### `public bool `[`getPulseNumber`](#class_tecsmith___a_m_c6821_1a61a9754bbb52c3a6a46687cee36c06ee)`()` 

#### `public bool `[`setStartMonitor`](#class_tecsmith___a_m_c6821_1ac420bc0ee9bb0f514c3736466d19b227)`(bool on)` 

#### `public bool `[`setGlobalIntEnable`](#class_tecsmith___a_m_c6821_1a6ecee7342ca22543b429a288405dcfeb)`(bool on)` 

#### `public bool `[`setRPMIntEnable`](#class_tecsmith___a_m_c6821_1a01fa700f7a04005af70f284d070dc914)`(bool on)` 

#### `public bool `[`setPWMInvert`](#class_tecsmith___a_m_c6821_1a2e4db48877028a788f84e2ee38d334ad)`(bool on)` 

#### `public bool `[`setFanFaultPinEnable`](#class_tecsmith___a_m_c6821_1a9d23940b744414f9e1750b06416f3104)`(bool on)` 

#### `public bool `[`setFanControlMode`](#class_tecsmith___a_m_c6821_1a374de01255a7adbe640ca093a19d4b0e)`(amc6821_conf1_fdrc_t mode)` 

#### `public bool `[`setThermIntEnable`](#class_tecsmith___a_m_c6821_1a37ebeed4a406000386588a9dd5d554f3)`(bool on)` 

#### `public bool `[`setPWMOutEnable`](#class_tecsmith___a_m_c6821_1a9212bdbfd125bb3342b714f63422f059)`(bool on)` 

#### `public bool `[`setTachMode`](#class_tecsmith___a_m_c6821_1a6ef32e9fa76ac14ea8ff5bdd1238ff2e)`(bool on)` 

#### `public bool `[`setTachEnable`](#class_tecsmith___a_m_c6821_1ad31c17f04ca79a872025b5c81ed4386c)`(bool on)` 

#### `public bool `[`setRemoteFailureIntEnable`](#class_tecsmith___a_m_c6821_1ab9f606abc434bc86e0c36543c6d5c1d4)`(bool on)` 

#### `public bool `[`setLTIntEnable`](#class_tecsmith___a_m_c6821_1a1e8028e6d2ca6877561d3f84ce8fcb11)`(bool on)` 

#### `public bool `[`setRTIntEnable`](#class_tecsmith___a_m_c6821_1aaaae58f60e31acb2a68886a6f7f22de3)`(bool on)` 

#### `public bool `[`setLPSVIntEnable`](#class_tecsmith___a_m_c6821_1ab01d5fe6dabbb1ea3d5793134a2b284f)`(bool on)` 

#### `public bool `[`setReset`](#class_tecsmith___a_m_c6821_1a5e53ba08704654c53d9f95c744d4ec9b)`()` 

#### `public bool `[`setTermFanEnable`](#class_tecsmith___a_m_c6821_1aa8d16db1763e73efcdc1274909b58e47)`(bool on)` 

#### `public bool `[`setOVREnable`](#class_tecsmith___a_m_c6821_1a15ac80d9c13df6af30ec784f68a040bc)`(bool on)` 

#### `public bool `[`setTachReadingFast`](#class_tecsmith___a_m_c6821_1a8c99df85e5d581cd83ce784ef6dc0d88)`(bool on)` 

#### `public bool `[`setPulseNumber`](#class_tecsmith___a_m_c6821_1a0bce22939aae76e134c6ee8038b5e48b)`(bool on)` 

#### `public uint8_t `[`getStatus`](#class_tecsmith___a_m_c6821_1af838168e598d2a0214dc2c52d9dd8ca4)`(byte no)` 

#### `public bool `[`getFanFast`](#class_tecsmith___a_m_c6821_1adce845795961541bd9b9fbc6c627b22b)`()` 

#### `public bool `[`getFanSlow`](#class_tecsmith___a_m_c6821_1aa1dd63f6c4d50cf9c605022f2d4998e7)`()` 

#### `public bool `[`getRTHigh`](#class_tecsmith___a_m_c6821_1a273ab7a903bf37b9cbfe4758f3614dca)`()` 

#### `public bool `[`getRTLow`](#class_tecsmith___a_m_c6821_1a1973cc6ce0250af32f0acbcdaf389ef8)`()` 

#### `public bool `[`getRTOverTherm`](#class_tecsmith___a_m_c6821_1a4a794e4cfe783083a05a4a97f1e46876)`()` 

#### `public bool `[`getRTFailure`](#class_tecsmith___a_m_c6821_1a2f6287d321ea35ca7b6fc4baba2e8ce1)`()` 

#### `public bool `[`getLTHigh`](#class_tecsmith___a_m_c6821_1a71c0f9eb8a8324af43ae3a8ad0721fce)`()` 

#### `public bool `[`getLTLow`](#class_tecsmith___a_m_c6821_1a17d5100d26e2f7c6f8f24ad74dac333f)`()` 

#### `public bool `[`getRTOverCritical`](#class_tecsmith___a_m_c6821_1a6b019dbff62e0ccff3619ded4103029e)`()` 

#### `public bool `[`getLTOverCritical`](#class_tecsmith___a_m_c6821_1ab838c76e6bb967012b6ece973c6e060c)`()` 

#### `public bool `[`getLTBelowTherm`](#class_tecsmith___a_m_c6821_1ae8da7da6e1b0b1792f353e3af85de4ef)`()` 

#### `public bool `[`getLTOverTherm`](#class_tecsmith___a_m_c6821_1af173502594c0a90d94c1ac8ede2ea599)`()` 

#### `public bool `[`getThermInput`](#class_tecsmith___a_m_c6821_1af449bc004d4c2b4d2c579132499cfc29)`()` 

#### `public int8_t `[`getLocalTemp`](#class_tecsmith___a_m_c6821_1acdc8554e62e645df61e4303ce78ec1ee)`()` 

#### `public int8_t `[`getRemoteTemp`](#class_tecsmith___a_m_c6821_1a4b7fe610c8a5718c625ac13474e7ec9f)`()` 

#### `public int32_t `[`getLocalMilliTemp`](#class_tecsmith___a_m_c6821_1a4de9164804011815c15f0e65e0b8f033)`()` 

#### `public int32_t `[`getRemoteMilliTemp`](#class_tecsmith___a_m_c6821_1a0d767540121c93130e2452f2f82450eb)`()` 

#### `public int8_t `[`getLocalHighTempLimit`](#class_tecsmith___a_m_c6821_1a03c9a8bfd85a3d895873ce644ab9705a)`()` 

#### `public int8_t `[`getLocalLowTempLimit`](#class_tecsmith___a_m_c6821_1a4665d6045821c703c0ead141cc9f024a)`()` 

#### `public int8_t `[`getLocalThermLimit`](#class_tecsmith___a_m_c6821_1a9705d7ee363a901ab89552fc4fb26e7e)`()` 

#### `public int8_t `[`getRemoteHighTempLimit`](#class_tecsmith___a_m_c6821_1ae94939cc6daa0a6ec8b50952785d5810)`()` 

#### `public int8_t `[`getRemoteLowTempLimit`](#class_tecsmith___a_m_c6821_1a2c7394e26dd1cb496527046b841083ce)`()` 

#### `public int8_t `[`getRemoteThermLimit`](#class_tecsmith___a_m_c6821_1ae00baa1a2307d7c6c55d09a8a415d70b)`()` 

#### `public int8_t `[`getLocalCriticalTemp`](#class_tecsmith___a_m_c6821_1ad0518343273070d5e90675a2468672c4)`()` 

#### `public int8_t `[`getPassiveCoolingTemp`](#class_tecsmith___a_m_c6821_1a07ee0aa9d8b8378b55f7e4637f3a6201)`()` 

#### `public int8_t `[`getRemoteCriticalTemp`](#class_tecsmith___a_m_c6821_1a56d95cceffecbc5d51205841a4d54284)`()` 

#### `public uint8_t `[`getFanCharacteristics`](#class_tecsmith___a_m_c6821_1a7fed6e2ca8932dd0fadc910c42151df4)`()` 

#### `public uint8_t `[`getDutyCycleLowTemp`](#class_tecsmith___a_m_c6821_1a037c112093c9f3d67742b3735b06c8bf)`()` 

#### `public uint8_t `[`getDutyCycle`](#class_tecsmith___a_m_c6821_1a36c7a1162a0244ad6b4a4912e723ce14)`()` 

#### `public uint8_t `[`getDutyCycleRamp`](#class_tecsmith___a_m_c6821_1a6a05f6d20a3f38b2d01e3ad2263ca58d)`()` 

#### `public uint8_t `[`getLocalTempFanControl`](#class_tecsmith___a_m_c6821_1a5eb68ac6477ea5fef04762adc548b0ef)`()` 

#### `public uint8_t `[`getRemoteTempFanControl`](#class_tecsmith___a_m_c6821_1a7efa03021ee65a1072851edf49959c46)`()` 

#### `public uint16_t `[`getTachData`](#class_tecsmith___a_m_c6821_1ac3636e82a5172f1424088e9fffc1f4ac)`()` 

#### `public uint16_t `[`getTachLowLimit`](#class_tecsmith___a_m_c6821_1a3375d4ed47bee34d10d1f6b4e8e902d3)`()` 

#### `public uint16_t `[`getTachHighLimit`](#class_tecsmith___a_m_c6821_1a91b37c73fc9589d5f06703e3e6612887)`()` 

#### `public uint16_t `[`getTachSetting`](#class_tecsmith___a_m_c6821_1a3838e483f470f75ac81e1907e7bd21dd)`()` 

#### `public uint16_t `[`getTachDataRPM`](#class_tecsmith___a_m_c6821_1a762a7e9a0689064875310ab4d30e4c9e)`()` 

#### `public uint16_t `[`getTachLowLimitRPM`](#class_tecsmith___a_m_c6821_1a7d2c980b3d5de1365682157e1f17ac17)`()` 

#### `public uint16_t `[`getTachHighLimitRPM`](#class_tecsmith___a_m_c6821_1a23b93c9dcd6f8a234717c15eb1271b80)`()` 

#### `public uint16_t `[`getTachSettingRPM`](#class_tecsmith___a_m_c6821_1a6158d06943555f89dd04223b36276224)`()` 

Generated by [Moxygen](https://sourcey.com/moxygen)