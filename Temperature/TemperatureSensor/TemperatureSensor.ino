#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

//Temperature Sensor Variables
int ledRed = 3;
int ledGreen = 4;
float volts;
float celsius;

//Display
int timeUpdateTemperature = 1000;

//Animations
int timeAnimationCount;
int maxTimeAnimationCount = 5;

void setup() {

  //Display//
  lcd.init();
  lcd.backlight();
  //Debug//
  Serial.begin(9600); 
  //Temperature Sensor//
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  //TEMPERATURE SENSOR//
  int value = analogRead(A0);
  float volts = (value * 5) / 1023.0;
  float celsius = volts * 100;
  Serial.print(celsius);
  Serial.println(" C");
  delay(1000);
  //LEDs//
  LEDs(celsius);
  //DISPLAY//
  Display(celsius);
  //ANIMATION CONTROLLER//
  animationsController();
}

void Display(float temperature){
  //Temperature Celsius
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ROOM TEMPERATURE");
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.setCursor(6,1);
  lcd.print("C");
  //Temperature Fahrenheit
  lcd.setCursor(9,1);
  lcd.print((temperature * 9.0)/5.0+32.0);
  lcd.setCursor(15,1);
  lcd.print("F");
  timeAnimationCount += 1;
  delay(timeUpdateTemperature);
}

void LEDs(float actualTemperature)
{ 
  int isHot = 25;
  int isCold = 18;
  if(actualTemperature > isHot || actualTemperature < isCold){
      digitalWrite(ledGreen,LOW);
      digitalWrite(ledRed,HIGH);
  }else{
    if(actualTemperature > isCold && actualTemperature < isHot)
    {
      digitalWrite(ledGreen, HIGH); digitalWrite(ledRed,LOW);
    } 
  }
}


//ANIMATIONS//
//CONTROLLER ANIMATION
void animationsController()
{
  if(timeAnimationCount == maxTimeAnimationCount || timeAnimationCount > maxTimeAnimationCount)
  {
    int randomAnimation = random(0, 4);
    switch(randomAnimation)
    {
        case 0: DinoAnimation(); break;
        //case 1: HorseAnimation(); break; -> Bug.
        case 1: ButterflyAnimation(); break;
        case 2: InsectAnimation(); break;
    }
    delay(2000);
    timeAnimationCount = 0;
  }
}
//DINO
void DinoAnimation(){

  byte chardino1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11100
  };

byte chardino2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
  };
byte chardino3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11100
  };
byte chardino4[8] = {
  B10000,
  B11000,
  B11000,
  B11000,
  B00000,
  B10000,
  B00000,
  B00000
  };
byte chardino5[8] = {
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00010,
  B00011
  };
byte chardino6[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B10110,
  B00010,
  B00010,
  B00011
  };

