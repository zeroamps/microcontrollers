MCU = attiny10
F_CPU = 1000000UL

upload: simple_blink.bin
	avrdude -c usbasp -p $(MCU) -U simple_blink.bin

simple_blink.bin: simple_blink.c
	avr-gcc simple_blink.c -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -o simple_blink.bin
