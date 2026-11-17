const int LED_EXT = D7;  // 외부 LED
const int BUZ = D6;  // 부저
void setup()
{
  pinMode(LED_EXT, OUTPUT);
  pinMode(BUZ, OUTPUT);
}

void loop()
{
  digitalWrite(LED_EXT, HIGH);
  tone(BUZ, 1000, 100); // 1000Hz, 0.1초
  delay(500);
  digitalWrite(LED_EXT, LOW);
  delay(500);
}
 


