# Blink
It blinks a LED connected to the PIN 2 via a resistor. It works the same on ATtiny4, ATtiny5, ATtiny9 and ATtiny10. For uploading binaries I use USBasp programmer which supports TPI (Tiny Programming Interface).

## ATtiny4 
### How to build
avr-gcc blink.c -mmcu=attiny4 -DF_CPU=1000000UL -Os -o blink.bin

### How to upload
avrdude -c usbasp -p attiny4 -U blink.bin

## ATtiny5
### How to build
avr-gcc blink.c -mmcu=attiny5 -DF_CPU=1000000UL -Os -o blink.bin

### How to upload
avrdude -c usbasp -p attiny5 -U blink.bin

## ATtiny9 
### How to build
avr-gcc blink.c -mmcu=attiny9 -DF_CPU=1000000UL -Os -o blink.bin

### How to upload
avrdude -c usbasp -p attiny9 -U blink.bin

## ATtiny10 
### How to build
avr-gcc blink.c -mmcu=attiny10 -DF_CPU=1000000UL -Os -o blink.bin

### How to upload
avrdude -c usbasp -p attiny10 -U blink.bin
