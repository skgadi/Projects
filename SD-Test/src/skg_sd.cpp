#include "skg_sd.h"


SKG_SD::SKG_SD() {
  SPI.begin(SKG_SD_SCK, SKG_SD_MISO, SKG_SD_MOSI, SKG_SD_CS);
  if (!SD.begin(SKG_SD_CS, SPI, (uint32_t)  10000000)) {
    Serial.println("SD card initialization failed!");
    while (1);
  }
  openTestFile();
  openMainFile();
}

bool SKG_SD::isSDCardPresent() {
  try {
    return openTestFile();
  } catch (const std::exception& e) {
    return false;
  }
}

bool SKG_SD::openFile(String filename) {
  if (filename == "") {
    return false;
  }
  File file = SD.open(filename, FILE_WRITE);
  if (!file) {
    return false;
  }
  return true;
}

bool SKG_SD::openTestFile() {
  if (testFile) {
    testFile.close();
  }
  testFile = SD.open("/test.bin", FILE_WRITE);
  if (!testFile) {
    return false;
  }
  return true;
}

bool SKG_SD::openMainFile() {
  if (mainFile) {
    mainFile.close();
  }
  mainFile = SD.open("/main.bin", FILE_WRITE);
  if (!mainFile) {
    return false;
  }
  return true;
}


void SKG_SD::closeTestFile() {
  if (testFile) {
    testFile.close();
  }
}

void SKG_SD::closeMainFile() {
  if (mainFile) {
    mainFile.close();
  }
}


bool SKG_SD::appendMainFile(float* array, int arrayLength) {
  if (!mainFile) {
    return false;
  }
  mainFile.write((uint8_t*)array, arrayLength * sizeof(float));
  return true;
}