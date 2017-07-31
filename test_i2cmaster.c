
#include <avr/io.h>
#include "i2cmaster.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
		



#include <i2cmaster.h>
#define Dev24C02  0x9e      // device address, see datasheet


int main(void)
{
uint8_t ret;
float temp;
char *string;
char *string2;


uart_init(0);
uart_printstrn(0, "temperature ");


  while (1){
    ret=0;

    i2c_init(); 
                        // initialize I2C library
    // 
    i2c_start(Dev24C02+1);  // set device address and write mode

    ret=i2c_readAck();
    

    string = dtostrf(ret, 2, 0, string);
    


      string2= strcat(string,"°C");
      uart_printstrn(0, string2);
    

    i2c_stop();
    _delay_ms(2000);
    
     }
    
}
