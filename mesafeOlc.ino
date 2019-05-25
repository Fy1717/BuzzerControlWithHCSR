const int buzzer = 4 ;
const int echo = 5;
const int trig = 6;

int olcum ;
int mesafe ;
int sure;


void setup()
{
  Serial.begin(9600);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(buzzer , OUTPUT);

}

void loop()
{
  
  mesafe = MesafeOlc();
  Serial.println(mesafe);

  if(mesafe > 150)
  {
    BuzzerRun();
  }
  else
  {
     noTone(buzzer);
  }
}


int MesafeOlc(){
  digitalWrite(trig , HIGH);
  delay(5);
  digitalWrite(trig , LOW);
  sure = pulseIn(echo, HIGH);
  olcum = (sure / 2) / 28.5;
  return olcum;
}

int BuzzerRun(){
   tone(buzzer, 100);
   delay(250);
   noTone(buzzer);
   delay(250);
}

