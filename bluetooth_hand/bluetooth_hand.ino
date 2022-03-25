#include <SoftwareSerial.h> // add library for serial Bluetooth
#include <Servo.h>  // add servo library

// Choose bluetooth pins

int bthTx = 0; //transmisor
int bthRx = 1; //receptor

SoftwareSerial bluetooth(bthTx, bthRx); //definimos los pines de recepción y de transmisión

// create servo object to control a servo
Servo servo1;  
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 

// analog pin used to connect the potentiometer
#define sound 13
/*
int pot1 = A0;  
int pot2 = A2; 
int pot3 = A3; 
int pot4 = A4; 
int pot5 = A5; 
*/
// variable to read the value from the analog pin
 
char val;  

// attaches the servo on pins to the servo object
void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(sound, OUTPUT); 
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
  if (bluetooth.available() >= 2) //si existe una comunicación serial de bluetooth entonces...
  {

    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos; 
    Serial.println(realservo); 
    


switch(realservo){
  // POSICIONES
  case 0:
    zero();
    break;
  case 1:
    one();
    break;
  case 2:
    two();
    break;
  case 3:
    three();
    break;
  case 4: 
    four();
    break;
  case 5: 
    five();
    break;
  case 6:
    surf();
    break;
  case 7: 
    rock();
    break;
  //BAILES
  case 10: 
    dance_1();
    break;
  case 11: 
    dance_2();
    dance_2();
    delay(1000);
    five();
    break;
  case 12: 
    dance_3();
    five();
    break;
  case 13: 
    dance_4(); 
    break; 
  case 14: 
    dance_5(); 
    break;
  case 15: 
    dance_6(); 
    break; 
}


//SLIDES
    
    if (realservo >= 1000 && realservo <1180){ 
      int val1 = realservo; 
      val1 = map(val1,1000,1180, 0,180); 
      servo1.write(val1); 
      delay(10);
    }

    if (realservo >= 2000 && realservo <2180){ 
      int val2 = realservo; 
      val2 = map(val2,2000,2180, 0,180); 
      servo2.write(val2); 
      delay(10);
    }

     if (realservo >= 3000 && realservo <3180){ 
      int val3 = realservo; 
      val3 = map(val3,3000,3180, 0,180); 
      servo3.write(val3); 
      delay(10);
    }

     if (realservo >= 4000 && realservo <4180){ 
      int val4 = realservo; 
      val4 = map(val4,4000,4180, 0,180); 
      servo4.write(val4); 
      delay(10);
    }

     if (realservo >= 5000 && realservo <5180){ 
      int val5 = realservo; 
      val5 = map(val5,5000,5180,0,180); 
      servo5.write(val5); 
      delay(10);
    }
    if (realservo >= 6000 && realservo <6180){ 
      int val6 = realservo; 
      val6 = map(val6,6000,6180,0,180); 
      servo1.write(val6); 
      servo2.write(val6); 
      servo3.write(val6); 
      servo4.write(val6); 
      servo5.write(val6); 
      delay(10);
    }
  }


}

int one(){
  servo1.write(180);
  servo2.write(0);
  servo3.write(180);
  servo4.write(180);
  servo5.write(180);
}

int two(){
  servo1.write(180);
  servo2.write(0);
  servo3.write(0);
  servo4.write(180);
  servo5.write(180);
} 

int three(){
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(180);
  servo5.write(180);
}

int four(){
  servo1.write(180);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}

int five(){
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}

int zero(){
  servo1.write(180);
  servo2.write(180);
  servo3.write(180);
  servo4.write(180);
  servo5.write(180);
  
}

int rock(){
       servo1.write(180);
       servo2.write(0);
       servo3.write(180);
       servo4.write(180);
       servo5.write(0);
}

int surf(){
       servo1.write(0);
       servo2.write(180);
       servo3.write(180);
       servo4.write(180);
       servo5.write(0);
}

int dance_1(){
  zero();
  delay(1000);
  one();
  delay(1000);
  two(); 
  delay(1000);
  three();
  delay(1000);
  four();
  delay(1000);
  five();
  delay(1000);
}

int dance_2(){
  two(); 
  delay(1000);
  surf();
  delay(1000);
  rock();
  delay(1000);
  zero();
}

int dance_3(){
  five(); 
  delay(400);
  servo5.write(60);
  delay(100);
  servo4.write(60); 
  delay(100);
  servo3.write(60);
  servo5.write(0); 
  delay(100);
  servo2.write(60);
  servo4.write(0); 
  delay(100); 
  servo1.write(60);
  servo3.write(0);
  delay(100); 
  servo2.write(0);
  delay(100); 
  servo1.write(0);

  delay(100);
  servo1.write(60);
  delay(100);
  servo2.write(60); 
  delay(100);
  servo3.write(60);
  servo1.write(0); 
  delay(100);
  servo4.write(60);
  servo2.write(0); 
  delay(100); 
  servo5.write(60);
  servo3.write(0);
  delay(100); 
  servo4.write(0);
  delay(100); 
  servo5.write(0);

  

  delay(400);
  five(); 
  servo5.write(180); 
  delay(200);
  servo4.write(180); 
  delay(200);
  servo3.write(180); 
  delay(200);
  servo2.write(180); 
  delay(200);
  servo1.write(180); 
  delay(200);
  
}


