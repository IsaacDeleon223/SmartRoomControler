/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/pstee/Documents/IoT/SmartRoomControler/smart_room_test/src/smart_room_test.ino"

#include <wemo.h>
#include <IoTClassroom_CNM.h>
#include <Encoder.h>
#include "Adafruit_SSD1306.h"
#include "colors.h"
#include <neopixel.h>

void setup();
void loop();
#line 9 "c:/Users/pstee/Documents/IoT/SmartRoomControler/smart_room_test/src/smart_room_test.ino"
#define OLED_RESET -1

Adafruit_SSD1306 display(OLED_RESET);

const int BULB5=5;
const int BULB4=4;
const int BULB3=3;
const int BULB2=2;
const int BULB1=1;
const int button=D3;
const int PIXELPIN = D8 ; // Pin the NeoPixels are connected to
const int PIXELCOUNT = 16; // Total number of NeoPixels
const int MYWEMO=4;

const int button2=A1;
bool buttonState2; 
bool toggler2;



int color;
int pixelnumber; 
int irsensor= A2;
int sensdata;

bool buttonState; 
bool toggler;
bool up;

Adafruit_NeoPixel pixel ( PIXELCOUNT , PIXELPIN , WS2812B ); 

SYSTEM_MODE(MANUAL);  //MANUEL
//SYSTEM_THREAD(ENABLED);

void setup(){
  pixel . begin () ;
pixel . show () ;
Wire.begin ();     
  Serial.begin(9600);

     pinMode(A1,INPUT); 

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

pinMode (A2, INPUT);
     pinMode( D3, INPUT_PULLDOWN ) ; 
    Serial.begin(9600);
  waitFor(Serial.isConnected,15000);
  WiFi.on();
  WiFi.setCredentials("IoTNetwork");
  WiFi.connect();
   while(WiFi.connecting()) {
     Serial.printf(".");
  }
  delay(1000);
 Serial.printf("\n\n");

}



void loop(){

if (sensdata>3000){
  // display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 for (pixelnumber=0; pixelnumber<=PIXELCOUNT; pixelnumber++) {
    pixel . setPixelColor (pixelnumber , red); 
    pixel . setBrightness (30) ;
    pixel . show () ;
 }
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.printf("Unstable!");
display.setTextColor(BLACK, WHITE); // 'inverted' text
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,35);
display.printf("tripped proceed with caution");
display.display();      
Serial.printf("***************************************************unstablw\n\n\n");
    buttonState=digitalRead(button);


    //switchON(MYWEMO);
      setHue(BULB5,true,HueRed,255,255);
      setHue(BULB1,true,HueRed,255,255);
      setHue(BULB2,true,HueRed,255,255);
      setHue(BULB3,true,HueRed,255,255);
      setHue(BULB4,true,HueRed,255,255);
    
   

 }
else{
   for (pixelnumber=0; pixelnumber<=PIXELCOUNT; pixelnumber++) {
    pixel . setPixelColor (pixelnumber , green); 
    pixel . setBrightness (30) ;
    pixel . show () ;
 }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.printf("Secured!");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,35);
  display.printf("active and or idle");
  display.display();
  Serial.printf("*****************************************secured\n\n\n");
  buttonState=digitalRead(button);
     setHue(BULB5,true,HueGreen,255,255);
      setHue(BULB1,true,HueGreen,255,255);
      setHue(BULB2,true,HueGreen,255,255);
      setHue(BULB3,true,HueGreen,255,255);
      setHue(BULB4,true,HueGreen,255,255);
              sensdata=analogRead(irsensor);

    }

    
    sensdata=analogRead(irsensor);
    Serial.printf("sensdata%d\n\n",sensdata);
    digitalWrite(A5,HIGH);
    Serial.printf("%i\r\n\n",sensdata);


    buttonState2=digitalRead(button2);
    if (buttonState2){
      Serial.printf("\n\nbutton2down\n\n");
     toggler2=!toggler2;
    }
    if(toggler2){
      switchON(MYWEMO);
      Serial.printf("\n\ntogglertrue\n\n"); 
    }
    else{
      switchOFF(MYWEMO);
      Serial.printf("\n\ntogglerfalse\n\n"); 

    }
}

 



