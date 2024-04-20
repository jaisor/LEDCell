# LEDCell

3D printed xehagonal shape with LED stip glued on the inner wall. 
Logic driven by a [Seeeduino XIAO](https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html) XIAO 
using the [FastLED](https://github.com/FastLED/FastLED) library. The controller requires USB-C cable.

LED strip needs to be 5V, else will require separate power accommodations.
Any individually programmable LEDs supported by FastLED should work.
I have used [this WS2812B strip](https://www.amazon.com/gp/product/B08B59CBK9/) which fits 61 LEDs as defined in the beginning of [main.cpp](src/main.cpp).
The LEDs are powered directly by the USB 5V and proper 1A+ USB adapter should be able adequate unless burning all LEDs at max-white continuously, 
which will cause overheat issues as well.

Once all is ready and tested, I used some E6000 glue to secure the controller and LEDs, but other adhesives or mouting tapes might work.

![Wiring](/pics/Wires.jpg)
![Plugged In](/pics/On.jpg)

## Development

USB driver for Windows required: [Silicon Labs CP210X](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)

Recommended: [VSCode](https://code.visualstudio.com/) + [PlatformIO](https://platformio.org/)

## 3D Print

STL files:

* [Base](stl/LEDCell-base.stl)
* [Lid Plain](stl/LEDCell-lid-plain.stl)
* [Lid Honey](stl/LEDCell-lid-Honey.stl)

### Printing recommendations

White PLA with some level of translucency (most white PLA should work). I have used the following succesfully:
* [ELEGOO PLA Plus](https://www.amazon.com/dp/B0C14M5HR9) - warm and cool white work good, warm is a bit more translucent
* [Hatchbox PLA White](https://www.amazon.com/gp/product/B00J0GMMP6)

I print at around 200C nozzle. Layer height at half of nozzle diameter. No supports needed for any of the parts. 
No need for brim and should be printed without raft to ensure smooth bottom layer.
Prints well on 0.6mm nozzle with 0.3 mm hegight. The rest of the settings are printer specifics.