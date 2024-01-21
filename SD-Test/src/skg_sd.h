#ifndef SKG_SD_H
#define SKG_SD_H

#include <SPI.h>
#include <SD.h>

#define SKG_SD_CS 5
#define SKG_SD_MOSI 23
#define SKG_SD_MISO 19
#define SKG_SD_SCK 18


class SKG_SD {
  File testFile;
  File mainFile;
  bool openFile(String filename);
  void closeFile(FILE file);
  public:
    SKG_SD();
    bool openTestFile();
    bool openMainFile();
    void closeTestFile();
    void closeMainFile();
    bool isSDCardPresent();
    bool appendMainFile(float* array, int arrayLength);
};

#endif // SKG_SD_H
