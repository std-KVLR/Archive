#include <mega8.h>
#include <stdio.h>
// Declare your global variables here

// TWI functions
#include <twi.h>
#include <delay.h>

// TWI Slave receive buffer
#define TWI_RX_BUFFER_SIZE 8
unsigned char twi_rx_buffer[TWI_RX_BUFFER_SIZE];

// TWI Slave transmit buffer
#define TWI_TX_BUFFER_SIZE 1
unsigned char twi_tx_buffer[TWI_TX_BUFFER_SIZE];

// TWI Slave receive handler
// This handler is called everytime a byte
// is received by the TWI slave

bit flag = 0;
bool twi_rx_handler(bool rx_complete)
{
if (twi_result==TWI_RES_OK)
   {   
   // A data byte was received without error
   // and it was stored at twi_rx_buffer[twi_rx_index]
   // Place your code here to process the received byte
   // Note: processing must be VERY FAST, otherwise
   // it is better to process the received data when
   // all communication with the master has finished    
   flag = 1; 
   }
else
   {
   // Receive error
   // Place your code here to process the error    
   flag = 0;

   return false; // Stop further reception
   }

// The TWI master has finished transmitting data?
if (rx_complete) return false; // Yes, no more bytes to receive

// Signal to the TWI master that the TWI slave
// is ready to accept more data, as long as
// there is enough space in the receive buffer
return (twi_rx_index<2);
}

// TWI Slave transmission handler
// This handler is called for the first time when the
// transmission from the TWI slave to the master
// is about to begin, returning the number of bytes
// that need to be transmitted
// The second time the handler is called when the
// transmission has finished
// In this case it must return 0
unsigned char twi_tx_handler(bool tx_complete)
{
if (tx_complete==false)
   {
   // Transmission from slave to master is about to start
   // Return the number of bytes to transmit
   return sizeof(twi_tx_buffer);
   }

// Transmission from slave to master has finished
// Place code here to eventually process data from
// the twi_rx_buffer, if it wasn't yet processed
// in the twi_rx_handler

// No more bytes to send in this transaction
return 0;
}

void main(void)
{

long result = 0;

UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

// TWI initialization
// Mode: TWI Slave
// Match Any Slave Address: Off
// I2C Bus Slave Address: 0x01
twi_slave_init(false,0x01,twi_rx_buffer,2,twi_tx_buffer,twi_rx_handler,twi_tx_handler);

delay_ms(2000);
          
// Global enable interrupts
#asm("sei")

delay_ms(10000);


printf("%d", flag);
result = (unsigned int)(twi_rx_buffer[0] << 8);
result |= twi_rx_buffer[1];

printf("%d %d %d", twi_rx_index, sizeof(twi_rx_buffer), TWCR);
printf("%ld", result);


while (1)
      {
      // Place your code here

      }
}