byte chardino7[8] = {
  B11111,
  B11001,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
  };
  int time = 400;
  int t = 100;
  lcd.clear();
  lcd.createChar(1,chardino1);
  lcd.createChar(2,chardino2);
  lcd.createChar(3,chardino3);
  lcd.createChar(4,chardino4);
  lcd.createChar(5,chardino5);
  lcd.createChar(6,chardino6);
  lcd.createChar(7,chardino7);
  for (int a=0; a<=18; a++)
  {
  if(a>=3){
  lcd.setCursor(a-3,0);
  lcd.write(1);}
  if(a>=2)
  {lcd.setCursor(a-2,0);
  lcd.write(2);}
  if(a>=1)
  {lcd.setCursor(a-1,0);
  lcd.write(3);}
  lcd.setCursor(a,0);
  lcd.write(4);
  
  if(a>=3){
  lcd.setCursor(a-3,1);
  lcd.write(5);}
  if(a>=2){
  lcd.setCursor(a-2,1);
  lcd.write(6);}
  if(a>=1){
  lcd.setCursor(a-1,1);
  lcd.write(7);}
  
  delay(time);
    lcd.clear();
 }

}
//HORSE
void HorseAnimation()
{
  int x = 0;

  byte chr[2][8][8] = {
    {
      {0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0E, 0x0E},
      {0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F},
      {0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x1F, 0x1F},
      {0x00, 0x00, 0x05, 0x1F, 0x1D, 0x1F, 0x16, 0x06},
      {0x0C, 0x18, 0x10, 0x00, 0x01, 0x01, 0x01, 0x00},
      {0x1F, 0x1F, 0x1E, 0x17, 0x00, 0x00, 0x10, 0x00},
      {0x1F, 0x1F, 0x03, 0x02, 0x14, 0x04, 0x02, 0x00},
      {0x1C, 0x1C, 0x04, 0x04, 0x08, 0x00, 0x00, 0x00}
    },

    {
      {0x00, 0x00, 0x00, 0x07, 0x0F, 0x0E, 0x1C, 0x18},
      {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F},
      {0x00, 0x00, 0x01, 0x03, 0x1F, 0x1F, 0x1F, 0x1F},
      {0x14, 0x1C, 0x1A, 0x1E, 0x1F, 0x13, 0x10, 0x10},
      {0x13, 0x13, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00},
      {0x1F, 0x07, 0x0E, 0x06, 0x01, 0x00, 0x00, 0x00},
      {0x0F, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00},
      {0x10, 0x18, 0x0C, 0x02, 0x02, 0x11, 0x00, 0x00}
    }
  };

  for (int f = 0; f < 2; f++) {
    lcd.clear();
    for (int i=0; i<8; i++) {
      lcd.createChar(i, chr[f][i]);
    }
    for (int c = 0; c < 4; c++) {
      int xc = x+c;
      if ((xc >= 0)&&(xc < 16)) {
        lcd.setCursor(x+c, 0); lcd.write(byte(c));
        lcd.setCursor(x+c, 1); lcd.write(byte(c+4));
      }
    }
    delay(200);
  }

}

//Butterfly
void ButterflyAnimation()
{
    image00();
    delay(250);
    image01();
    delay(250);
    image02();
    delay(250);
    image03();
    delay(700);
    image04();
    delay(250);
    image05();
    delay(250);
    image06();
    delay(700);
    image07();
    delay(1250);
}

void image00()
{
    lcd.clear();

    byte image22[8] = {B00110, B01101, B11011, B10011, B00111, B01111, B01111, B11111};
    byte image23[8] = {B01111, B11110, B11100, B11000, B11000, B10000, B10000, B00000};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00111};
    byte image08[8] = {B00000, B01000, B10000, B10000, B10000, B11111, B11111, B11000};
    byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B11000, B11000, B00100};

    lcd.createChar(0, image22);
    lcd.createChar(1, image23);
    lcd.createChar(2, image07);
    lcd.createChar(3, image08);
    lcd.createChar(4, image09);

    lcd.setCursor(5, 1);
    lcd.write(byte(0));
    lcd.setCursor(6, 1);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(8, 0);
    lcd.write(byte(4));
}

void image01()
{
    lcd.clear();

    byte image22[8] = {B00110, B00101, B00011, B00011, B00111, B01111, B01111, B11111};
    byte image23[8] = {B01111, B11110, B11100, B11000, B11000, B10000, B10000, B00000};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B11001, B10111};
    byte image08[8] = {B00000, B01000, B10000, B10000, B10000, B11111, B11111, B11000};
    byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B11000, B11000, B00100};
    byte image06[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00011};

    lcd.createChar(0, image22);
    lcd.createChar(1, image23);
    lcd.createChar(2, image07);
    lcd.createChar(3, image08);
    lcd.createChar(4, image09);
    lcd.createChar(5, image06);

    lcd.setCursor(5, 1);
    lcd.write(byte(0));
    lcd.setCursor(6, 1);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(8, 0);
    lcd.write(byte(4));
    lcd.setCursor(5, 0);
    lcd.write(byte(5));
}

