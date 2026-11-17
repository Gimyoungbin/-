const int LED_EXT = D7;  // 외부 LED
const int BUZ = D6;  // 부저
void setup()
{
  pinMode(LED_EXT, OUTPUT);
  pinMode(BUZ, OUTPUT);
}

// void loop()
// {
//   digitalWrite(LED_EXT, HIGH);
//   tone(BUZ, 1000, 100); // 1000Hz, 0.1초
//   delay(500);
//   digitalWrite(LED_EXT, LOW);
//   delay(500);
// }

int notes[8] = {262, 294, 330, 349, 392, 440, 494, 523};

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(LED_EXT, i % 2);
    tone(BUZ, notes[i], 200);
    delay(250);
  }
  delay(1000);
}


