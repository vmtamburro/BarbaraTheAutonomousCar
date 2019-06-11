/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
* 
* Modified by Alexandra and Victoria Tamburro
*
*/

//Setup the Motor Pins
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

const int speed = 200;

//Setup Front L Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinFL = 23;
  const int echoPinFL = 22;
  // defines variables
  long durationFL;
  int distanceFL;
  long durationFL2;
  int distanceFL2;
  long durationFL3;
  int distanceFL3;

//Setup Front R Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinFR = 25;
  const int echoPinFR = 24;
  // defines variables
  long durationFR;
  int distanceFR;
  long durationFR2;
  int distanceFR2;
  long durationFR3;
  int distanceFR3;

//Setup Back R Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinBR = 27;
  const int echoPinBR = 26;
  // defines variables
  long durationBR;
  int distanceBR;
  long durationBR2;
  int distanceBR2;
  long durationBR3;
  int distanceBR3;
  

//Setup Back L Sensor Pin Numbers and Variables
  // defines pins numbers
  const int trigPinBL = 29;
  const int echoPinBL = 28;
  // defines variables
  long durationBL;
  int distanceBL;
  long durationBL2;
  int distanceBL2;
  long durationBL3;
  int distanceBL3;



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
  delay(500);

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
  delay(500);
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
  delay(500);
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
  delay(500);

}


void stop()
{
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}




void setup()
{
//Sets up Front Left Sensor
  pinMode(trigPinFL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinFL, INPUT); // Sets the echoPin as an Input

//Sets up Front Right Sensor
  pinMode(trigPinFR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinFR, INPUT); // Sets the echoPin as an Input

//Sets up Back Right Sensor
  pinMode(trigPinBR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinBR, INPUT); // Sets the echoPin as an Input

//Sets up Back Left Sensor
  pinMode(trigPinBL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinBL, INPUT); // Sets the echoPin as an Input

  Serial.begin(9600); // Starts the serial communication
}




void loop()
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
    digitalWrite(trigPinFL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinFL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationFL2 = pulseIn(echoPinFL, HIGH);
  // Calculating the distance
  distanceFL2= durationFL2*0.034/2;
    digitalWrite(trigPinFL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinFL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationFL3 = pulseIn(echoPinFL, HIGH);
  // Calculating the distance
  distanceFL3= durationFL3*0.034/2;

  distanceFL = (distanceFL + distanceFL2 + distanceFL3) / 3;


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
  
    digitalWrite(trigPinFR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinFR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationFR2 = pulseIn(echoPinFR, HIGH);
  // Calculating the distance
  distanceFR2= durationFR*0.034/2;
    digitalWrite(trigPinFR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinFR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationFR3 = pulseIn(echoPinFR, HIGH);
  // Calculating the distance
  distanceFR3= durationFR3*0.034/2;

  distanceFR = (distanceFR + distanceFR2 + distanceFR3) / 3;

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
  
    digitalWrite(trigPinBR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinBR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationBR2 = pulseIn(echoPinBR, HIGH);
  // Calculating the distance
  distanceBR2= durationBR2*0.034/2;
    digitalWrite(trigPinBR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinBR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationBR3 = pulseIn(echoPinBR, HIGH);
  // Calculating the distance
  distanceBR2= durationBR3*0.034/2;

  distanceBR = (distanceBR + distanceBR2 + distanceBR3) / 3;

  Serial.print("Distance: ");
Serial.println(distanceBR);
  
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
  
    digitalWrite(trigPinBL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinBL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationBL2 = pulseIn(echoPinBL, HIGH);
  // Calculating the distance
  distanceBL2= durationBL2 * 0.034/2;
    digitalWrite(trigPinBL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinBL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationBL3 = pulseIn(echoPinBL, HIGH);
  // Calculating the distance
  distanceBL3= durationBL3*0.034/2;

  distanceBL = (distanceBL + distanceBL2 + distanceBL3) / 3;
  


  if(distanceBL <= 5 && distanceBL >= 0)
  {
      right();
  }

  if(distanceFR <= 5 && distanceFR >= 0)
  {
    left();
    
  }


  if (distanceFL <= 5 && distanceFL >= 0)
  {
     if(distanceFR <=5 && distanceFR >= 0)
     {
        backward();
     }
      
  }

  if(distanceBL <= 5 && distanceBL >= 0)
  {
    if(distanceBR <= 5 && distanceBR >= 0)
    {
      forward();
    }
  }
  else
  {
      stop();
  }



}
