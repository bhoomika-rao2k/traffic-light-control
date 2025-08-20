#define RED_LED 2
#define YELLOW_LED 3
#define GREEN_LED 4
#define BUZZER 5
#define ECHO_PIN 6
#define TRIG_PIN 7
#define LDR_PIN A0
long duration, distance;
int threshold = 100;
int start =0;
int front =0;


void setup() 
{
 pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool nm = NightMode();
  bool pm = PedestrianMode();
  if(!pm && !nm)
  {
    if(start==0)
    {
      digitalWrite(RED_LED, HIGH);
      delay(2000);
      digitalWrite(RED_LED, LOW);
      start =1;
      front =1;
      }
      else if (start==1 && front ==1)
      {
         digitalWrite(YELLOW_LED, HIGH);
         delay(1000);
         digitalWrite(YELLOW_LED, LOW);
         start=2;
        }
        else if (start==1 && front ==0)
        {
         digitalWrite(YELLOW_LED, HIGH);
         delay(1000);
         digitalWrite(YELLOW_LED, LOW);
         start=0;
          }
          else if (start==2)
          {
             digitalWrite(GREEN_LED, HIGH);
             delay(2000);
             digitalWrite(GREEN_LED, LOW);
            start =1;
            front =0;
            }
    }
    else if (nm && pm)
    {
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      }
    else if (nm && !pm)
    {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      }

      else if (pm && !nm)
      {
        blinkYellowLED();
        }
 

}
void blinkYellowLED() {
  for (int i = 0; i < 10; i++) {
    tone(BUZZER,260);
    digitalWrite(YELLOW_LED, HIGH);
    delay(100);
    digitalWrite(YELLOW_LED, LOW);
    delay(100);
  }
  noTone(BUZZER);
}

bool NightMode()
{
  int ldr_sensor = analogRead(LDR_PIN);
  Serial.println(ldr_sensor);
  return ldr_sensor < threshold;
  }


bool PedestrianMode()
{

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  return distance<10;
 
  }
