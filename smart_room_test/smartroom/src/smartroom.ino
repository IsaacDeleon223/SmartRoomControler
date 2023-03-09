/*
 * Project smartroom
 * Description:
 * Author:
 * Date:
 */

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