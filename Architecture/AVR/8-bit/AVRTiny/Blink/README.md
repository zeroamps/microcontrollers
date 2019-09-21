# Blink
It blinks a LED connected to the PIN 2 via a resistor. For uploading binaries I use USBasp programmer which supports TPI (Tiny Programming Interface) and SPI (Serial Peripheral Interface).

## Supported microcontrollers
ATtiny4, ATtiny5, ATtiny9, ATtiny10, ATtiny20 and ATtiny40.

## How to compile and upload it to a microcontroller

### Option 1
In Visual Studio Code just press Ctrl+Shift+B.

### Option 2
By default for ATtiny10, F_CPU=1000000UL.
```
make
```

### Option 3
For any other microcontrollers.
```
make MCU=attiny20 F_CPU=8000000UL
```

### Option 4
```
avr-gcc blink.c -mmcu=attiny4 -DF_CPU=1000000UL -Os -o blink.bin
avrdude -c usbasp -p attiny4 -U blink.bin
```

#### Note
For correct intellisense in Visual Studio Code don't forget to change to your target microcontroller in c_cpp_properties.json.
```
"defines": [
                "__AVR_ATtiny10__"
            ], 
```
