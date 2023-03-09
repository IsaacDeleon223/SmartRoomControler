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


int irsensor= A2;
int sensdata;
const int MYWEMO=4;

const int button=D3;
bool buttonState; 
bool toggler;
int color;


 const int PIXELPIN = D8 ; // Pin the NeoPixels are connected to
 const int PIXELCOUNT = 16; // Total number of NeoPixels
int pixelnumber; 

bool up;


Adafruit_NeoPixel pixel ( PIXELCOUNT , PIXELPIN , WS2812B ); 



SYSTEM_MODE(SEMI_AUTOMATIC);  //MANUEL
SYSTEM_THREAD(ENABLED);


void setup(){
  pixel . begin () ;
pixel . show () ;
Wire.begin ();     
  Serial.begin(9600);



  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);


    display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.printf("Secured");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setTextSize(1);

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
 for (pixelnumber=0; pixelnumber<=PIXELCOUNT; pixelnumber++) {
    pixel . setPixelColor (pixelnumber , green); 
 pixel . setBrightness (15) ;
pixel . show () ;

sensdata=analogRead(irsensor);
digitalWrite(A5,HIGH);
Serial.printf("%i\r",sensdata);

buttonState=digitalRead(button);
if (buttonState){
toggler=!toggler;
}
if(toggler){
switchON(MYWEMO);
setHue(BULB5,true,HueGreen,255,255);
setHue(BULB1,true,HueGreen,255,255);
setHue(BULB2,true,HueGreen,255,255);
setHue(BULB3,true,HueGreen,255,255);
setHue(BULB4,true,HueGreen,255,255);
}
else{
//switchOFF(MYWEMO);
setHue (BULB5,false,HueGreen,255,255);
setHue (BULB1,false,HueGreen,255,255);
setHue (BULB2,false,HueGreen,255,255);
setHue (BULB3,false,HueGreen,255,255);
setHue (BULB4,false,HueGreen,255,255);
}

}


}