volatile int encoderValue = 0;
volatile long lastEncoderValue = 0;

int encoderPin1 = 2;
int encoderPin2 = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);

  digitalWrite(encoderPin1, 1);
  digitalWrite(encoderPin2, 1);

  attachInterrupt(digitalPinToInterrupt(2),updateEncoder,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),updateEncoder,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(encoderValue);
  delay(50);
}

void updateEncoder(){

  int MSB = digitalRead(encoderPin1);
  int LSB = digitalRead(encoderPin2);

  int encoded = (MSB << 1) | LSB;
  int sum = (lastEncoderValue << 2) | encoded;
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011){ 
    encoderValue ++; 
  }
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000){
    encoderValue --; 
  }
  lastEncoderValue = encoded;
  }


