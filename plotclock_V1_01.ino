// Plotclock
// cc - by Johannes Heberlein 2014
// v 1.01
// thingiverse.com/joo   wiki.fablab-nuernberg.de

// units: mm; microseconds; radians
// origin: bottom left of drawing surface

// time library see http://playground.arduino.cc/Code/time 

// delete or mark the next line as comment when done with calibration  
#define CALIBRATION

// When in calibration mode, adjust the following factor until the servos move exactly 90 degrees
#define SERVOFAKTOR 603    //x* 360/47.5 * 500 / 2Pi

// Zero-position of left and right servo
// When in calibration mode, adjust the NULL-values so that the servo arms are at all times parallel
// either to the X or Y axis
#define SERVOLEFTNULL 300
#define SERVORIGHTNULL 984

#define SERVOPINLIFT  5
#define SERVOPINLEFT  7
#define SERVOPINRIGHT 6

// lift positions of lifting servo
#define LIFT0 1250 // on drawing surface
#define LIFT1 1140  // between numbers
#define LIFT2 800  // going towards sweeper

// speed of liftimg arm, higher is slower
#define LIFTSPEED 1500

// length of arms
#define L1 35
#define L2 45
#define L3 13


// origin points of left and right servo 
#define O1X 22
#define O1Y -25
#define O2X 47
#define O2Y -25



#include <Time.h> // see http://playground.arduino.cc/Code/time 
#include <Servo.h>

int servoLift = 1500;

Servo servo1;  // 
Servo servo2;  // 
Servo servo3;  // 

volatile double lastX = 39.5;  //
volatile double lastY = 40; //

int last_min = 0;

void setup() 
{ 
  Serial.begin(9600);
  // Set current time only the first to values, hh,mm are needed
  setTime(21,49,0,0,0,0);

  //drawTo(75.2, 47);
  lift(0);
  servo1.attach(SERVOPINLIFT);  //  lifting servo
  servo2.attach(SERVOPINLEFT);  //  left servo
  servo3.attach(SERVOPINRIGHT);  //  right servo
  lift(1);
  //set_XY(lastX, lastY);
  delay(5000);  
} 

#define H_p      34
void cha() 
{
  lift(2);
  drawTo(73, H_p);
  lift(1);
  drawTo(10, 34);
  drawTo(50, 30);
  drawTo(10, 28);
  drawTo(50, 20);
  drawTo(10, 18);
  drawTo(50, 15);
  drawTo(4, 12);
  drawTo(50, 10);
  drawTo(4, 10);
  //drawTo(4, 35);
  //drawTo(7, 8);
  drawTo(6, 35);
  drawTo(7, 8);
  drawTo(8, 35);
  drawTo(10, 8);
  drawTo(12, 35);
  drawTo(15, 8);
  drawTo(18, 37);
  drawTo(20, 8);
  drawTo(22, 37);
  drawTo(25, 8);
  drawTo(27, 37);
  drawTo(30, 8);
  drawTo(32, 37);
  drawTo(35, 8);
  drawTo(39, H_p);
  
  drawTo(22, H_p);
  drawTo(73, H_p);
  lift(2);
  drawTo(10, 39);
  lift(1);
}

