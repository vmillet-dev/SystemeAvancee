# MIF18-Lab 4: Arduino 101

  * Laure Gonnord, Université Lyon 1, LIP [email](mailto:laure.gonnord@univ-lyon1.fr)
  * Version: 2020.01
  * Inspired by a lab with Sebastien Mosser, UQAM, Montreal.
  * Other collaborators: Lionel Morel (Insa Lyon), Julien Forget (Lille).
  * Deadline : Monday, April 24h, 6pm strict, on Tomuss.
  * [General Instructions for MIF18](../HOWTO_CR_TP_MIF18.md)
  * Special instructions for this Lab : deliver code from step1 to step4, and your report with your answers to questions (in French or English)

## Problem Description 

In this lab you will be asked to write simple Arduino programs that
interact with sensors/actuators. The objective is double:
* Manipulate the platform and the compilation chain
* Experiment two variants of Arduino programming and compare their pros and cons.

Prerequisite : Test your arduino setting [follow this
link](_startup.md)

All given code is in this [code directory](_code/)


## Step 1:  Led on Digital 13 + Button on Digital 10 (ex1/)


* Button on digital 10, and 220 ohm resistor

![Button on Port Digital 10](figs/p-boutonpoussoir_arduino.png)


*  Write a `int get_reset_value()`
  function that reads on digital 10 (use `PINB` value and some boolean
  operators). Use it in the `main` to control the led (switch it on to
  off or off to on if the button is pressed).


## Step 2: Two LEDs with different frequencies (ex2/)

Now make two leds blink at different frequencies (the second one uses
PIN 12). Make your code as generic as possible.

In the README, explain your solution for different values of the
frequencies. Explain why is it satisfactory or not ? What would you
like as a developper?

## Step 3: Led, Button, 7 segment V1 (ex3/)

Here is the new component assembly:
<p align="center">
  <img src="https://raw.githubusercontent.com/mosser/sec-labs/master/lab_1/figs/montage.jpg"/>
</p>


* The seven segment displays can be "common cathode" or "common anode"
	(common anode for most of us, but please test with the code provided in `_code/test7seg`). See the startup before making this exercice.
	
	
The objective is to build the following behavior:
  1. Switch on or off a LED based on a button sensor;
  2. Building a simple counter using a 7-segment display;
  3. Compose the two behaviors so that the button control both the display and the LED.

![Expected behavior](figs/expected_behavior_cr10.png)


### Expected work

* We give you a starting code. 

* Add functionality for the button (see `ex1`). Do not forget to update
  the `setup` function if required. Test.

* Add functionality for the seven-segment display: write a `void
display_7seg(int value)` function to display a given number.
As an
  example, our version begins with:
```C
void display_7seg(int value){
  switch (value) {
  case 0: //a,b,c,d,e,f
    PORTD = 0b01111110;
    break;
	//todo: implement the rest!
}
```

And use it to increment the 7 segment value each time you enter the
  loop. If the button is pressed, the 7-segment should reset
  to 0. Test.



### Questions (TBD in README)
  - What can we say about readability of this code? What are the skills required to write such a program?
  - Regarding embedded systems, how could you characterize the
  expressivity (can all applications be written in that way) ?
  The configurability of the code to change pins or behavior? Its debugging capabilities?
  - Regarding the performance of the output code, what kind of parallelism is expressed by the use of the DDRx registers?
  - What if we add additional tasks in the micro-controller code, with the same frequency? With a different frequency?

## Step 4: Led, Button, 7 segment V2 (ex4/)

A little journey into the Arduino library. 

## The LED example
* Include `Arduino.h` and link with the lib (the Makefile does this
job):
```C
#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>
```

* Now each pin has his own configuration and can be set independently
of the others:   `pinMode(led, OUTPUT);` for the led setup and
`digitalWrite(led, LOW);`,  `digitalWrite(led, HIGH);` to set the led
value.

* We have to store the led state in the `led_on` variable.


## Documentation & Bibliography

* The Arduino C++ library
[reference](https://www.arduino.cc/en/Reference/HomePage). See
the `pinMode` and `digitalRead` documentation.


## Expected Work

* Implement the Button functionality. Test it!
* Implement the Seven Segment display functionnality: first implement `displayDigit`:
```C
void displayDigit(int digit)
{
  turnOff();
  //Conditions for displaying segment a
  if(digit!=1 && digit != 4)
    digitalWrite(a,HIGH);
	//continue
	}
```
and use it in the main. Test it!


## Feedback Questions

  - Is the readability problem solved?
  - What kind of parallelism can still be expressed? (task parallelism, instruction parallelism, hardware parallelism) ? 
  - Who is the public targeted by this "language"? It it ok for
    (real-time) system programmers ? 
  - Is this language extensible enough to support new features?
  - What is the price for the developer?
