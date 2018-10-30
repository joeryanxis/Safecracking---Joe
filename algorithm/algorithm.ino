int i,j,k,l;
String num1, num2, num3, num4;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  algorithm();
}
void algorithm(){
   for(i = 0; i<9; i++){
    for(j = 0; j<9;j++){
      for(k = 0;k<9;k++){
        for(l = 0;l<9;l++){
         /* buttonPress(i);
          buttonPress(j);
          buttonPress(k);
          buttonPress(l);
          pressEnter();*/
          Serial.print(i);
          Serial.print(",");
          Serial.print(j);
          Serial.print(",");
          Serial.print(k);
          Serial.print(",");
          Serial.println(l);
          
        }
      }
    }
  }
}

