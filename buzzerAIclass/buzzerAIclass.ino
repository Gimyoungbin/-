const int PRegistor = A0;
const int led = 9;

void setup() {
  Serial.begin(9600);

}

void loop() {

  int value = analogRead(PRegistor);
  analogWrite(led,255-value);
  Serial.println(value);
}
