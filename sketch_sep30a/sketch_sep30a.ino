
int lastSw = HIGH;
long cnt = 0;
unsigned long Mil = 0;
long startTime,endTime;
int pw =0;
const int password = 221;


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
    delay(20);
    endTime = millis();
    if(endTime - startTime > 500)
    {
      pw = pw * 10 + 2;
    }
    else
    {
      pw = pw * 10 + 1;
    }
    cnt++;

    Serial.println(pw);
  }
  if(cnt >=3)
  {
    if(password == pw)
    {
      Serial.println("unlock");
    }
    else
    {
      Serial.println("Lock");
    }
    pw = 0;
    cnt = 0;

  }

  lastSw = sw;

}


