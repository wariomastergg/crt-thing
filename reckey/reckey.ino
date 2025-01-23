String receivedMessage;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}
int key = 0;
void loop() {
  while (Serial1.available() > 0) {
    key = Serial1.read();
  }
  if (key == 104){
    Serial.println("wow");
  }
 
}
