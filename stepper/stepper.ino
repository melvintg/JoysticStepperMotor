
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepperX(stepsPerRevolution, 4, 5, 6, 7);
Stepper myStepperY(stepsPerRevolution, 8, 9, 10, 11);

int maxSpeedX = 20;
int speedX = 0;
int maxSpeedY = 20;
int speedY = 0;

int sX = 0;
int sY = 0;

int posX = 0;
int posY = 0;

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}

void loop() {
  // read the sensor value:
  sX = analogRead(0);
  sY = analogRead(1);
  Serial.print("read:");
  Serial.println(sX);

  if (sX > 530 and posX < 80) {
    speedX = map(sX, 500, 1023, 0, maxSpeedX);
    myStepperX.setSpeed(speedX);
    myStepperX.step(1);
    posX++;
    
  } else if (sX < 490 and posX > -80) {
    speedX = map(sX, 0, 530, 0, maxSpeedX);
    speedX = maxSpeedX - speedX;
    myStepperX.setSpeed(speedX);
    myStepperX.step(-1);
    posX--;
  }

  if (sY > 530 and posY > -25) {
    speedY = map(sY, 500, 1023, 0, maxSpeedY);
    myStepperY.setSpeed(speedY);
    myStepperY.step(1);
    posY--;
    
  } else if (sY < 490 and posY < 50) {
    speedY = map(sY, 0, 530, 0, maxSpeedY);
    speedY = maxSpeedX - speedY;
    myStepperY.setSpeed(speedY);
    myStepperY.step(-1);
    posY++;
  }

}
