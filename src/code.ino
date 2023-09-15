const int pwm = 2 ; //initializing pin 2 as pwm
const int in_1 = 26 ;
const int in_2 = 24;
#include <Servo.h>
#include "TCS34725.h"
#include "Wire.h"
TCS34725 tcs;
const int SERVO_PIN = 5;
// constants won't change
const int TRIG_PIN  = 4;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 3;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
 // Arduino pin connected to Servo Motor's pin
const int DISTANCE_THRESHOLD = 90; // centimeters
const int TRIG_PIN1  = 10;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN1  = 11;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int TRIG_PIN2  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN2  = 7;  // Arduino pin connected to
int time =0;
int corner=0;

Servo servo; // create servo object to control a servo

// variables will change:
float duration_us, distance_cm,duration_us1, distance_cm1,duration_us2, distance_cm2;
void setup() {
   pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
   pinMode(in_1,OUTPUT) ; //Logic pins are also set as output
   pinMode(in_2,OUTPUT) ;
   Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(TRIG_PIN1, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN2, INPUT);
  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object
   Serial.begin(115200);
    Wire.begin();
    if (!tcs.attach(Wire))
        Serial.println("ERROR: TCS34725 NOT FOUND !!!");
    tcs.integrationTime(10); // ms
    tcs.gain(TCS34725::Gain::X01);
    // set LEDs...
  servo.write(90);
   }
void loop() { 
  analogWrite(pwm,170) ;
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
        corner=0;
       while(corner<12){
  if(distance_cm < DISTANCE_THRESHOLD){
    servo.write(160); // rotate servo motor to 90 degree
    delay(100);
    }
    else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }
  
    if(distance_cm2 < 40){
    servo.write(120); // rotate servo motor to 90 degree
    delay(100);
    }
  else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }
 if(distance_cm1 < 20){
    servo.write(60); // rotate servo motor to 90 degree
    delay(100);
    }
  else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }
  

       }
       corner++;
       }
       if(raw.b>raw.r&&raw.b>raw.g){
       while(corner<12){
  if(distance_cm < DISTANCE_THRESHOLD){
    servo.write(20); // rotate servo motor to 90 degree
    delay(100);
    }
    else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }
  
    if(distance_cm2 < 40){
    servo.write(60); // rotate servo motor to 90 degree
    delay(100);
    }
  else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }
 if(distance_cm1 < 20){
    servo.write(120); // rotate servo motor to 90 degree
    delay(100);
    }
  else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }
  

       }
       corner++;
       }
       
      
        prev_ms = millis();
    
   //For Clock wise motion , in_1 = High , in_2 = Low
   
    }
   
 

  
  analogWrite(pwm,130) ;
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,LOW) ;
   delay (100000);
   
  
}
