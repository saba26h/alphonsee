#include "Servo.h"
#include "TCS34725.h"
#include "Wire.h"
Servo servo;
TCS34725 tcs;
const int pwm = 2 ; //initializing pin 2 as pwm
const int in_1 = 26 ;
const int in_2 = 24;
void setup(void)
{
  pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
   pinMode(in_1,OUTPUT) ; //Logic pins are also set as output
   pinMode(in_2,OUTPUT) ;
  servo.attach(5);
    Serial.begin(115200);
    Wire.begin();
    if (!tcs.attach(Wire))
        Serial.println("ERROR: TCS34725 NOT FOUND !!!");
    tcs.integrationTime(10); // ms
    tcs.gain(TCS34725::Gain::X01);
    // set LEDs...
}
void loop(void)
{
  analogWrite(pwm,100) ;
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
    if (tcs.available())
    {
        static uint32_t prev_ms = millis();
       TCS34725::RawData raw = tcs.raw();
        Serial.print("Raw R      : "); Serial.println(raw.r);
        Serial.print("Raw G      : "); Serial.println(raw.g);
        Serial.print("Raw B      : "); Serial.println(raw.b);
       if(raw.r>raw.b&&raw.r>raw.g){
        Serial.println("red");
         servo.write(135);
         delay(2000);
         tcs.clearInterrupt();
       
       }
       else{
        servo.write(90);
        delay(10);
       }
       
       
      if(raw.b>raw.r&&raw.b>raw.g){
        Serial.println("blue");
         servo.write(45);
         delay(2000);
         tcs.clearInterrupt();
       
       }
       
       else{
        servo.write(90);
        delay(10);
       }
        prev_ms = millis();
    }
}
