# Christmas Star Led Chaser
It blinks a LED connected to the PIN 4 via a resistor. For uploading binaries I use USBasp programmer which supports TPI (Tiny Programming Interface) and SPI (Serial Peripheral Interface).

TIP: [How to program AVR microcontrollers in Visual Studio Code](https://github.com/chovanj/Microcontrollers/wiki/How-to-program-AVR-microcontrollers-in-Visual-Studio-Code)

## Supported microcontrollers
The code is written specifically for ATtiny13A, but it should work also on other microcontrollers.

## How to compile and upload it to a microcontroller

### Option 1
In Visual Studio Code just press Ctrl+Shift+B and it compiles the code and uploads it to a microcontroller. For correct intellisense in Visual Studio Code don't forget to change c_cpp_properties.json to your target microcontroller.
```
"defines": [
                "__AVR_ATtiny13A__"
            ], 
```

### Option 2
By default for ATtiny13A, F_CPU=1000000UL.
```
make
```

### Option 3
```
avr-gcc simple_blink.c -mmcu=attiny13 -DF_CPU=1000000UL -Os -o simple_blink.bin
avrdude -c usbasp -p attiny13 -U simple_blink.bin
```
