#include <msp430.h>
#include "buzzer.h"
#include "symphony.h"

int i = 0;

void main(void) {
  WDTCTL = WDTPW + WDTHOLD; //Halt watchdog

  //Set bit0 and bit 6 to outputs
  P1DIR |= BIT0 + BIT6;
  P1OUT &= ~BIT0;
  P1OUT &= ~BIT6;

  //Set buttons of P2 to inputs
  P2REN |= BIT0 + BIT1 + BIT2 + BIT3;
  P2OUT |= BIT0 + BIT1 + BIT2 + BIT3;

  buzzer_init();
  
  while(1) {
    
    P1OUT |= BIT0 + BIT6;
    //Play a song with blinking LEDs
    if((P2IN & BIT0) == 0) {
      P1OUT &= ~BIT0;
      P1OUT &= ~BIT6;
      for(i=0; i<20000; i++);
      symphony();
    }
    //Alternate LEDs with sound
    else if((P2IN & BIT1) == 0) {
      P1OUT |= BIT0;
      P1OUT &= ~BIT6;
      buzzer_set_period(9000);
      for(i=0; i<30000; i++);
      P1OUT |= BIT6;
      P1OUT &= ~BIT0;
      buzzer_set_period(4000);
      for(i=0; i<30000; i++);
      buzzer_set_period(0);
    }
    //Dim LEDs
    else if((P2IN & BIT2) == 0) {
      while((P2IN & BIT2) == 0) {
        P1SEL |= BIT0;
        P1SEL |= BIT6;
        TA0CCR0 = 100;
        TA0CCR1 == 10;
        TA0CCTL1 = OUTMOD_7;
        TA0CTL = TASSEL_2 + MC_1;
        P1SEL &= ~BIT0;
	P1SEL &= ~BIT6; 
      }
    }
    //Play constant sound
    else if((P2IN & BIT3) == 0) {
	buzzer_set_period(8000);      
    }
  } 
}
