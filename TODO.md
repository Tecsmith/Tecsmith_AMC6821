# Publishing your library

## Official

https://github.com/arduino/library-registry/blob/main/FAQ.md#readme

https://github.com/arduino/library-registry/blob/main/README.md#adding-a-library-to-library-manager

## Unofficial

(Extracted from: https://arduinoplusplus.wordpress.com/2018/02/19/writing-arduino-libraries/ )

Once you have created you library you may wish to publish it to the world.

One option is to store the source code on a publicly accessible code repository (like GitHub, BitBucket or GitLab) and hope people will find it. They can then download and install it manually on their systems.

A better option is to use the process the Arduino Team has created to allow your library to be found by the Library Manager:

- Host the library on a major git-hosting website. GitHub is the easiest here as Arduino is also on GitHub.

- Ensure your library is compliant with the version 1.5 format (discussed above) as the v1.5 format folder layout is required.

- [Tag](https://git-scm.com/book/en/v2/Git-Basics-Tagging) the code and push the tag (or create a release) of your code. The tag must be the version number in 1.0.0 format and match the version number in the library.properties file.

- On the [Arduino GitHub](https://github.com/arduino/Arduino/issues) site, open an issue specifying the URL of the repository you wish to add to the Library Manager list.

- When your issue is dealt with and closed, the library will be available for installation via Library Manager. Subsequent updates of the repository will automatically be picked up provided the version number in the Tag and library.properties match.

### Useful References

*"Arduino IDE 1.5: Library Specification"*, Arduino github site at https://github.com/arduino/arduino/wiki/arduino-ide-1.5:-library-specification

*"Arduino Library Style Guide"*, Arduino References site at http://arduino.cc/en/Reference/APIStyleGuide

<p align="center">*</p>
