#define rightMaxSpeed 255
#define leftMaxSpeed 255
#define rightBaseSpeed 200
#define leftBaseSpeed 200
#define safe 15
#define k 5
#define fsafe 20
#define Kf 5
//ultrasonic definitions
const int ltrig =2;
const int ftrig =7;
const int lecho =4;
const int fecho =8;

double ltime;
double ldist;
double ftime;
double fdist;

//motor definitions
int enA = 6;
int in1 = 3;
int in2 = 5;
int enB = 11;
int in3 = 10;
int in4 = 9;

void setup() {
//ultrasonic setup
Serial.begin(9600); // Starting Serial Terminal
pinMode(ltrig,OUTPUT);
pinMode(lecho,INPUT);

//motor setup
pinMode(enA,INPUT);
pinMode(in1,INPUT);
pinMode(in2,INPUT);
pinMode(enB,INPUT);
pinMode(in3,INPUT);
pinMode(in4,INPUT);
delay(2000);

}

double error;

void loop() {

digitalWrite(ltrig,LOW);
delayMicroseconds(10);
digitalWrite(ltrig,HIGH);
delayMicroseconds(30);
digitalWrite(ltrig,LOW);

ltime = pulseIn(lecho,HIGH);
ldist=ltime*0.034/2;
Serial.println(ldist);

digitalWrite(ftrig,LOW);
delayMicroseconds(10);
digitalWrite(ftrig,HIGH);
delayMicroseconds(30);
digitalWrite(ftrig,LOW);

ftime = pulseIn(fecho,HIGH);
fdist=ftime*0.034/2;
Serial.println(fdist);

error = ldist - safe;
int motorSpeed = k * error;
int rightMotorSpeed = rightBaseSpeed + motorSpeed;
int leftMotorSpeed = leftBaseSpeed - motorSpeed;
/*
error = fdist - fsafe;
int fmotorSpeed = Kf * error;
int frightMotorSpeed = rightBaseSpeed - fmotorSpeed;
int fleftMotorSpeed = leftBaseSpeed + fmotorSpeed;

if (fdist<20)
{
analogWrite(enA,leftBaseSpeed);
analogWrite(enB,0);

analogWrite(enA,fleftMotorSpeed);
analogWrite(enB,frightMotorSpeed);

fleftMotorSpeed = constrain(fleftMotorSpeed,100,255);
frightMotorSpeed = constrain(frightMotorSpeed,100,255);

}
*/
//else {
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);

leftMotorSpeed = constrain(leftMotorSpeed,100,255);
rightMotorSpeed = constrain(rightMotorSpeed,100,255);

analogWrite(enA,leftMotorSpeed);
analogWrite(enB,rightMotorSpeed);
//}

}