void loop() 
{ 

#ifdef CALIBRATION

  // Servohorns will have 90° between movements, parallel to x and y axis
  //delay(1000);
  //number(3, 3, 111, 1);
  //delay(2000);
  /*servo2.writeMicroseconds(1252);
  servo3.writeMicroseconds(1852);
  delay(2000);
  servo2.writeMicroseconds(1389);
  servo3.writeMicroseconds(1852);*/
  delay(2000);
  cha();
   delay(4000);
  drawTo(34.5, 45);
     delay(4000);
  //cha();
  //number(0 + 10, 5, 1, 0.9);
 // drawTo(34.5, 45);
  /*drawTo(5, 4);
  drawTo(5, 45);
  drawTo(50, 45);
  drawTo(50, 40);

  drawTo(5, 40);
  drawTo(5, 35);
  drawTo(50, 35);
  drawTo(65, 30);

  drawTo(5, 30);
  drawTo(5, 25);
  drawTo(50, 25);
  drawTo(50, 20);

  drawTo(5, 20);
  drawTo(60, 44);

  drawTo(75.2, 47);
  delay(1000);*/
  //drawTo(10, 10);
  //delay(1000);
  //drawTo(50, 10);
  //delay(1000);
 // drawTo(50, 40);
  //delay(1000);
  //drawTo(10, 40);
  //drawTo(40,40);
  //delay(5000);
  //drawTo(1, 30);
  //delay(1000);
  //drawTo(, 15);
  //delay(5000);*/
  
  //lift(1);
  /*drawTo(1, 55);
  delay(3000);
  drawTo(70, 55);
  delay(3000);
  drawTo(70, 1);
  delay(3000);
  drawTo(1, 1);*/
  
  //delay(3000);
  /*drawTo(0, 28);
  delay(1000);
  drawTo(74, 28);
  delay(1000);
  drawTo(74, 44);
  delay(1000);
  drawTo(0, 44);
  delay(1000);*/

#else 
  int pyX =5;
  int pyY = - 17;

  int i = 0;
  if (last_min != minute()) {

    if (!servo1.attached()) servo1.attach(SERVOPINLIFT);
    if (!servo2.attached()) servo2.attach(SERVOPINLEFT);
    if (!servo3.attached()) servo3.attach(SERVOPINRIGHT);

    lift(2);

    hour();
    while ((i+1)*10 <= hour())
    {
      i++;
    }

    number(3 + pyX, 3 + pyY, 111, 1);
    number(0 + pyX, 25 + pyY, i, 0.9);
    number(14 + pyX, 25 + pyY , (hour()-i*10), 0.9);
    number(23 + pyX, 25 + pyY, 11, 0.9);

    i=0;
    while ((i+1)*10 <= minute())
    {
      i++;
    }
    number(29 + pyX, 25 + pyY, i, 0.9);
    number(43 + pyX, 25 + pyY, (minute()-i*10), 0.9);
    lift(2);
    drawTo(70.2, 40.5);
    lift(2);
    last_min = minute();

    servo1.detach();
    servo2.detach();
    servo3.detach();
  }

#endif

} 

