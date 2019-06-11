#include <SoftwareSerial.h>
#include<SPI.h>
#include<Servo.h>


//Setup Front L Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinFL = 23;
  const int echoPinFL = 22;
  // defines variables
  long durationFL;
  int distanceFL;

//Setup Front R Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinFR = 25;
  const int echoPinFR = 24;
  // defines variables
  long durationFR;
  int distanceFR;

//Setup Back R Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinBR = 27;
  const int echoPinBR = 26;
  // defines variables
  long durationBR;
  int distanceBR;

//Setup Back L Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinBL = 29;
  const int echoPinBL = 28;
  // defines variables
  long durationBL;
  int distanceBL;

// connect motor controller pins to Arduino digital pins
int speed = 200;

SoftwareSerial esp8266Module(10, 11);
const char* ssid = "Hackathon2019";
const char* password = "2019_HackAthon!";

bool breakOut = false;
int wifiStatus = 0;

// motor one
//Left Side of the Car
int enA = 10;
int in1 = 9;
int in2 = 8;

//Right Side of the Car
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

//for the ultrasonic sensors
int const trigPinFR = 25;
int const echoPinFR = 24;

int const trigPinFL = 23;
int const echoPinFL = 22;

int const trigPinBR = 27;
int const echoPinBR = 26;

int const trigPinBL = 29;
int const echoPinBL = 28;


void setup()
{


  esp8266Module.begin(115200);
  delay(2000);
  Serial.println('\n');

  
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  


  //for the ultrasonic sensors
  pinMode(trigPinFL, OUTPUT); // trig pin will have pulses output
  pinMode(echoPinFL, INPUT); // echo pin should be input to get pulse width

  pinMode(trigPinFR, OUTPUT); // trig pin will have pulses output
  pinMode(echoPinFR, INPUT); // echo pin should be input to get pulse width

  pinMode(trigPinBL, OUTPUT); // trig pin will have pulses output
  pinMode(echoPinBL, INPUT); // echo pin should be input to get pulse width

  pinMode(trigPinBR, OUTPUT); // trig pin will have pulses output
  pinMode(echoPinBR, INPUT); // echo pin should be input to get pulse width

  

  Serial.begin(9600);

}

void forward()
{
    //Moves Car Forward
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speed);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, speed);
  delay(2000);

}

void backward()
{
   //Moves Car Backward
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  

  analogWrite(enA, speed);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 

  analogWrite(enB, speed);
  delay(2000);
}


void right()
{
  //Turn Car Right
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enA, speed);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enB, speed);
  delay(2000);
}



void left()
{
    //Turn Car Left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enA, speed);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enB, speed);
  delay(2000);

}


void stop()
{
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void calculate()
{
//Starts action for Front Left Sensor
  // Clears the trigPin
  digitalWrite(trigPinFL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinFL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationFL = pulseIn(echoPinFL, HIGH);
  // Calculating the distance
  distanceFL= durationFL*0.034/2;

//Starts action for Front Right Sensor
  // Clears the trigPin
  digitalWrite(trigPinFR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinFR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationFR = pulseIn(echoPinFR, HIGH);
  // Calculating the distance
  distanceFR= durationFR*0.034/2;

//Starts action for Back Right Sensor
  // Clears the trigPin
  digitalWrite(trigPinBR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinBR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationBR = pulseIn(echoPinBR, HIGH);
  // Calculating the distance
  distanceBR= durationBR*0.034/2;
  
//Starts action for Back Left Sensor
  // Clears the trigPin
  digitalWrite(trigPinBL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinBL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationBL = pulseIn(echoPinBL, HIGH);
  // Calculating the distance
  distanceBL= durationBL*0.034/2;
  
}

navigate()
{
  if(distanceBL <= 10 && distanceBL >= 0)
  {
      right();
  }

  if(distanceFR <= 10 && distanceFR >= 0)
  {
    left();
    
  }


  if (distanceFL <= 10 && distanceFL >= 0)
  {
     if(distanceFR <=10 && distanceFR >= 0)
     {
        backward();
     }
      
  }

  if(distanceBL <= 10 && distanceBL >= 0)
  {
    if(distanceBR <= 10 && distanceBR >= 0)
    {
      forward();
    }
  }
  else
  {
      stop();
  }

}

void loop()
{

  calculate();
  navigate();
  
}
