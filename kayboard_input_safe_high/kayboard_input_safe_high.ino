#include <EEPROM.h>

byte address = 0;
int digit1 ,digit2  ,digit3 ,digit4;//places to store input digits
int number;//temporary place to hold input
int counter = 0; // counts how many digits have been submitted
String keyInput; // string to hold input

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  //starts all pins at low
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  Serial.println("Hello, Type a number between 0 and 9 in the box above to send it to the keypad.");
}

void loop() {
  if(counter == 4){//if 4 numbers have been pressed
      pressEnter();//calls function to press enter
      allHigh();
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
      buttonPress(2,6);//calls the function to simulate pressing the 1 button on the keypad
      address = address + sizeof(int);//increments address, so the next value is written to an empty space in EEPROM
      counter++; //increments counter, gets closer to pressing enter
      
    }
    else if (number == 2 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(4,6);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 3 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(6,7);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 4 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(2,5);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 5 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(4,5);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 6 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(5,7);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 7 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(2,3);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 8 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(3,4);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 9 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(3,7);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 0 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(1,4);
      address = address + sizeof(int);
      counter++; 
      
    }

 }
}

void allHigh(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(5000);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
} 
void buttonPress(int a, int b){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  delay(20);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
}
void pressEnter(){
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(20);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
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
  
  
}

