/*
 * OccupancyDetector.c
 *
 *  Created on: Jan 30, 2023
 *      Author: Jacob Drennen
 */


#include <msp430.h>

char ToggleEnable = 0x01;                       // Global Variable to track if the LED should be on or off

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
  P1DIR |= BIT0;              // Configure P1.0 to an Output
  P6DIR |= BIT6;              // Configure P6.6 to an Output
  P2DIR &= ~BIT3;             // Configure P2.3 to an Input
  P4DIR &= ~BIT1;             // Configure P4.1 to an Input
  P2REN |= BIT3;               // Enable Resistor on P2.3
  P2OUT |= BIT3;               // Configure Resistor on P2.3 to be Pullup
  P4REN |= BIT1;               // Enable Resistor on P4.1
  P4OUT |= BIT1;               // Configure Resistor on P4.1 to be Pullup
  PM5CTL0 &= ~LOCKLPM5;
  unsigned char i=0;  //setting counter to 0
  while(1)
  {
      if(!(P4IN & BIT1))    //reset if button is pressed
      {
          P1OUT &= ~BIT0;   //turns red led off
          i=0;
      }
      if(!(P2IN & BIT3))    //If button press
        {
          P6OUT &= ~BIT6;       //turns green led off just in case it is still on
              while(i<56)       //while looper for timer. Flashes red button. 15 seconds
              {
                  P1OUT ^= BIT0;
                  __delay_cycles(500000);
                  P1OUT ^= ~BIT0;
                  i++;
              }
              if(i>=56)           //if i goes over 56(15 seconds) red stays on
              {
                P1OUT |= BIT0;
              }
        }
        else                    //green flashes
        {
            if(i >= 56)        //if timer variable reaches the 15 seconds hold red light on
            {
                P1OUT |= BIT0;
            }
            else            //else flash green light every 3 seconds, and reset i to 0
            {
                P1OUT &= ~BIT0; //sets red led to 0 just incase it was still on
                P6OUT ^= BIT6;
                __delay_cycles(100000);
                P6OUT ^= ~BIT6;
                __delay_cycles(3000000);
                i=0;
         }
}
 }
 }





