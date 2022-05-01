//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define BLUE 3
#define GREEN 5
#define RED 6

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

int redValue = 0;
int greenValue = 255;
int blueValue = 0;

void loop() {

  digitalWrite(LED_BUILTIN, LOW);
 
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
 
  if (a < 15)
  {
    greenValue = 0;
    redValue = 255;
    blueValue = 0;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);    
  }
  else if (a < 30)
  {
    greenValue = 255;
    redValue = 255;
    blueValue = 0;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
  }
  else if (a > 140)
  {
    greenValue = 0;
    redValue = 0;
    blueValue = 255;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
  }
  else
  {
    greenValue = 255;
    redValue = 0;
    blueValue = 0;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
  }
}
