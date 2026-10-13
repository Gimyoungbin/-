
int lastSw = HIGH;
long cnt = 0;
unsigned long Mil = 0;
long startTime,endTime;


void setup()
{
  Serial.begin(9600);
  pinMode(D4, INPUT_PULLUP);
}

void loop()
{
  int sw = digitalRead(D4);

  if (lastSw == HIGH && sw == LOW)
  {
    delay(20);
    startTime = millis();
  }

  if (lastSw == LOW && sw == HIGH)
  {
    endTime = millis();
    if(endTime - startTime > 500)
    {
      Serial.println("2");
    }
    else
    {
      Serial.println("1");
    }
  }

  lastSw = sw;

}


