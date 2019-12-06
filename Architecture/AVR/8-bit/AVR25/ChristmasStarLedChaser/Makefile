MCU = attiny13
F_CPU = 1000000UL

upload: christmas_star_led_chaser.bin
	avrdude -c usbasp -p $(MCU) -U christmas_star_led_chaser.bin -B4

christmas_star_led_chaser.bin: christmas_star_led_chaser.c
	avr-gcc christmas_star_led_chaser.c -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -o christmas_star_led_chaser.bin
