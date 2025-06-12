void setup() {
  //Serial.begin(9600);
  //dacWrite(25, 0);
}

int i = 1;
float c;
void loop() {
  //Serial.println(99);
  x++;
  float c = ((((sin((float)x/3.))+1.)/2.)*250.);
  analogWrite(16, (int)c);
  
  delay(10);
  //Serial.println(num);
}
