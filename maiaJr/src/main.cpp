#include <Arduino.h>

//variaveis
#define pino1 3
#define pino2 9
#define ent1 10
#define ent2 2
#define ent3 11
#define ent4 12
#define trig 5
#define ech 4
int ultimaAt;
int distancia;
const int alertadis = 40;


//funcoes
void acelerar();
void parar();
void caminho();
int getDistance();


void setup()
{

  Serial.begin(115200);
  Serial.println("Sistemas iniciando...");
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(ent1, OUTPUT);
  pinMode(ent2, OUTPUT);
  pinMode(ent3, OUTPUT);
  pinMode(ent4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(ech,INPUT);

  

}

void loop() 
{
  
  int velocidade = 500;
  analogWrite(pino1,velocidade);
  analogWrite(pino2,velocidade);
  distancia = getDistance();
  if(distancia != ultimaAt)
  {
  Serial.println(distancia);
  ultimaAt = distancia;
  }

  if(distancia > alertadis ){
    acelerar();
  }
  if(distancia < alertadis){
    parar();
    delay(1500);
    caminho();
  }
  else{
    acelerar();
  }

  

}


void acelerar()
{
  
  digitalWrite(ent1, LOW);
  digitalWrite(ent2, HIGH);
  digitalWrite(ent3, HIGH);
  digitalWrite(ent4, LOW);

}

void parar()
{

  digitalWrite(ent1,LOW);
  digitalWrite(ent2,LOW);
  digitalWrite(ent3,LOW);
  digitalWrite(ent4,LOW);

}

void caminho()
{

  digitalWrite(ent1,LOW);
  digitalWrite(ent2,HIGH);
  digitalWrite(ent3,LOW);
  digitalWrite(ent4,LOW);

}

int getDistance()
{

  int duration, distance;
  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  duration = pulseIn(ech,HIGH);
  distance = duration/58.2;
  return distance;
}