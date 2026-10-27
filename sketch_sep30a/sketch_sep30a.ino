void setup() 
{
  Serial.begin(9600); // 약속한 속도로 포트를 연다
}
void loop()
{
  Serial.write('U');  // 0x55 =0b01010101
}


