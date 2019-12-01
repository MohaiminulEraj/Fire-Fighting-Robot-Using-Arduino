#include <Servo.h>
Servo myservo;

  const int ENA = 3;  //PWM
  const int IN1 = 7;
  const int IN2 = 8;
  const int ENB = 6;   //PWM
  const int IN3 = 2;
  const int IN4 = 4;
  const int a = 74;
  const int b = 74;

  const int pump1 = 12;
  const int pump2 = 13;
  const int pumpENA = 11;

/*-------defining Inputs------*/
#define Forward_S A1 //forward sensor
#define Left_S A2      // left sensor
#define Right_S A3    // right sensor
#define trigPin A4
#define echoPin A5

void setup()
{
  Serial.begin(9600);
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pumpENA, OUTPUT);
  myservo.attach(9);
  myservo.write(90);
  delay(2000);
}


void loop()
{
 // int sum;

  int distanceR = 0;
  int distanceL = 0;
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  delay(40);

     /*
   if(analogRead(A0) <= 45){
      digitalWrite(IN1, LOW);   // Backward
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, a);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, b);
      }
   */
   // Serial.println("Out_Of_Loop: ");
    digitalWrite(pump1,LOW);
    digitalWrite(pump2,LOW);
    analogWrite(pumpENA, 0);

    Serial.println(analogRead(A0));
    delay(400);
    /*
    for(int i=0; i<10; i++){
    sum=0;
    sum=analogRead(A0);
    sum+=sum;
    delay(100);
    */


    while (digitalRead(Left_S) == 1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1)  //If Fire detected all sensors
      {
    // Move Forward
        digitalWrite(pump1,HIGH);
        digitalWrite(pump2,LOW);
        analogWrite(pumpENA, 155);
      //  delay(100);
       //analogRead(A0);
        //Forward Code was here in this line
    //delay(300);
 //   Serial.print("L-F-S: ");
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, 0);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, 0);
  /*
      while(analogRead <= 139 ){                   //Do not move the robot
        Serial.print(" STOP=> ");
        Serial.println(analogRead(A0));
        digitalWrite(pump1,HIGH);
        digitalWrite(pump2,LOW);
        analogWrite(pumpENA, 127);
        delay(200);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, 0);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, 0);

      if(analogRead(A0) < 102){
        digitalWrite(pump1,HIGH);
        digitalWrite(pump2,LOW);
        analogWrite(pumpENA, 127);
        Serial.print(" GOing Back=> ");
        Serial.println(analogRead(A0));
        delay(200);
        digitalWrite(IN1, LOW);   // Backward
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, a);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, b);
      } */
      if(digitalRead(Right_S)==0 || digitalRead(Left_S)==0) { //|| digitalRead(Forward_S)==0
        //if (digitalRead(Right_S)==0 || digitalRead(Forward_S) ==0 || digitalRead(Left_S) == 0) { }
        digitalWrite(pump1,LOW);
        digitalWrite(pump2,LOW);
        analogWrite(pumpENA,0);

        digitalWrite(IN1, LOW);   // Backward
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, a);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, b);
        delay(100);
        break;
        }
      }

    if(digitalRead(Forward_S) == 1 && digitalRead(Right_S) == 1 && digitalRead(Left_S) == 0){
      digitalWrite(IN1, HIGH);   //RIGHT
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, b);
    }

    else if(digitalRead(Forward_S) == 1 && digitalRead(Left_S) == 1 && digitalRead(Right_S) == 0){
      digitalWrite(IN1, LOW);  //LEFT
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);
    }

    else if(digitalRead(Forward_S) == 1 && digitalRead(Right_S) == 0 && digitalRead(Left_S) == 0){

    //delay(300);
  //  Serial.print("F: ");
   // Serial.println(analogRead(A0));

    while(analogRead(A0) <= 900){                   //Do not move the robot

      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);
      digitalWrite(pump1, LOW);
      digitalWrite(pump2,LOW);
      analogWrite(pumpENA,0);
      if(analogRead(A0) <= 170) {
        break;
      }
      /*
      else if(digitalRead(Forward_S) == 1 && digitalRead(Right_S) == 1) {
        digitalWrite(IN1, HIGH);  //RIGHT
        digitalWrite(IN2, LOW);
        analogWrite(ENA, a);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, b);
        delay(70);
        break;
      }
       else if(digitalRead(Forward_S) == 1 && digitalRead(Left_S) == 1) {
        digitalWrite(IN1, LOW);  //LEFT
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, a);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, b);
        delay(70);
        break;
      }
  */
//      for(int i = 0; i < 10; i++){
//        sum=sum+ analogRead(A0);
//      }
     // sum = sum/10;

      }
        // digitalWrite(pump,0);
    }

   //   Serial.print("FClose: ");
   //   Serial.println(analogRead(A0));


    else if (digitalRead(Forward_S) == 0 && digitalRead(Right_S) == 0 && digitalRead(Left_S) == 0 && distance > 27) //If Fire not detected all sensors
    {
      digitalWrite(pump1, LOW);
      digitalWrite(pump2,LOW);
      analogWrite(pumpENA,0);
      Serial.println("NoFire");
    //Move the robot forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);

      }

  else if ( digitalRead(Forward_S) == 0 && digitalRead(Right_S) == 0 && digitalRead(Left_S) == 0 && distance <= 26 ) //If Fire not detected all sensors
    {
    //  Serial.print(" DISS<22: ");
      //Serial.println(distance);
            //Stop();
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(ENA, 0);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 0);
      delay(300);
      // back();
      digitalWrite(IN1, LOW);   // Backward
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, a);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, b);
      delay(300);
     //Stop();
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(ENA, 0);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 0);
      delay(300);
      distanceR = lookRight();
      delay(300);
      distanceL = lookLeft();
      delay(300);

