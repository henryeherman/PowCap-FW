#include <avr/io.h>
#include "SPI.h"

void SPI_MasterInit(void) {
     //Set Direction For MOSI and SCK PIN
    DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS)|(1<<DD_SS2); 
    //Set SPI Control Registers
    PORT_SPI = PORT_SPI | PSS;
    PORT_SPI = PORT_SPI | PSS2;
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<CPOL);
}

void SPI_MaterTransmit(char cData) {
    SPDR = cData;
    while(!(SPSR & (1<<SPIF)));
}

