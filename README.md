# monkey-bean

This is the Arduino code that runs the monkey.

The arduino in the monkey is a [LightBlue Bean](https://punchthrough.com/bean) and can be programmed over bluetooth.

## Programming A LightBlue Bean

To program the LightBlue Bean, follow the [Get Started directions here](https://punchthrough.com/bean/docs/guides/getting-started/intro/).

## NeoPixel

The monkey has two neopixels, both attached to PIN 1 on the LightBlue Bean. In order to use the AdaFruit_NeoPixel library, you need to install it in the Aurduino app.

### Installing the NeoPixel library

1. Open the Arduino app
2. From the menu, navigate Sketch -> Include Library -> Manage Libraries...
3. Search for `NeoPixel`
4. Click on `AdaFruit NeoPixel` (for me this was the second one down after searching)
5. Choose the most recent version (I'm using 1.0.6) and Install
