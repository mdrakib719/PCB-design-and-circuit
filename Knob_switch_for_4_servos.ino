/* 
 Controlling servo position using potentiometers (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
 modified by Armando padilla on 19 Apr 2016 added 3more servos and a second
 control method with buttons
 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 4;     // the number of the pushbutton pin
const int buttonPin3 = 7;     // the number of the pushbutton pin
const int buttonPin4 = 8;     // the number of the pushbutton pin
const int buttonPin5 = 13;

int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;


              // uncomment following to restore pot functions
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
int potpin1 = 1;
int val1;
int potpin2 = 2;
int val2;
int potpin3 = 3;
int val3;    // variable to read the value from the analog pin

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(12);

   // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
 
}

void loop() { 
        // Uncomment th following val statements to restore pot functions
  val = analogRead(potpin); //reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 180);
  val1 = analogRead(potpin1);
  val1 = map(val1, 0, 1023, 0, 180);
  val2 = analogRead(potpin2);
  val2 = map(val2, 0, 1023, 0, 180);
  val3 = analogRead(potpin3);
  val3 = map(val3, 0, 1023, 0, 180);  //scale it to use with the servo(value between 0and180) 
  
  myservo.write(val);   // sets the servo position according to the scaled value 
  myservo2.write(val1);
  myservo3.write(val2);
  myservo4.write(val3);

      // make all following statements "comments" if above statements are uncommented:
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value:
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  
 if (buttonState == HIGH) {  //  move myservo back to flex pos.:
   myservo.write(val);}  // sets the servo position according to the scaled value 
  else {myservo.write(90);}  //  move myservo back to center pos.:
    
 if (buttonState2 == HIGH) {
    myservo2.write(val1);}
  else {myservo2.write(90);}
   
 if (buttonState3 == HIGH) {
    myservo3.write(val2);}
  else {myservo3.write(90);}

 if (buttonState4 == HIGH) {
   myservo4.write(val3);}
  else {myservo4.write(90);}

  if (buttonState5 == HIGH) {
    myservo.write(val);
     delay(250);
    myservo2.write(val);
     delay(500);
    myservo3.write(val);
     delay(820);
    myservo4.write(val);
     delay(1200);} // waits for the servo to get there
  else {(val = 90);} 
       delay(25);
}

