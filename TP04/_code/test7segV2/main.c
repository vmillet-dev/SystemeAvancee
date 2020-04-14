// MIF18 Test 7 seg Common cathode or common anode ? 

#include <avr/io.h>
#include <util/delay.h>

// code for common cathode 
//7 seg on digital 1 to 7 (a-> digital 1, ...)

// If CC : all led off, and "a" led is on for a while, then off a short time, and so on
// If CA : all on, and "a" led is off for a while, then on for a short time, and so on

void init(void)
{
  // This is mysterious, we'll see later
  DDRD |= 0b11111110; 
}

void ledAon()
{
  PORTD = 0b00000010;
}

void ledAoff(){
  PORTD = 0000000000;
}


int main(void)
{
  init();
  while(1) //infinite loop
    {
      ledAon();
      _delay_ms(2000);  
      ledAoff();
      _delay_ms(200);  
    }
  
  return 0;
}
