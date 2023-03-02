//BTS7960 1
#define RPWM 2
#define LPWM 3
#define REN 4
#define LEN 5

//BTS7960 2
#define RPWMO 6
#define LPWMO 7
#define RENO 8
#define LENO 9


int pot;
int pot1;
int out1;
int out2;
int out3;
int out4;

void setup()
{
  Serial.begin(9600);
  pinMode(RPWM,OUTPUT);
  pinMode(LPWM,OUTPUT);
  pinMode(LEN,OUTPUT);
  pinMode(REN,OUTPUT);
  digitalWrite(REN,HIGH);
  digitalWrite(LEN,HIGH);

  pinMode(RPWMO,OUTPUT);
  pinMode(LPWMO,OUTPUT);
  pinMode(LENO,OUTPUT);
  pinMode(RENO,OUTPUT);
  digitalWrite(RENO,HIGH);
  digitalWrite(LENO,HIGH);
}

void loop()
{
  pot=analogRead(A0);
  if(pot>512)
  {
    out1=map(pot,512,1023,0,255);
    analogWrite(RPWM,out1);
    analogWrite(LPWM,0);
    analogWrite(RPWMO,out1);
    analogWrite(LPWMO,0);
  }
 
  if(pot<512)
  {
    out2=map(pot,512,0,0,255);
    analogWrite(LPWM,out2);
    analogWrite(RPWM,0);
    analogWrite(LPWMO,out2);
    analogWrite(RPWMO,0);
  }

  pot1=analogRead(A1);
  if(pot1>512)
  {
    out3=map(pot1,512,1023,0,255);
    analogWrite(RPWM,out3);
    analogWrite(LPWM,0);
    analogWrite(RPWMO,0);
    analogWrite(LPWMO,out3);
  }
 
  if(pot1<512)
  {
    out4=map(pot1,512,0,0,255);
    analogWrite(LPWM,out4);
    analogWrite(RPWM,0);
    analogWrite(LPWMO,0);
    analogWrite(RPWMO,out4);
  }
}