// Writing numeral with bx by being the bottom left originpoint. Scale 1 equals a 20 mm high font.
// The structure follows this principle: move to first startpoint of the numeral, lift down, draw numeral, lift up
void number(float bx, float by, int num, float scale) {

  switch (num) {

  case 0:
    drawTo(bx + 12 * scale, by + 6 * scale);
    lift(0);
    bogenGZS(bx + 7 * scale, by + 10 * scale, 10 * scale, -0.8, 6.7, 0.5);
    lift(1);
    break;
  case 1:

    drawTo(bx + 3 * scale, by + 15 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 10 * scale, by + 0 * scale);
    lift(1);
    break;
  case 2:
    drawTo(bx + 2 * scale, by + 12 * scale);
    lift(0);
    bogenUZS(bx + 8 * scale, by + 14 * scale, 6 * scale, 3, -0.8, 1);
    drawTo(bx + 1 * scale, by + 0 * scale);
    drawTo(bx + 12 * scale, by + 0 * scale);
    lift(1);
    break;
  case 3:
    drawTo(bx + 2 * scale, by + 17 * scale);
    lift(0);
    bogenUZS(bx + 5 * scale, by + 15 * scale, 5 * scale, 3, -2, 1);
    bogenUZS(bx + 5 * scale, by + 5 * scale, 5 * scale, 1.57, -3, 1);
    lift(1);
    break;
  case 4:
    drawTo(bx + 10 * scale, by + 0 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 2 * scale, by + 6 * scale);
    drawTo(bx + 12 * scale, by + 6 * scale);
    lift(1);
    break;
  case 5:
    drawTo(bx + 2 * scale, by + 5 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 6 * scale, 6 * scale, -2.5, 2, 1);
    drawTo(bx + 5 * scale, by + 20 * scale);
    drawTo(bx + 12 * scale, by + 20 * scale);
    lift(1);
    break;
  case 6:
    drawTo(bx + 2 * scale, by + 10 * scale);
    lift(0);
    bogenUZS(bx + 7 * scale, by + 6 * scale, 6 * scale, 2, -4.4, 1);
    drawTo(bx + 11 * scale, by + 20 * scale);
    lift(1);
    break;
  case 7:
    drawTo(bx + 2 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 12 * scale, by + 20 * scale);
    drawTo(bx + 2 * scale, by + 0);
    lift(1);
    break;
  case 8:
    drawTo(bx + 5 * scale, by + 10 * scale);
    lift(0);
    bogenUZS(bx + 5 * scale, by + 15 * scale, 5 * scale, 4.7, -1.6, 1);
    bogenGZS(bx + 5 * scale, by + 5 * scale, 5 * scale, -4.7, 2, 1);
    lift(1);
    break;

  case 9:
    drawTo(bx + 9 * scale, by + 11 * scale);
    lift(0);
    bogenUZS(bx + 7 * scale, by + 15 * scale, 5 * scale, 4, -0.5, 1);
    drawTo(bx + 5 * scale, by + 0);
    lift(1);
    break;

  case 111:
    cha();
 
    break;

  case 11:
    drawTo(bx + 5 * scale, by + 15 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 15 * scale, 0.1 * scale, 1, -1, 1);
    lift(1);
    drawTo(bx + 5 * scale, by + 5 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 5 * scale, 0.1 * scale, 1, -1, 1);
    lift(1);
    break;

  }
}



void lift(char lift) {
  switch (lift) {
    // room to optimize  !

  case 0: //850

      if (servoLift >= LIFT0) {
      while (servoLift >= LIFT0) 
      {
        servoLift--;
        servo1.writeMicroseconds(servoLift);				
        delayMicroseconds(LIFTSPEED);
      }
    } 
    else {
      while (servoLift <= LIFT0) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }
    }

    break;

  case 1: //150

    if (servoLift >= LIFT1) {
      while (servoLift >= LIFT1) {
        servoLift--;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);

      }
    } 
    else {
      while (servoLift <= LIFT1) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }

    }

    break;

  case 2:

    if (servoLift >= LIFT2) {
      while (servoLift >= LIFT2) {
        servoLift--;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }
    } 
    else {
      while (servoLift <= LIFT2) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);				
        delayMicroseconds(LIFTSPEED);
      }
    }
    break;
  }
}


void bogenUZS(float bx, float by, float radius, int start, int ende, float sqee) {
  float inkr = -0.05;
  float count = 0;

  do {
    drawTo(sqee * radius * cos(start + count) + bx,
    radius * sin(start + count) + by);
    count += inkr;
  } 
  while ((start + count) > ende);

}

void bogenGZS(float bx, float by, float radius, int start, int ende, float sqee) {
  float inkr = 0.05;
  float count = 0;

  do {
    drawTo(sqee * radius * cos(start + count) + bx,
    radius * sin(start + count) + by);
    count += inkr;
  } 
  while ((start + count) <= ende);
}


void drawTo(double pX, double pY) {
  double dx, dy, c;
  int i;

  // dx dy of new point
  dx = pX - lastX;
  dy = pY - lastY;
  //path lenght in mm, times 4 equals 4 steps per mm
  c = floor(4 * sqrt(dx * dx + dy * dy));

  if (c < 1) c = 1;

  for (i = 0; i <= c; i++) {
    // draw line point by point
    set_XY(lastX + (i * dx / c), lastY + (i * dy / c));

  }

  lastX = pX;
  lastY = pY;
}