void image02()
{
    lcd.clear();

    byte image22[8] = {B00000, B00001, B00011, B00011, B00111, B01111, B01111, B11111};
    byte image23[8] = {B01111, B11110, B11100, B11000, B11000, B10000, B10000, B00000};
    byte image07[8] = {B00000, B00000, B00000, B00001, B00111, B00100, B11001, B10111};
    byte image08[8] = {B00000, B01000, B10000, B10000, B10000, B11111, B11111, B11000};
    byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B11000, B11000, B00100};

    lcd.createChar(0, image22);
    lcd.createChar(1, image23);
    lcd.createChar(2, image07);
    lcd.createChar(3, image08);
    lcd.createChar(4, image09);

    lcd.setCursor(5, 1);
    lcd.write(byte(0));
    lcd.setCursor(6, 1);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(8, 0);
    lcd.write(byte(4));
}

void image03()
{
    lcd.clear();

    byte image22[8] = {B00000, B00001, B00011, B00011, B00111, B01111, B01111, B11111};
    byte image23[8] = {B01111, B11110, B11100, B11000, B11000, B10000, B10000, B00000};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00111};
    byte image08[8] = {B00000, B01000, B10000, B10000, B10000, B11111, B11111, B11010};
    byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B11000, B11000, B00100};
    byte image24[8] = {B00010, B00111, B00111, B00111, B00111, B00111, B00010, B00000};

    lcd.createChar(0, image22);
    lcd.createChar(1, image23);
    lcd.createChar(2, image07);
    lcd.createChar(3, image08);
    lcd.createChar(4, image09);
    lcd.createChar(5, image24);

    lcd.setCursor(5, 1);
    lcd.write(byte(0));
    lcd.setCursor(6, 1);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(8, 0);
    lcd.write(byte(4));
    lcd.setCursor(7, 1);
    lcd.write(byte(5));
}

void image04()
{
    lcd.clear();

    byte image22[8] = {B00000, B00001, B00011, B00011, B00111, B01111, B01111, B11111};
    byte image23[8] = {B01111, B11110, B11100, B11000, B11000, B10001, B10000, B00000};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00111};
    byte image08[8] = {B00000, B01000, B10000, B10000, B10000, B11111, B11111, B11010};
    byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B11000, B11000, B00100};
    byte image24[8] = {B00010, B00100, B01011, B10101, B11010, B10101, B11010, B01110};
    byte image25[8] = {B00000, B00000, B00000, B10000, B10000, B00000, B00000, B00000};

    lcd.createChar(0, image22);
    lcd.createChar(1, image23);
    lcd.createChar(2, image07);
    lcd.createChar(3, image08);
    lcd.createChar(4, image09);
    lcd.createChar(5, image24);
    lcd.createChar(6, image25);

    lcd.setCursor(5, 1);
    lcd.write(byte(0));
    lcd.setCursor(6, 1);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(8, 0);
    lcd.write(byte(4));
    lcd.setCursor(7, 1);
    lcd.write(byte(5));
    lcd.setCursor(8, 1);
    lcd.write(byte(6));
}

void image05()
{
    lcd.clear();

    byte image24[8] = {B01010, B10100, B01011, B10101, B11010, B10101, B11010, B01110};
    byte image25[8] = {B00000, B00000, B00000, B10000, B10000, B00000, B00000, B00000};
    byte image23[8] = {B01101, B01010, B01101, B00111, B00000, B00000, B00000, B00000};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011};
    byte image08[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B10000};

    lcd.createChar(0, image24);
    lcd.createChar(1, image25);
    lcd.createChar(2, image23);
    lcd.createChar(3, image07);
    lcd.createChar(4, image08);

    lcd.setCursor(7, 1);
    lcd.write(byte(0));
    lcd.setCursor(8, 1);
    lcd.write(byte(1));
    lcd.setCursor(6, 1);
    lcd.write(byte(2));
    lcd.setCursor(6, 0);
    lcd.write(byte(3));
    lcd.setCursor(7, 0);
    lcd.write(byte(4));
}