int dance_4(){ 
  zero(); 
  delay(500);
  finger_1(); 
  delay(500);
  finger_2();
  delay(500);
  finger_3(); 
  delay(500);
  finger_4();
  delay(500);
  finger_5();   
  delay(500);
  finger_4(); 
  delay(500);
  finger_3(); 
  delay(500);
  finger_2();
  delay(500);
  finger_1();
  delay(500);
  zero(); 
  delay(500);
  five();   
  delay(500);
}

int dance_5(){
  positions(180, 180, 180, 180, 180); 
  delay(500);
  positions(0, 180, 180, 180, 180); 
  delay(500);
  positions(180, 0, 180, 180, 180); 
  delay(500);
  positions(0, 0, 180, 180, 180); 
  delay(500);
  positions(180, 180, 0, 180, 180); 
  delay(500);
  positions(0, 180, 0, 180, 180); 
  delay(500);
  positions(180, 0, 0, 180, 180); 
  delay(500);
  positions(0, 0, 0, 180, 180); 
  delay(500);
  positions(180, 180, 180, 0, 180); 
  delay(500);
  positions(0, 180, 180, 0, 180); 
  delay(500);
  positions(180, 0, 180, 0, 180); 
  delay(500);
  positions(0, 0, 180, 0, 180); 
  delay(500);
  positions(180, 180, 0, 0, 180); 
  delay(500);
  positions(0, 180, 0, 0, 180); 
  delay(500);
  positions(180, 0, 0, 0, 180);
  delay(500);
  positions(0, 0, 0, 0, 180);  
  delay(500);
  positions(180, 180, 180, 180, 0); 
  delay(500);
  positions(0, 180, 180, 180, 0); 
  delay(500);
  positions(180, 0, 180, 180, 0); 
  delay(500);
  positions(0, 0, 180, 180, 0); 
  delay(500);
  positions(180, 180, 0, 180, 0); 
  delay(500);
  positions(0, 180, 0, 180, 0); 
  delay(500);
  positions(180, 0, 0, 180, 0); 
  delay(500);
  positions(0, 0, 0, 180, 0); 
  delay(500);
  positions(180, 180, 180, 0, 0); 
  delay(500);
  positions(0, 180, 180, 0, 0); 
  delay(500);
  positions(180, 0, 180, 0, 0); 
  delay(500);
  positions(0, 0, 180, 0, 0); 
  delay(500);
  positions(180, 180, 0, 0, 0); 
  delay(500);
  positions(0, 180, 0, 0, 0); 
  delay(500);
  positions(180, 0, 0, 0, 0); 
  delay(500);
  positions(0, 0, 0, 0, 0); 
  delay(500);
  
}

int dance_6(){ 
  three();
  delay(200);
  digitalWrite(sound,HIGH);
  delay(300);
  digitalWrite(sound, LOW);
  
  two(); 
  delay(200);
  digitalWrite(sound,HIGH);
  delay(300);
  digitalWrite(sound, LOW);
  
  one(); 
  delay(200);
  digitalWrite(sound,HIGH);
  delay(300);
  digitalWrite(sound,LOW);
  
  positions(180,180,180,180,180);
  delay(500); 
  positions(150,150,150,150,150);
  delay(100); 
  positions(180,180,180,180,180);
  delay(500);
  positions(150,150,150,150,150);
  delay(100); 
  positions(180,180,180,180,180);
  delay(500);
  positions(150,150,150,150,150);
  delay(500);
  int rnd = random(0, 3);
switch(rnd){
  case 0:
    two();
    break;
  case 1: 
    five();
    break; 
  case 2: 
    zero();
    break;
  
} 
  
  
  
  
  
}
// DEDOS

int finger_1(){
       servo1.write(0);
       servo2.write(180);
       servo3.write(180);
       servo4.write(180);
       servo5.write(180);
}

int finger_2(){
       servo1.write(180);
       servo2.write(0);
       servo3.write(180);
       servo4.write(180);
       servo5.write(180);
}

int finger_3(){
       servo1.write(180);
       servo2.write(180);
       servo3.write(0);
       servo4.write(180);
       servo5.write(180);
}
int finger_4(){
       servo1.write(180);
       servo2.write(180);
       servo3.write(180);
       servo4.write(0);
       servo5.write(180);
}
int finger_5(){
       servo1.write(180);
       servo2.write(180);
       servo3.write(180);
       servo4.write(180);
       servo5.write(0);
}

int positions(int one,int two,int three,int four,int five){
       servo1.write(one);
       servo2.write(two);
       servo3.write(three);
       servo4.write(four);
       servo5.write(five);
}
