/*
* I, Cole Spiers, student number 000389039,
* certify that this material is my original work.
* No other person's work has been used without due acknowledgment
* and I have not made my work available to anyone else.
* 2022-09-26
*/
#include <Arduino.h> 
 
void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
 
 // configure pin D5 as digital input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);

  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);
 
  // set default PWM range
  analogWriteRange(1023);
}

int current;  //this is the current state of the light
int c = 0;    // this is the count
int p = HIGH; //THE old button statee

void loop()
{
  current = digitalRead(D5);

  //if the current light is on and the preveious was off then
  //add 1 to the count
  if(current == LOW && p == HIGH)
  {
    c++;
  }

  //the previous button equals the count
  p = current;
  
  //Serial.println(c);

  //if c is not an even number
  if(c%2 !=0)
  {
    //wrote the current count to the LED
    //and then read the variable resistor
    analogWrite(D4, analogRead(A0));
  }

  else
  {
    //set the count to 2
    c = 2;
    //write the light as off
    digitalWrite(D4, HIGH);
  }
  //delay of 10ms
  delay(1);
}