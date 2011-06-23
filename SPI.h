


#ifndef __SPI_H_
#define __SPI_H_


#include <avr/io.h>

#define DD_MOSI DDB2  //SPI PINS available on PortB

#define DD_SCK DDB1  //SCK pin is PB1

#define DD_SS DDB0  //SS pin is PB0

#define DD_SS2 DDB4 //SS2 pin is PB4

#define PSS PORTB0  //SS pin is PB00

#define PSS2 PORTB4

#define DDR_SPI DDRB //Data direction port for SPI is PortB 

#define PORT_SPI PORTB

#define SELECT0()   (PORT_SPI &=~(_BV(PSS)))
#define SELECT1()   (PORT_SPI &=~(_BV(PSS2)))
#define UNSELECT0()    (PORT_SPI |= _BV(PSS))
#define UNSELECT1()    (PORT_SPI |= _BV(PSS2))
 
void SPI_MasterInit(void);
void SPI_MaterTransmit(char cData); 

#endif

