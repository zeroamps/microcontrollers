MCU = attiny10
F_CPU = 1000000UL

upload: blink.bin
	avrdude -c usbasp -p $(MCU) -U blink.bin

blink.bin: blink.c
	avr-gcc blink.c -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -o blink.bin
