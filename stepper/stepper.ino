const int dirPin = 3;
const int stepPin = 4;
const int bir_turdaki_adim = 200;
int stepCounter = 0;
int pwm ;
double sp; 
void setup()
{
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop()
{
pwm = analogRead(A0);
sp = 5000-4.5*pwm;
Serial.println(sp);
geri(sp);


}


void ileri(int speedOfMotor){
  digitalWrite(dirPin, HIGH);

  // 1 turdaki adım sayısı kadar adım attırıp 360 derece döndürüyoruz
  for(int x = 0; x < bir_turdaki_adim; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(speedOfMotor);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speedOfMotor);
  }
  
  }

void geri(int speedOfMotor){
    digitalWrite(dirPin, LOW);

  
  for(int x = 0; x < bir_turdaki_adim; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(speedOfMotor);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speedOfMotor);
  }
  stepCounter = stepCounter + 1;
  //Serial.println(stepCounter);
  }
