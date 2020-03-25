#include <msp430.h>
#include "buzzer.h"
#include "symphony.h"

int j = 0;

void symphony(void) {
      P1OUT &= ~BIT0;
      P1OUT &= ~BIT6;
      for(j=0; j<30000; j++);
      
      c_note();
      c_note();
      d_note();
      e_note();
      e_note();
      d_note();
      c_note();
      b_note();
      a_note();
      a_note();
      b_note();
      c_note();
      b_note();
      for(j=0; j<5000; j++);
      b_note();
}

void a_note(void) {
  P1OUT |= BIT0 + BIT6;
  buzzer_set_period(10000);
  for(j=0; j<20000; j++);
  buzzer_set_period(0);
  P1OUT &= ~BIT0;
  P1OUT &= ~BIT6;
  for(j=0; j<10000; j++);
}

void b_note(void) {
  P1OUT |= BIT6;
  buzzer_set_period(9000);
  for(j=0; j<20000; j++);
  buzzer_set_period(0);
  P1OUT &= ~BIT6;
  for(j=0; j<10000; j++);
}

void c_note(void) {
  P1OUT |= BIT0 + BIT6;
  buzzer_set_period(8000);
  for(j=0; j<20000; j++);
  buzzer_set_period(0);
  P1OUT &= ~BIT0;
  P1OUT &= ~BIT6;
  for(j=0; j<10000; j++);
}

void d_note(void) {
  P1OUT |= BIT0;
  buzzer_set_period(7000);
  for(j=0; j<20000; j++);
  buzzer_set_period(0);
  P1OUT &= ~BIT0;
  for(j=0; j<10000; j++);
}

void e_note(void) {
  P1OUT |= BIT0 + BIT6;
  buzzer_set_period(6000);
  for(j=0; j<20000; j++);
  buzzer_set_period(0);
  P1OUT &= ~BIT0;
  P1OUT &= ~BIT6;
  for(j=0; j<10000; j++);
}
