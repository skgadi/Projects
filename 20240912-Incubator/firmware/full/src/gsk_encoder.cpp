#include "gsk_encoder.h"

GSK_ENCODER::GSK_ENCODER() {
    encoder = new ESP32Encoder();
    encoder->attachHalfQuad(GSK_PIN_ENCODER_CLK, GSK_PIN_ENCODER_DT);
    encoder->clearCount();
}