enum State { WAIT, READY, GO };

State st = WAIT;

unsigned long t0, waitMs, goTime;

int stable = HIGH, lastRead = HIGH;

unsigned long tChange = 0, tDown = 0;

bool justPressed = false;

unsigned long released = 0;


// =========================
// D4 = 시작 버튼
// =========================
void readButton()
{
  justPressed = false;
  released = 0;

  int r = digitalRead(D4);

  if (r != lastRead)
  {
    lastRead = r;
    tChange = millis();
  }

  if (millis() - tChange > 20 && r != stable)
  {
    stable = r;

    if (stable == LOW)
    {
      justPressed = true;
      tDown = millis();
    }
    else
    {
      released = millis() - tDown;
    }
  }
}


// =========================
// D6 = 반응 버튼
// =========================
int last6 = HIGH;
bool hit6 = false;

void readHit()
{
  int r = digitalRead(D6);

  hit6 = (last6 == HIGH && r == LOW);

  last6 = r;
}


// =========================
// SETUP
// =========================
void setup()
{
  Serial.begin(9600);

  pinMode(D4, INPUT_PULLUP);  // 시작 버튼
  pinMode(D6, INPUT_PULLUP);  // 반응 버튼
  pinMode(D9, OUTPUT);        // 부저
  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);       // LED

  randomSeed(analogRead(A0));

  Serial.println("D4를 누르면 시작!");
}


// =========================
// LOOP
// =========================
void loop()
{
  readButton();
  readHit();

  switch (st)
  {
    // =====================
    // WAIT 상태
    // =====================
    case WAIT:

      if (justPressed)
      {
        waitMs = random(1000, 4001);
        t0 = millis();

        Serial.println("게임 시작!");
        Serial.println("WAIT...");

        digitalWrite(D13, HIGH);

        st = READY;
      }

      break;


    // =====================
    // READY 상태
    // =====================
    case READY:

      // 삐 소리 전에 D6을 누름
      if (hit6)
      {
        Serial.println("부정출발!");

        tone(D9, 200, 600);

        digitalWrite(D13, LOW);

        st = WAIT;
      }

      // 랜덤 시간이 지나면 GO
      else if (millis() - t0 >= waitMs)
      {
        Serial.println("GO!");

        tone(D9, 2000);
        digitalWrite(D12, HIGH);

        goTime = millis();

        st = GO;
      }

      break;


    // =====================
    // GO 상태
    // =====================
    case GO:

      // 삐 소리 후 D6을 누름
      if (hit6)
      {
        noTone(D9);
        digitalWrite(D12, LOW);

        digitalWrite(D13, LOW);

        Serial.print("반응시간: ");
        Serial.print(millis() - goTime);
        Serial.println(" ms");

        st = WAIT;

        Serial.println("WAIT 상태");
      }

      break;
  }
}