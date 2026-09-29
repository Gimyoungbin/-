void setup() {
  Serial.begin(9600);


}

void loop() {
  int v = analogRead(A0);
  float volt = v * 3.3 / 1023.0;
  Serial.print(v);
  Serial.print(" ");
  Serial.println(volt, 2);  //소수 2자리
}