void image06()
{
    lcd.clear();

    byte image08[8] = {B00000, B00100, B01010, B01010, B10001, B00011, B00110, B01100};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00001, B00010, B00010, B00001};
    byte image09[8] = {B00000, B00000, B10000, B11000, B00000, B00000, B11000, B00100};
    byte image24[8] = {B00100, B00100, B00011, B00000, B00000, B00000, B00000, B00000};
    byte image25[8] = {B10000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};

    lcd.createChar(0, image08);
    lcd.createChar(1, image07);
    lcd.createChar(2, image09);
    lcd.createChar(3, image24);
    lcd.createChar(4, image25);

    lcd.setCursor(7, 0);
    lcd.write(byte(0));
    lcd.setCursor(6, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 1);
    lcd.write(byte(3));
    lcd.setCursor(8, 1);
    lcd.write(byte(4));
}

void image07()
{
    lcd.clear();

    byte image24[8] = {B10101, B01110, B01110, B00100, B10101, B01110, B00100, B11111};
    byte image08[8] = {B00000, B00100, B01010, B01010, B10001, B00011, B00110, B01100};
    byte image07[8] = {B00000, B00000, B00000, B00000, B00001, B00010, B00010, B00001};
    byte image09[8] = {B00000, B00000, B10000, B11000, B00000, B00000, B00000, B00000};

    lcd.createChar(0, image24);
    lcd.createChar(1, image08);
    lcd.createChar(2, image07);
    lcd.createChar(3, image09);

    lcd.setCursor(7, 1);
    lcd.write(byte(0));
    lcd.setCursor(7, 0);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(8, 0);
    lcd.write(byte(3));
}

//INSECT
void InsectAnimation()
{
    byte stepA1[8] = {0x0F,  0x0F,  0x06,  0x0A,  0x12,  0x12,  0x09,  0x00};
  byte stepA2[8] = {0x18,  0x1e,  0x18,  0x10,  0x10,  0x08,  0x04,  0x00};
  byte stepA3[8] = {0x00,  0x09,  0x12,  0x12,  0x0A,  0x07,  0x0F,  0x0F};
  byte stepA4[8] = {0x00,  0x04,  0x08,  0x10,  0x10,  0x18,  0x1e,  0x18};
  byte stepA5[8] = {0x0F,  0x0F,  0x07,  0x0A,  0x12,  0x12,  0x12,  0x00};
  byte stepA6[8] = {0x18,  0x1E,  0x18,  0x10,  0x10,  0x08,  0x08,  0x00};
  byte stepA7[8] = {0x00,  0x12,  0x12,  0x12,  0x0A,  0x07,  0x0F,  0x0F};
  byte stepA8[8] = { 0x00,  0x08,  0x08,  0x10,  0x10,  0x18,  0x1E,  0x18};
  lcd.createChar(1, stepA1);
  lcd.createChar(2, stepA2);
  lcd.createChar(3, stepA3);
  lcd.createChar(4, stepA4);
  lcd.createChar(5, stepA5);
  lcd.createChar(6, stepA6);
  lcd.createChar(7, stepA7);
  lcd.createChar(8, stepA8);
  lcd.clear();
  delay(1000);
  for (int i =-1; i<16 ; i=i+2)
  {
    int j = i+1;
    int k =j+1;
 
    lcd.setCursor(i,1);
    lcd.write(1);
    lcd.setCursor(j,1);
    lcd.write(2);
    lcd.setCursor(i,0);
    lcd.write(3);
    lcd.setCursor(j,0);
    lcd.write(4);
    delay(500);
 
    lcd.clear ();
    lcd.setCursor(j,1);
    lcd.write(5);
    lcd.setCursor(k,1);
    lcd.write(6);
    lcd.setCursor(j,0);
    lcd.write(7);
    lcd.setCursor(k,0);
    lcd.write(8);
    delay(500);
    lcd.clear ();
  }
}