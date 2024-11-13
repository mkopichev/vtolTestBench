#include "../inc/ledStrip.h"

void ledStripInit(void) {

    DDRB |= (1 << 0);
    clearAll();
}

void zeros(void) {

    PORTB |= (1 << 0);
    PORTB &= ~(1 << 0);
}

void ones(void) {

    PORTB |= (1 << 0);
    _NOP();
    _NOP();
    _NOP();
    _NOP();
    _NOP();
    _NOP();
    _NOP();
    PORTB &= ~(1 << 0);
}

void lights(uint8_t G, uint8_t R, uint8_t B) {

    uint8_t i;
    for(i = 0b10000000; i >= 0b00000001; i = i >> 1) {

        if((G & i) > 0) {

            ones();
        } else {

            zeros();
        }
    }

    for(i = 0b10000000; i >= 0b00000001; i = i >> 1) {

        if((R & i) > 0) {

            ones();
        } else {

            zeros();
        }
    }

    for(i = 0b10000000; i >= 0b00000001; i = i >> 1) {

        if((B & i) > 0) {

            ones();
        } else {

            zeros();
        }
    }
}

void clearAll(void) {

    for(uint8_t i = 1; i <= STRIP_LENGTH; i++) {

        lights(0, 0, 0);
    }
    _delay_ms(5);
}

void hueToRgb(uint8_t hue, uint8_t brithness) {

    switch(brithness) {
    case STRIP_BRITHNESS_ULTRALOW:
        if(hue <= 85) {

            lights(0, (hue / 6), ((85 - hue) / 6));
            return;
        }
        if(hue > 170) {

            lights(((255 - hue) / 6), 0, ((hue - 171) / 6));
            return;
        } else {

            lights(((hue - 86) / 6), ((171 - hue) / 6), 0);
            return;
        }
        break;
    case STRIP_BRITHNESS_LOW:
        if(hue <= 85) {

            lights(0, (hue / 3), ((85 - hue) / 3));
            return;
        }
        if(hue > 170) {

            lights(((255 - hue) / 3), 0, ((hue - 171) / 3));
            return;
        } else {

            lights(((hue - 86) / 3), ((171 - hue) / 3), 0);
            return;
        }
        break;
    case STRIP_BRITHNESS_MEDIUM:
        if(hue <= 85) {

            lights(0, hue, (85 - hue));
            return;
        }
        if(hue > 170) {

            lights((255 - hue), 0, (hue - 171));
            return;
        } else {

            lights((hue - 86), (171 - hue), 0);
            return;
        }
        break;
    case STRIP_BRITHNESS_HIGH:
        if(hue <= 85) {

            lights(0, (hue * 3), ((85 - hue) * 3));
            return;
        }
        if(hue > 170) {

            lights(((255 - hue) * 3), 0, ((hue - 171) * 3));
            return;
        } else {

            lights(((hue - 86) * 3), ((171 - hue) * 3), 0);
            return;
        }
        break;
    }
}

void lightUp(rgb_strip_t *strip, uint8_t num, RGB_data_t color) {

    strip->rgbData[num] = color;
}

void draw(rgb_strip_t strip) {

    for(uint8_t i = 0; i < strip.length; i++) {

        lights(strip.rgbData[i].green, strip.rgbData[i].red, strip.rgbData[i].blue);
    }
}