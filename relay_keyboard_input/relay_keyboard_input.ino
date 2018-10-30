#include <EEPROM.h>
#include <Servo.h>


#define num1 2
#define num2 3
#define num3 4
#define num4 5
#define num5 6
#define num6 7
#define num7 8
#define num8 9
#define num9 10
#define num0 11
#define enter 12
//set pins that will control the relays that short the two wires together

byte address = 0;
int digit1 ,digit2  ,digit3 ,digit4;//places to store input digits
int number;//temporary place to hold input
int counter = 0; // counts how many digits have been submitted
String keyInput; // string to hold input

//photosensor reading variables
int sensorVal=0;//hold sensor Value
int photoCellValue = A0;

//servo code 
Servo myServo;
int pos = 0;//set initial position to zero

void setup() {
  Serial.begin(9600);
  pinMode(num1,OUTPUT);
  pinMode(num2,OUTPUT);
  pinMode(num3,OUTPUT);
  pinMode(num4,OUTPUT);
  pinMode(num5,OUTPUT);
  pinMode(num6,OUTPUT);
  pinMode(num7,OUTPUT);
  pinMode(num8,OUTPUT);
  pinMode(num9,OUTPUT);
  pinMode(num0,OUTPUT);
  pinMode(enter, OUTPUT);
  //starts all pins at LOW
  digitalWrite(num1,LOW);
  digitalWrite(num2,LOW);
  digitalWrite(num3,LOW);
  digitalWrite(num4,LOW);
  digitalWrite(num5,LOW);
  digitalWrite(num6,LOW);
  digitalWrite(num7,LOW);
  digitalWrite(num8,LOW);
  digitalWrite(num9,LOW);
  digitalWrite(num0,LOW);
  digitalWrite(enter,LOW);

  pinMode(photoCellValue, INPUT);//sets pin to read photosensor value

  myServo.attach(1);//Set servo control pin to #1, because all our other pins are taken
  myServo.write(0);
  Serial.println("Hello, Type a number between 0 and 9 in the box above to send it to the keypad.");
}

void loop() {
  if(counter == 4){//if 4 numbers have been pressed
      pressEnter();//calls function to press enter
    }
  if(Serial.available() > 0){//if you type a thing
    keyInput = Serial.read();//reads input, puts it in keyinput
    number = keyInput.toInt()-'0';//converts it to the ASCII value, 0 being 48, 9 being 57

    if(number < 0 || number > 9 ){
      //Makes sure it's an integer input
      Serial.println("Please type a number between 0 and 9");
    }
    else if (number == 1 && counter != 4){
      //Makes sure the counter isn't already at the max
      EEPROM.put(address, number);//stores the digit in EEPROM
      Serial.println(number);//Prints the number
      buttonPress(num1);//calls the function to simulate pressing the 1 button on the keypad
      address = address + sizeof(int);//increments address, so the next value is written to an empty space in EEPROM
      counter++; //increments counter, gets closer to pressing enter
      
    }
    else if (number == 2 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num2);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 3 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num3);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 4 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num4);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 5 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num5);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 6 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num6);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 7 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num7);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 8 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num8);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 9 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num9);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 0 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num0);
      address = address + sizeof(int);
      counter++; 
      
    }

 }
}


void buttonPress(int a){
  digitalWrite(a, HIGH);
  delay(50);
  digitalWrite(a, LOW);
  delay(50);
}



void pressEnter(){
 
  digitalWrite(enter,HIGH);
  delay(50);
  digitalWrite(enter,LOW);
  delay(50);
  counter = 0;//resets counter to 0
  address = 0;//resets address to zero, to make EEPROM easier to read from
  EEPROM.get(address,digit1);//reads value at first address, stores it into digit1
  address = address + sizeof(int);//increments address 
  EEPROM.get(address,digit2);
  address = address + sizeof(int);
  EEPROM.get(address,digit3);
  address = address + sizeof(int);
  EEPROM.get(address,digit4);
  address = 0;// resets address to zero, for the next round of testing
  Serial.print("Combination tried:");
  Serial.print(digit1);
  Serial.print(", ");
  Serial.print(digit2);
  Serial.print(", ");
  Serial.print(digit3);
  Serial.print(", ");
  Serial.println(digit4);
  
  check();
}

void check(){
  sensorVal = analogRead(photoCellValue);
  Serial.println("Checking...");
  //Serial.println(sensorVal);
  if(sensorVal>375){
    delay(3000);//delay 3 seconds
    sensorVal = analogRead(photoCellValue);
    if(sensorVal>375){
    Serial.println("SUCESSFUL COMBINATION");
    turnHandle();
    exit;
    }else{
     Serial.println("FAILED");
    }
  }
}

void turnHandle(){
  myServo.write(90);
}



