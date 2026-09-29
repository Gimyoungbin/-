void setup() {
  Serial.begin(9600);
  pinMode(D7, INPUT);

}

void loop() {
  Serial.println(digitalRead(D7));
  delay(200);
}