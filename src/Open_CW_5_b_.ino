#include <Pixy2.h>
#include <Servo.h>
#include "Wire.h"
#include <MPU6050_light.h>  //for GY-521

////////////FOR GYRO////////////////
MPU6050 mpu(Wire);
unsigned long timer = 0;
int gyroZ = 0;
int stableZ = 0;
int z = 0;
////////////FOR PIXY////////////////
Pixy2 pixy;
int orangeX;
int orangeY;
int orangeWidth;
int orangeHeight;

int blueX;
int blueY;
int blueWidth;
int blueHeight;
///////////FOR SERVO///////////////
Servo myServo;
int servoPin = 9;

//////////FOR ULTRASONIC SENSORS//////////
int frontEcho = 6;
int frontTrig = 7;
int FD;
int fduration;

int rightEcho = 14;
int rightTrig = 15;
int LD;
int lduration;

int leftEcho = 16;
int leftTrig = 17;
int RD;
int rduration;


///////////////FOR MOTORS///////////////
int enB = 3;
int in3 = 4;
int in4 = 5;

int sped = 120;

//////////////PUSHBUTTON///////////////
int BUTTON_PIN = 2;
int buttonState = 0;


/////////////OTHER VARIABLES///////////
int center;
int turns = 0;
int flagg;
int turn_flagg = 1;
long int Full;
long int Period;
int lock = 0;
int lock_right = 0;
int blueLock = 1;

//////////////CUSTOM DEFINED FUNCTIONS//////////////////
void straight() {
  myServo.write(83);
}

int left(int x = 150) {
  myServo.write(x);
}

int right(int y = 30) {
  myServo.write(y);
}

