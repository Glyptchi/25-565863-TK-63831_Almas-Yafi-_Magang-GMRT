#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

//Almas Yafi'
//565863

Servo servo1, servo2, servo3, servo4, servo5;

#define S1 12
#define S2 14
#define S3 16
#define S4 17
#define S5 19
#define pir 4

Adafruit_MPU6050 mpu;
int pirstate = LOW;

float roll, pitch, yaw;
int ip1 = 90, ip2 = 90, ip3 = 90, ip4 = 90, ip5 = 90;
int ip = 90;

void setup() {

  Serial.begin(115200);
  Wire.begin();

  servo1.attach(S1);
  servo2.attach(S2);
  servo3.attach(S3);
  servo4.attach(S4);
  servo5.attach(S5);

  servo1.write(ip1);
  servo2.write(ip2);
  servo3.write(ip3);
  servo4.write(ip4);
  servo5.write(ip5);

  pinMode(pir, INPUT);

}

void loop() {

  int motion = digitalRead(pir);

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  roll = g.gyro.x;
  pitch = g.gyro.y;
  yaw = g.gyro.z;

  if (motion == HIGH && pirstate == LOW) {
    pirstate = HIGH;

    for (int pos = ip; pos >= 45; pos--) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      servo5.write(pos);
      delay(10);
    }
    delay(300);

    for (int pos = 45; pos <= ip; pos++) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      servo5.write(pos);
      delay(10);
    } 
  } else if (motion == LOW && pirstate == HIGH) {
    pirstate = LOW;
  }

  if(roll>1){
    servo1.write(ip1 - 30);
    servo2.write(ip2 - 30);
  }else if(roll<-1){
    servo1.write(ip1 + 30);
    servo2.write(ip2 + 30);
  }else{
    servo1.write(ip1);
    servo2.write(ip2);
  }

  if(pitch>1){
    servo3.write(ip3 + 30);
    servo4.write(ip4 + 30);
  }else if(pitch<-1){
    servo3.write(ip3 - 30);
    servo4.write(ip4 - 30);
  }else{
    servo3.write(ip3);
    servo4.write(ip4);
  }

  if(yaw>1){
    servo5.write(ip5 + 30);
    delay(1000);
    servo5.write(ip5);
  }else if(yaw<-1){
    servo5.write(ip5 - 30);
    delay(1000);
    servo5.write(ip5);
  }

  delay(100);
}
