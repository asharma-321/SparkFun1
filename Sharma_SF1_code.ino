/* 
SparkFun Lab 1 Homework 
A.Sharma
paayushisharad@gmail.com
Traffic Light
Parts taken from Arduino IDE Sample - Blink and RGB. Additional help from FYELIC (Matthew 2nd year MechE student)
A car traffic light (red, yellow and green LEDs) and pedestrian light (RGB LED) 
along with a push button, to request access to cross the road.
*/

const int ButtonPin = 2;  // pushbutton 1 pin

const int RedPin =  13;    // LED pin
const int YellowPin = 12;
const int GreenPin = 11;

const int RGB_Red = 7;
const int RGB_Green = 6;
const int RGB_Blue = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ButtonPin, INPUT);
  
  pinMode(GreenPin, OUTPUT);
  pinMode(YellowPin, OUTPUT);
  pinMode(RedPin, OUTPUT);

  pinMode(RGB_Green, OUTPUT);
  pinMode(RGB_Blue, OUTPUT);
  pinMode(RGB_Red, OUTPUT);

}

void loop() {
  //Traffic light
  greenLight();
  yellowLight();
  redLight();

  

}

//Green Light function
void greenLight(){
  digitalWrite(RedPin, LOW);
 digitalWrite(GreenPin, HIGH);
 //delay(5000); // only needed for part 1 and 2
 for(int i=0; i<5000; i++) // will check if button was pressed for 5 seconds
  {
    if (digitalRead (ButtonPin) == LOW) //if button pressed, then break out of loop
    {
      break;
    } 
    else //other wise wait a millisecond and then go through loop again
    {
      delay(1);
    }
  }
}

  //Yellow Light
 void yellowLight(){
 digitalWrite(GreenPin, LOW);
 digitalWrite(YellowPin, HIGH);
 delay(2500);
 }
 
//Red Light
void redLight(){
 digitalWrite(YellowPin, LOW);
 digitalWrite(RedPin, HIGH);
 
 //White RGB for 3 seconds
 digitalWrite(RGB_Red, HIGH);
  digitalWrite(RGB_Green, HIGH);
  digitalWrite(RGB_Blue, HIGH);
  delay(3000);
  
  //Blinking Orange RGB for 2 seconds
  for (int i = 0; i<=8; i++){
  analogWrite(RGB_Red, 255);
  analogWrite(RGB_Green, 10);
  analogWrite(RGB_Blue, 0);
  delay(250); //0.25 seconds blink
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Green, 0);
  analogWrite(RGB_Blue, 0);
  delay(250);
  }
  
  //Continuous Orange RGB
  analogWrite(RGB_Red, 255);
  analogWrite(RGB_Green, 10);
  analogWrite(RGB_Blue, 0);
  delay(2500);
  analogWrite(RGB_Red, 0);
  analogWrite(RGB_Green, 0);
  analogWrite(RGB_Blue, 0);
  delay(250);
}
