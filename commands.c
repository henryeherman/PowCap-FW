#include "commands.h"
#include <stdlib.h>
#include "SPI.h"


void cb_gain1(char *param) {
    char *s;
    int16_t val;
    s = param;
    val = strtol(param,&s,16);
    for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
    }
    SELECT1();
    SPI_MaterTransmit(val);
    UNSELECT1();

}

void cb_gain2(char *param) {
    char *s;
    int16_t val;
    s = param;
    val = strtol(param,&s,16);
    for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
    }
    SELECT0();
    SPI_MaterTransmit(val);
    UNSELECT0();
}


