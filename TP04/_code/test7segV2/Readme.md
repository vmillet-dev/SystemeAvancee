# Arduino Lab

## 7 seg test : common adode or common cathode ?

Common anode : middle wires on grnd (blue or black line)
Common cathode : middle wires on +5V (red line)
Do not forget to plug resistors.

a on Digital 1, b on digital 2, .... g on digital 10


## How to compile?

```
laure@vernet$ make
avr-gcc -c -mmcu=atmega328p -Wall -I. -I/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino -I/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard -DF_CPU=16000000 -Os  main.c -o main.o
avr-gcc -c -mmcu=atmega328p -Wall -I. -I/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino -I/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard -DF_CPU=16000000 -Os  wiring.c -o wiring.o
avr-gcc -c -mmcu=atmega328p -Wall -I. -I/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino -I/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard -DF_CPU=16000000 -Os  wiring_digital.c -o wiring_digital.o
avr-gcc -g -mmcu=atmega328p -lm -Wl,--gc-sections  -o test7seg.elf main.o wiring.o wiring_digital.o
avr-objcopy -j .text -j .data -O ihex test7seg.elf test7seg.hex
avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 -O ihex test7seg.elf eeprom.hex
avr-objcopy: --change-section-lma .eeprom=0x0000000000000000 never used
```

## How to upload to the board?

```
laure@vernet$ make upload
stty -f /dev/tty.usbmodem* hupcl # reset
...
avrdude done.  Thank you.
```
