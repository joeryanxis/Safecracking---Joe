int photogate;

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);

}

void loop() {
  photogate = digitalRead(3);
  Serial.println(photogate);

}
