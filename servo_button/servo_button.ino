#include <Servo.h>//include servo library
Servo myservo;//declare servo
int pos = 0;//set initial position to 0
int button, buttonState; //declare button
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);//set pin to to read button
  myservo.attach(9);//attach servo to pin #9
}

void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(2);
  Serial.println(button);
  if (button == 1){
    toggle();
    delay(200);
  }
  if (buttonState == 0){
    myservo.write(90);
  }
  else{
    myservo.write(0);
  }
}
void toggle(){
  if (buttonState==1){
    buttonState = 0;
  }
  else{
    buttonState = 1;
  }
}

