#include <avr/sleep.h>
#include <avr/wdt.h>

// code from http://www.gammon.com.au/power

const byte LED = 7;
int i = 0;
bool flashnow = false;

void flash ()
  {
  pinMode (LED, OUTPUT);
  for (byte i = 0; i < 4; i++)
    {
    digitalWrite (LED, HIGH);
    delay (100);
    digitalWrite (LED, LOW);
    delay (1000);
    }
    
  pinMode (LED, INPUT);
    
  }  // end of flash
  
// watchdog interrupt
ISR (WDT_vect) 
{
   wdt_disable();  // disable watchdog
}  // end of WDT_vect

void wakeUp ()
{
  // cancel sleep as a precaution
  sleep_disable();
  // precautionary while we do other stuff
  detachInterrupt (0);
  flashnow = true;
}

void wakeUp1 ()
{
  // cancel sleep as a precaution
  sleep_disable();
  // precautionary while we do other stuff
  detachInterrupt (0);
  flashnow = true;
}  // end of wake

  // end of wake

void setup () { 
  digitalWrite (2, HIGH);  // enable pull-up
  }

void loop () 
{
  if (i == 4 || flashnow == true) {
    flash ();
    i = 0;
    flashnow = false;
  }
  i++;
  
  // disable ADC
  ADCSRA = 0;  

  // clear various "reset" flags
  MCUSR = 0;     
  // allow changes, disable reset
  WDTCSR = bit (WDCE) | bit (WDE);
  // set interrupt mode and an interval 
  WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 seconds delay
  wdt_reset();  // pat the dog
  
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
  sleep_enable();

  noInterrupts ();           // timed sequence follows

 // will be called when pin D2 goes low  
    attachInterrupt (0, wakeUp, FALLING);
    attachInterrupt (1, wakeUp1, FALLING);
    
    EIFR = bit (INTF0);  // clear flag for interrupt 0
    EIFR = bit (INTF1);  // clear flag for interrupt 1

  // turn off brown-out enable in software
  MCUCR = bit (BODS) | bit (BODSE);
  MCUCR = bit (BODS); 
  interrupts ();             // guarantees next instruction executed
  sleep_cpu ();  
  
  // cancel sleep as a precaution
  sleep_disable();
  
  } // end of loop