void front_dist() {
  digitalWrite(frontTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(frontTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTrig, LOW);
  fduration = pulseIn(frontEcho, HIGH);
  FD = (fduration / 2) * 0.0343;
  Serial.print("Front:- ");
  Serial.println(FD); //determining the distance in front of the vehicle
  //  return FD;
}

void left_dist() {
  digitalWrite(leftTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(leftTrig, HIGH);                                                // ultra sonic sensor
  delayMicroseconds(10);
  digitalWrite(leftTrig, LOW);
  lduration = pulseIn(leftEcho, HIGH);
  LD = (lduration / 2) * 0.0343;
  Serial.println("Left:- " + String(LD)); // determining the distance to the left of the vehicle
}

void right_dist() {
  digitalWrite(rightTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(rightTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTrig, LOW);
  rduration = pulseIn(rightEcho, HIGH);
  RD = (rduration / 2) * 0.0343;
  Serial.println("Right:- " + String(RD)); // determining the distance to the right of the vehicle
}
////////////////////////////////////////////////////////
void setup() {

  Serial.begin(115200);


  //////////////////FOR GYRO CALIBRATION//////////////////////
  Wire.begin();
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } // stop everything if could not connect to MPU6050



  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  while (true) {
    Serial.println(F("Calculating offsets, do not move MPU6050"));
    mpu.calcOffsets(); // gyro and accelero
    delay(2000);
    Serial.print("Angel is: ");
    Serial.println(mpu.getAngleZ());
    if (mpu.getAngleZ() < 0.2 || mpu.getAngleZ() > -0.2) {
      break;
    }
  }
  Serial.println("Done!\n");
  ///////////////////////////////////////////////////////////

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(frontEcho, INPUT);
  pinMode(frontTrig, OUTPUT);
  pinMode(leftEcho, INPUT);
  pinMode(leftTrig, OUTPUT);
  pinMode(rightEcho, INPUT);
  pinMode(rightTrig, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(115);  // for testing purpose
  delay(1000);         // for testing purpose
  straight();
  pixy.init();

}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  //  if (lock == 0) {
  //    Serial.println(buttonState);
  //  }
  if (buttonState == 0) {   //To start the main loop for the robot
    flagg = 1;
  }
  // creating an infinite loop  after pressing the button
  while (flagg == 1) {
    mpu.update();
    gyroZ = mpu.getAngleZ();

    if ((millis() - timer) > 10) { // print data every 10ms
      Serial.println("//////////////////////////////////////////////////////");
      Serial.print("gyroZ is : ");
      Serial.println(gyroZ);
      timer = millis();
    }
    int orangeWidth = 0;
    int orangeHeight = 0;
    int orangeArea = 0;
    int blueWidth = 0;

    digitalWrite(in4, LOW);
    digitalWrite(in3, HIGH);  //forward
    analogWrite(enB, sped);


    //    myServo.write(83);

    int blocks = pixy.ccc.getBlocks();
    int sign = pixy.ccc.blocks[0].m_signature;

    front_dist();
    left_dist();
    right_dist();


    if (sign == 3) {     //orange detection
      orangeWidth = pixy.ccc.blocks[0].m_width;
      orangeHeight = pixy.ccc.blocks[0].m_height;
      orangeX = pixy.ccc.blocks[0].m_x;
      orangeY = pixy.ccc.blocks[0].m_y;
      //      for (int i = 0; i < pixy.ccc.numBlocks; i++)
      //      {
      //        Serial.print("  block ");
      //        Serial.print(i);
      //        Serial.print(": ");
      //        pixy.ccc.blocks[i].print();
      //      }
      orangeArea = orangeWidth * orangeHeight;
      Serial.println("orange area : " + String(orangeArea));
      pixy.ccc.blocks[0].print();
      Serial.println("");
    }

    else if (sign == 4) {    //blue detection
      blueWidth = pixy.ccc.blocks[0].m_width;
      blueHeight = pixy.ccc.blocks[0].m_height;
      blueX = pixy.ccc.blocks[0].m_x;
      blueY = pixy.ccc.blocks[0].m_y;
      Serial.println("Blue Line Width : " + String(blueWidth));

      pixy.ccc.blocks[0].print();
      Serial.println("");
    }

    ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////Starting of Main Code////////////////////////////


    //    if (sign == 4 && blueHeight > 32 && FD < 40) {  //blueLock == 0 && blueHeight > 15 && blueHeight < 35 &&
    //      //      int le = map(blueWidth, 34, 234, 30, 78);
    //      //      myServo.write(le);
    //      Serial.println("Blue - front wall turning right");
    //      right();
    //    }

    if (sign == 3 && orangeX <= 62 && orangeY >= 168 && FD <= 85) {
      Serial.println("Orange wall turn - Turning right");
      stableZ = stableZ - 90;
      while (gyroZ >= stableZ) {
        Serial.println("turning...");
        mpu.update();
        gyroZ = mpu.getAngleZ();
        right(50); //40
      }
      turns++;
      Serial.println("Turns became: " + String(turns));
    }


    ////////////////////////GYRO CENTERING/////////////////////////////
    else if (LD >= 19 && LD < 21 && (gyroZ > stableZ + 4)) {
      Serial.println("Centering the bot due to Gyro - Turning right");
      z = map(gyroZ, (stableZ + 25), (stableZ + 5), 30, 75);
      if (z < 30) {
        z = 30;
      } else if (z > 75) {
        z = 75;
      }
      right(z);
    }

    else if (LD >= 19 && LD < 21 && (gyroZ < stableZ - 4) ) {
      Serial.println("Centering the bot due to Gyro - Turning left");
      z = map(gyroZ, (stableZ - 25), (stableZ - 5), 150, 93);
      if (z < 93) {
        z = 93;
      } else if (z > 150) {
        z = 150;
      }
      left(z);
    }
    /////////////////////////////////////////////////////////////////////////

    ///////////////////////////LEFT WALL CENTERING////////////////////////
    else if (LD >= 21 && (gyroZ >= stableZ - 25) && (gyroZ <= stableZ + 25)) {  //far form left wall
      Serial.println("Going left 1\n");
      int j = map(LD, 22, 30, 93, 150); //25, 35
      if (j < 93) {
        j = 93;
      }
      else if (j > 150) {
        j = 150;
      }
      left(j);
    }

    else if (LD >= 21 && gyroZ > (stableZ + 25)) {          // far from left wall - CCW dir - 
      Serial.println("Going right 1");
      //      z = map(gyroZ, (stableZ + 25), (stableZ + 6), 30, 75);
      //      if (z < 30) {
      //        z = 30;
      //      } else if (z > 75) {
      //        z = 75;
      //      }
      right();
    }

    else if (LD >= 21 && gyroZ < (stableZ - 25)) {        //far from left wall - CW dir - /_/
      Serial.println("Going left 2");
      //      z = map(gyroZ, (stableZ - 25), (stableZ - 6), 150, 93);
      //      if (z < 93) {
      //        z = 93;
      //      } else if (z > 150) {
      //        z = 150;
      //      }
      left();
    }



    else if (LD < 19 && (gyroZ >= stableZ - 5) && (gyroZ <= stableZ + 5)) {     //closer to left wall
      Serial.println("Going right 2\n");
      int k = map(LD, 18, 12, 73, 30);
      if (k < 30) {
        k = 30;
      }
      else if (k > 73) {
        k = 73;
      }
      right(k);
    }

    else if (LD < 19 && gyroZ > (stableZ + 5)) {
      Serial.println("Going right 3\n");
      int k = map(gyroZ, (stableZ + 6), (stableZ + 25), 73, 30);
      if (k < 30) {
        k = 30;
      }
      else if (k > 73) {
        k = 73;
      }
      right(k);
    }

//    else if (LD < 19 && gyroZ < (stableZ - 5)) {
//      Serial.println("Going left 3\n");
//      int k = map(gyroZ, (stableZ - 6), (stableZ - 25), 93, 150);
//      if (k < 93) {
//        k = 93;
//      } else if (z > 150) {
//        k = 150;
//      }
//      left(k);
//    }


    else {
      straight();
      Serial.println("Going Straight\n");
    }
    Serial.print("StableZ is ");
    Serial.println(stableZ);

    //////////////////////Counting part///////////////////////

    //    if (sign == 3 && turn_flagg == 1) {
    //      turn_flagg = 0;
    //      blueLock = 1;
    //    }
    //    else if (sign == 4 && turn_flagg == 0) {
    //      Serial.println("Incrementing....\n\n");
    //      turn_flagg = 1;
    //      blueLock = 0;
    //      turns++;
    //    }


    if (turns == 4 && lock == 0 ) { //&& blueLock == 0
      //      delay(200);
      Serial.println("Turn became " + String(turns) + " ...PRE-STOPPINGs..........");
      Full = millis();
      Period = 5000;
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      lock = 1;
      //      flagg = 0;
      //      Serial.println("Breaking");
      //      break;
    }

    if (lock == 1 && millis() > Full + Period) {
      Serial.println("Times up!..STOPPING...");
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      flagg = 0;
      Serial.println("Breaking");
      break;
    }
  }
  if (lock == 1) {
    Serial.print("\n\n");
    Serial.print("Turns is ");
    Serial.println(turns);
    lock = 0;
  }
}
