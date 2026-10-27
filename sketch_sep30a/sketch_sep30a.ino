void setup() 
{
  Serial.begin(9600); // 약속한 속도로 포트를 연다
}
void loop()
{
  if (Serial.available() > 0){  // 도착한 게 있나?
    char c = Serial.read();      // 한 글자 꺼낸다
    Serial.print("got: ");
    Serial.println(c);
  }
}


