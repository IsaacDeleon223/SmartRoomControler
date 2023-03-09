/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/pstee/Documents/IoT/SmartRoomControler/smart_room_test/smartroom/src/smartroom.ino"
/*
 * Project smartroom
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
#line 8 "c:/Users/pstee/Documents/IoT/SmartRoomControler/smart_room_test/smartroom/src/smartroom.ino"
int sensdata; 
int irsenPIN= A2;



SYSTEM_MODE(SEMI_AUTOMATIC);
void setup(){
pinMode (A2, INPUT);
}


void loop(){

sensdata=analogRead(irsenPIN);



digitalWrite(A5,HIGH);
Serial.printf("%i\r",sensdata);
}