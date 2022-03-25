#include <SoftwareSerial.h> // add library for serial Bluetooth
#include <Servo.h>

// Choose bluetooth pins

int bthTx = 0; //transmisor
int bthRx = 1; //receptor
char result;
SoftwareSerial bluetooth(bthTx, bthRx); //definimos los pines de recepción y de transmisión

// create servo object to control a servo
Servo servo1;  
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

         servo1.write(0);
         servo2.write(0);
         servo3.write(0);
         servo4.write(0);
         servo5.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
 while (bluetooth.available() > 0){
    result = bluetooth.read();
    switch (result){
      case '0':
         servo1.write(0);
         servo2.write(0);
         servo3.write(0);
         servo4.write(0);
         servo5.write(0);
        break;
      case '1':
         servo1.write(80);
         servo2.write(50);
         servo3.write(80);
         servo4.write(40);
         servo5.write(30);
        break;
      case '2':
         servo1.write(180);
         servo2.write(0);
         servo3.write(0);
         servo4.write(180);
         servo5.write(180);
        break;
      case '3':
         servo1.write(130);
         servo2.write(100);
         servo3.write(90);
         servo4.write(35);
         servo5.write(10);
        break;
      case '4':
         servo1.write(0);
         servo2.write(0);
         servo3.write(180);
         servo4.write(180);
         servo5.write(0);
        break;
      case '5':
         servo1.write(180);
         servo2.write(30);
         servo3.write(180);
         servo4.write(180);
         servo5.write(180);

        break;
      case '6':
         servo1.write(0);
         servo2.write(180);
         servo3.write(180);
         servo4.write(180);
         servo5.write(0);



        break;

      
        
    }
 }
 delay(100);
}