//  Serial.print(distanceR);
//  Serial.print(" <=R == L=> ");
//  Serial.print(distanceL);


    if(distanceR >= distanceL)
  {   // turnRight();
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, b);
      delay(1000);
      // then Forward()
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);

 //   Serial.println(" Turn RIGHT ");
//    Serial.print(distanceR);
//    Serial.print(" R===L " );
//    Serial.println(distanceL);

    //Stop();
  }else
  {
    //turnLeft();
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);
      delay(1000);
      //then Forward();
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);
  // Serial.println(" Turn LEFT ");

    //Stop();
  }

    myservo.write(90);
    }




    else if (digitalRead(Right_S) == 1)//(digitalRead(Left_S) == 0) //&& digitalRead(Right_S) == 1 && digitalRead(Forward_S) == 1) //If Fire is to the right
    {
    //  Serial.println("StraightRightFire");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, a);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, b);

    }


    else if (digitalRead(Left_S) == 1) //(digitalRead(Right_S) == 0) //&& digitalRead(Left_S) == 1 && digitalRead(Forward_S) == 1) //If Fire is to the left
    {
   //   Serial.println("StraightLefttFire");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, a);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, b);

    }



//delay(300); //Slow down the speed of robot
  }



int lookRight()
{
    long durationR, distanceR;
    myservo.write(20);    //45
    delay(500);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    durationR=pulseIn(echoPin, HIGH);
    distanceR =(durationR/2)/29.1;
    delay(100);
    myservo.write(90);     //115
    return distanceR;
}

int lookLeft()
{
    long durationL, distanceL;
    myservo.write(160);
    delay(500);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    durationL=pulseIn(echoPin, HIGH);
    distanceL =(durationL/2)/29.1;
    delay(100);
    myservo.write(90);   //115
    return distanceL;

}

/*
int sensorValue(){
   for(int i = 0; i < 10; i++){
        sum=sum+ analogRead(A0);
      }
      return (sum/10);

} */
