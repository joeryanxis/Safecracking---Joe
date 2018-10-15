#include <Keyboard.h>
#include <EEPROM.h>
const byte address = 0;
int lightTime = 0;
String keyInput;

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.println("Hello, Type a number between 0 and 9 in the box above to control how long the LED is illluminated");
}

void loop() {
  if(Serial.available() > 0){
    keyInput = Serial.read();
    lightTime = keyInput.toInt()-48;//converts it to the ASCII value, 0 being 48, 9 being 57
    
    if(lightTime != 0 && lightTime != 1 && lightTime != 2 && lightTime != 3 && lightTime != 4 && lightTime != 5 && lightTime != 6 && lightTime != 7 && lightTime != 8 && lightTime != 9){
      Serial.println("Please type a number between 0 and 9");
      Serial.println("Illuminating LED from last used number");
      //Serial.println(lightTime);
      lightTime = lightTime*1000;
      digitalWrite(3, HIGH);
      EEPROM.get(address,lightTime);
      delay(lightTime);
      digitalWrite(3,LOW);
    }
    else {
      lightTime = keyInput.toInt()-48;//converts it to the ASCII value, 0 being 48, 9 being 57
      lightTime = lightTime*1000;
      EEPROM.put(address, lightTime);
      Serial.println(lightTime);
      digitalWrite(3,HIGH);
   
      delay(lightTime);
      digitalWrite(3,LOW);  
    }
 
    
  }

}
