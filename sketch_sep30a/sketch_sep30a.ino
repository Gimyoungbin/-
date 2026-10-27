void setup() 
{
  Serial.begin(9600); // 약속한 속도로 포트를 연다
}
void loop()
{
  if (Serial.available() > 0){  // 도착한 게 있나?
    char c = Serial.read();      // 한 글자 꺼낸다
    if(c== 'b') 
    {
      tone(D9, 1000); // 울려라
    }
    if(c== 's') 
    {
      noTone(D9);  // 멈줘라
    }
    if(c== 'B') 
    {
      tone(D9, 1000); // 울려라
    }
    if(c== 'S') 
    {
      noTone(D9);  // 멈줘라
    }
  }
}


