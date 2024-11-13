#ifndef LEDSTRIP_H_
#define LEDSTRIP_H_

#include "common.h"

#define STRIP_BRITHNESS_ULTRALOW 0
#define STRIP_BRITHNESS_LOW      1
#define STRIP_BRITHNESS_MEDIUM   2
#define STRIP_BRITHNESS_HIGH     3
#define STRIP_LENGTH             17 // n times by 3 LEDs

struct point {
    uint8_t x;
    uint8_t y;
};

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGB_data_t;

typedef struct {
    uint8_t length;
    uint8_t mode;
    uint8_t *hueData;
    RGB_data_t *rgbData;
} rgb_strip_t;

void ledStripInit(void);
void zeros(void);
void ones(void);
void lights(uint8_t G, uint8_t R, uint8_t B);
void clearAll(void);
void hueToRgb(uint8_t hue, uint8_t brithness);
void lightUp(rgb_strip_t *strip, uint8_t num, RGB_data_t color);
void draw(rgb_strip_t strip);

#endif