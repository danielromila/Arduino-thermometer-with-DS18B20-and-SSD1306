// This code is written by Sreekanth Mp and his practical implementation can be seen at
// https://www.youtube.com/watch?v=iaNiQ1sQbSA&lc=z23wentrykres1tz504t1aokghsi44vdfindpmf0pzmwbk0h00410.1573904852647521

#include <OneWire.h>    //////////////////////TEMP SENSOR SECTION
#include <DallasTemperature.h>

#include <Adafruit_GFX.h>//////////////////////OLED SECTION
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4//////////////////////////////OLED 
#define WIDTH     128//////// the lower right corner is (X=128, Y=63)
#define HEIGHT     64
#define NUM_PAGE    8
#define NUMFLAKES 10
#define XPOS 0/////////////////Every pixel on the display has a coordinate that is specified with a X and //Y. 
              ///////////////////The X increases from left to right and Y increases from top to the bottom. and
#define YPOS 0//////////////////The upper left corner of the screen is (X=0, Y=0) 
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
Adafruit_SSD1306 display(OLED_RESET);

#define ONE_WIRE_BUS 8////////////////////temp signal wire coonected to 8 D/PIN
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
float Celcius = 0;

void setup(void)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);///// Call the begin function of the display object by passing our I2C address 0x3C
  Serial.begin(9600);
  sensors.begin();

  display.clearDisplay();/////////////clears the display completely.
  display.setTextSize(2);/////////accepts an integer number as a size. The greater the number, the bigger the text would be. Smallest size is 1 which is the default size //of texts.
  display.setTextColor(WHITE);///////////////specify the color using display.setTextColor() WHITE/BLACK
  display.setCursor(15, 8);//////////////////specify where on the display we're going to display the text.
  display.println("SREEKANTH");////////////We draw something on by calling on our (display) object,
  display.display();//////////////////Call the display.display() function to make the actual drawing happen on the hardware level.
  delay(2000);

}

void loop()
{
  sensors.requestTemperatures();///////////////getting the actual temperature value.
  Celcius = sensors.getTempCByIndex(0);//////////get the temperature in Celsius.we’re using just one sensor its index is 0.
  //////////////////////////////////////////////If you have more than one sensor, you use index 0 for the ///first sensor, index 1 for the second sensor, and so on.
  Serial.print(" C  ");
  Serial.println(Celcius);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(30, 0);
  display.setTextSize(1);
  display.println("TEMPERATURE:");
  display.setTextSize(2);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(34, 14);
  display.println(Celcius);

  display.drawLine(0, 8, 128, 8, WHITE);
  display.drawLine (110, 10, 110, 22, WHITE);
  display.drawLine (114, 10, 114, 22, WHITE);
  display.drawLine (110, 10, 114, 10, WHITE);
  display.drawCircle (112, 25, 3, WHITE);
  display.drawCircle (112, 25, 4, WHITE);
  display.drawPixel (112, 12, WHITE);
  display.drawPixel (112, 14, WHITE);
  display.drawPixel (112, 16, WHITE);
  display.drawPixel (112, 18, WHITE);
  display.drawPixel (112, 20, WHITE);
  display.display();

}
