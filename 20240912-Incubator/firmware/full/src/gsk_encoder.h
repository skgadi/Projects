#ifndef GSK_ENCODER_H
#define GSK_ENCODER_H

#include <ESP32Encoder.h>

#include "gsk_global.h"

class GSK_ENCODER {
    ESP32Encoder* encoder;

   public:
    GSK_ENCODER();
};

#endif  // GSK_ENCODER_H