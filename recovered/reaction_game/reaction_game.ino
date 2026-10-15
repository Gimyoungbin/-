int lastSw = HIGH;
bool armed = false;
bool alarming = false;


void setup() 
{
  Serial.begin(9600);
  pinMode(D4, INPUT_PULLUP);  // 스위치
  pinMode(D9, OUTPUT);        // 부저
  pinMode(D13, OUTPUT);       // 상태 LED
}


void loop()
 {
  int sw = digitalRead(D4);
  //Serial.println(sw);
 
    if (lastSw == HIGH && sw == LOW) 
    {   // 방금 눌림
    delay(20);
    armed = !armed;                    // 경보 ON / OFF
    digitalWrite(D13, armed);
        if (!armed) 
        { 
          noTone(D9); 
          alarming = false; 
        }

    }
    
    lastSw = sw;
    //버튼이 눌려있다면 실행한다
    if(armed)
    {
      int v = analogRead(A0);
      if(v > 280 && alarming == false)
      {
        //여기는 어두운 곳
        tone(D9, 1000); 
        Serial.println("Start");
        alarming = true;
      }
      if(v <= 280 && alarming == true)
      {
        //여기는 밝은 곳
        noTone(D9); 
        Serial.println("End");
        alarming = false;
      }
    
     }

   

  }
  
