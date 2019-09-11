# Blink
It blinks a LED connected to the PIN 2 via a resistor. It works the same on ATtiny4, ATtiny5, ATtiny9 and ATtiny10. For uploading binaries I use USBasp programmer which supports TPI (Tiny Programming Interface).

## ATtiny4 
avr-gcc blink.c -mmcu=attiny4 -DF_CPU=1000000UL -Os -o blink.bin
avrdude -c usbasp -p attiny4 -U blink.bin

## ATtiny5
avr-gcc blink.c -mmcu=attiny5 -DF_CPU=1000000UL -Os -o blink.bin
avrdude -c usbasp -p attiny5 -U blink.bin

## ATtiny9 
avr-gcc blink.c -mmcu=attiny9 -DF_CPU=1000000UL -Os -o blink.bin
avrdude -c usbasp -p attiny9 -U blink.bin

## ATtiny10 
avr-gcc blink.c -mmcu=attiny10 -DF_CPU=1000000UL -Os -o blink.bin
avrdude -c usbasp -p attiny10 -U blink.bin
