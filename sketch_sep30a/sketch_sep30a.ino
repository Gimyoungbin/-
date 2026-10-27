void setup() 
{
  Serial.begin(9600); // 약속한 속도로 포트를 연다
  pinMode(D1, OUTPUT);
  pinMode(D8, OUTPUT);
}
void loop()
{
 digitalWrite(D1, HIGH);
 digitalWrite(D8, HIGH);
 delay(1000);
 digitalWrite(D1, LOW);
 digitalWrite(D8, LOW);
 delay(1000);
}


