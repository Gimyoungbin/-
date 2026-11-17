// 조도센서 값 읽기: AO는 A0, DO는 D4
const int LIGHT_DO = D4;
 
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);     // 0 ~ 4095로 읽기
  pinMode(LIGHT_DO, INPUT);
}
 
void loop() {
  int raw = analogRead(A0);     // 0 ~ 4095
  float x = raw / 4095.0;       // 0 ~ 1로 바꾸기
  Serial.print("x:"); Serial.print(x);
  Serial.print(",DO:"); Serial.println(digitalRead(LIGHT_DO));
  delay(50);
}

