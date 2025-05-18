/*
   This code is for Standard Cheap JOYSTICK only with LCD!!!
   This code is for Mahowik BalancingWii Transmitter with NRF24L01 (PWM Activated) ONLY!
   Please see our documentation and video
   https://www.youtube.com/@ardujimmy
   Please subscribe!
*/

/******************************************************* Multiwii 2.3 NRF24L01 Transmitter ********************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <EEPROM.h>

//const byte address[6] = "00001";
const uint64_t pipeOut = 0xE8E8F0F0E1LL;

RF24 radio(10, 9); // CE, CSN

unsigned long lastLcdUpdate = 0; // Track last LCD update time
const unsigned long lcdUpdateInterval = 100; // Update LCD every 100ms

unsigned long lastSendTime = 0; // Track last data send time
const unsigned long sendInterval = 20; // Send data every 20ms

#define btnLamp 2   // Pin for Lamp

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

struct MyData {
  byte throttle;
  byte yaw;
  byte pitch;
  byte roll;
  byte AUX1;
  byte AUX2;
  byte AUX3;  
  byte AUX4;  
};

MyData data;

void resetData() {
  data.throttle = 0;
  data.yaw = 127;
  data.pitch = 127;
  data.roll = 127;
  data.AUX1 = 0;
  data.AUX2 = 0;
  data.AUX3 = 0;
  data.AUX4 = 0;  
}

void setup() {
  Serial.begin(9600);

  pinMode(btnLamp, INPUT_PULLUP);
    
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipeOut);
  radio.setPALevel(RF24_PA_MIN);    
  resetData();
  //since we use Trimmer and the value stored in EEPROM, we need to show again in LCD to see if there is value of Pitch and Roll stored in EEPROM.
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device found at 0x");
      Serial.println(address, HEX);
    }
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
      Serial.println(F("SSD1306 allocation failed"));
      //for (;;);
    }
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    //Show in LCD
    display.clearDisplay();
    display.setCursor(0, 0); // Set cursor to top-left corner
    display.println("Hallo Ardujimmy");
    display.println("-------------------");
    display.println("Attempting to connect");
    display.println("0xE8E8F0F0E1LL RX");
    display.println("-------------------");    
    display.println("Please wait .....");      
    display.display();
    delay(100);
  }
}

int mapJoystickValues(int val, int lower, int middle, int upper, bool reverse) {
  val = constrain(val, lower, upper); // Constrain the input to safe bounds

  if (val < middle)
    val = map(val, lower, middle, 0, 127);   // Lower half → 0 to 127
  else
    val = map(val, middle, upper, 128, 255); // Upper half → 127 to 255

  return (reverse ? 255 - val : val); // Reverse axis if needed
}


/************************* Repeated Command *******************************/
void loop() {
  // Map joystick values
  data.throttle = mapJoystickValues(analogRead(A1),  1,   524, 1024, true);  // Throttle
  data.yaw      = mapJoystickValues(analogRead(A0),  2,   506, 1021, true);  // Yaw
  data.pitch    = mapJoystickValues(analogRead(A3),  0,   520, 1023, true);  // Pitch
  data.roll     = mapJoystickValues(analogRead(A2),  5,   512, 1024, true);  // Roll
  
  // Read AUX1 state
  data.AUX1 = digitalRead(3);
  data.AUX2 = digitalRead(4);
  data.AUX3 = map(analogRead(A6), 0, 1023, 1000, 2000); // AUX3 from pot on A6
  data.AUX4 = map(analogRead(A7), 0, 1023, 1000, 2000); // AUX4 from pot on A7


  
  // Send data at regular intervals
  if (millis() - lastSendTime >= sendInterval) {
    lastSendTime = millis();
    radio.write(&data, sizeof(MyData));
  }

  // Update LCD at regular intervals
  if (millis() - lastLcdUpdate >= lcdUpdateInterval) {
    lastLcdUpdate = millis();
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(data.AUX1 == 1 ? "AUX1 ON" : "AUX1 OFF");
    display.print(" | ");
    display.println(data.AUX2 == 1 ? "AUX2 ON" : "AUX2 OFF");    
    display.println("-------------------");
    display.println("Throttle: " + String(data.throttle));
    display.println("Yaw     : " + String(data.yaw));
    display.println("Roll    : " + String(data.roll));
    display.println("Pitch   : " + String(data.pitch));
    //display.println("");   
    //display.println("By Herman Ardujimmy");  
    display.display();
  }
}
