const int SW1 = D2, SW2 = D3;
const int LED = LED_BUILTIN;
 
// 학습 데이터 (AND)
int X[4][2] = {{0,0},{0,1},{1,0},{1,1}};
int T[4] = {0,0,0,1};
 
float w1 = 0, w2 = 0, b = 0;
float lr = 0.25;  // 학습률
void setup() {
  Serial.begin(115200);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  delay(2000); // 창 열 시간
  train();     // 학습!
}
 
void loop()
{ // 추론
  int x1 = (digitalRead(SW1)==LOW)?1:0;
  int x2 = (digitalRead(SW2)==LOW)?1:0;
  digitalWrite(LED, predict(x1,x2));
  delay(20);
}
 
int predict(int x1, int x2) {
  return (w1*x1 + w2*x2 + b > 0) ? 1 : 0;
}
void train()
{
  for (int epoch = 1; epoch <= 20; epoch++)
  {
    int errors = 0;
    for (int i = 0; i < 4; i++)
    {
      int x1 = X[i][0], x2 = X[i][1];
      int e = T[i] - predict(x1, x2);
      if (e != 0)
      {
        errors++;
      }
      w1 += lr * e * x1;
      w2 += lr * e * x2;
      b += lr * e;
    }
    printStatus(epoch, errors);
    if (errors == 0)
    {
      return;  // 다 맞힘!
    }
  }
}
void printStatus(int epoch, int errors)
{
  Serial.print("epoch ");
  Serial.print(epoch);
  Serial.print(" err ");
  Serial.print(errors);
  Serial.print(" w1 ");
  Serial.print(w1);
  Serial.print(" w2 ");
  Serial.print(w2);
  Serial.print(" b ");
  Serial.println(b);
}
 