double return_angle(double a, double b, double c) {
  // cosine rule for angle between c and a
  return acos((a * a + c * c - b * b) / (2 * a * c));
}

void print_angle(double x, double y, int a1, int a2) {
   return;
   Serial.print("a1:a2 | ");
   Serial.print(a1);
   Serial.print(":");   
   Serial.print(a2);
   
   Serial.print("  ===x:y|");
   Serial.print(x);
   Serial.print(":");   
   Serial.print(y);
   Serial.println();
}

void set_XY2(double Tx, double Ty) 
{
  delay(1);
  double dx, dy, c, a1, a2, Hx, Hy;
  int so1j = 0, so2j = 0;

  // calculate triangle between pen, servoLeft and arm joint
  // cartesian dx/dy
  dx = Tx - O1X;
  dy = Ty - O1Y;

  // polar lemgth (c) and angle (a1)
  c = sqrt(dx * dx + dy * dy); // 
  a1 = atan2(dy, dx); //
  a2 = return_angle(L1, L2, c);

  so1j = floor(((a2 + a1 - M_PI) * SERVOFAKTOR) + SERVOLEFTNULL);
 /* ---------------------------------------------- */
  // calculate joinr arm point for triangle of the right servo arm
  a2 = return_angle(L2, L1, c);
  Hx = Tx + L3 * cos((a1 - a2 + 0.621) + M_PI); //36,5°
  Hy = Ty + L3 * sin((a1 - a2 + 0.621) + M_PI);

  // calculate triangle between pen joint, servoRight and arm joint
  dx = Hx - O2X;
  dy = Hy - O2Y;

  c = sqrt(dx * dx + dy * dy);
  a1 = atan2(dy, dx);
  a2 = return_angle(L1, (L2 - L3), c);

  so2j = floor(((a1 - a2) * SERVOFAKTOR) + SERVORIGHTNULL);
  servo2.writeMicroseconds(so1j);
  servo3.writeMicroseconds(so2j);

  print_angle(Tx, Ty, so1j,so2j);
}

void set_XY(double Tx, double Ty) 
{
  delay(6);
  double dx, dy, c, a1, a2, a3, Hx, Hy;
  int so1j = 0, so2j = 0;

  // calculate triangle between pen, servoLeft and arm joint
  // cartesian dx/dy
  dx = Tx - O1X;
  dy = Ty - O1Y;
  
  // polar lemgth (c) and angle (a1)
  c = sqrt(dx * dx + dy * dy); // 
  a1 = atan2(dy, dx); //
  a2 = return_angle(L1, L2, c);
  //Serial.print("C1:");
  //Serial.print(c);
  //Serial.print(" atan2:");
  //Serial.print(a1);
  //Serial.print(" angle:");
  //Serial.print(a2);
  if ( c < L2 - L1 || c > L2 + L1) return;  
  //Serial.print(" all*:");
  //Serial.print((a2 + a1) * SERVOFAKTOR);  
  so1j = floor(((a2 + a1) * SERVOFAKTOR) + SERVOLEFTNULL);
  //so1j = floor(2500 - ((a2 + a1) * SERVOFAKTOR) );
 /* ---------------------------------------------- */
  // calculate joinr arm point for triangle of the right servo arm
  dx = Tx - O2X;
  dy = Ty - O2Y;
  
  c = sqrt(dx * dx + dy * dy); 
  //Serial.print(" C2:");
  //Serial.print(c);
  //Serial.print(" | ");
  if (c < L2 - L1 || c > L2 + L1) return;
  a3 = atan2(dy, dx);
  a2 = return_angle(L1, L2, c);

  so2j = floor(((a3 - a2) * SERVOFAKTOR) + SERVORIGHTNULL);
  //so2j = floor(2500 - ((a3 - a2) * SERVOFAKTOR) );
  servo2.writeMicroseconds(so1j);
  servo3.writeMicroseconds(so2j);
  print_angle(Tx, Ty, so1j,so2j);
}




