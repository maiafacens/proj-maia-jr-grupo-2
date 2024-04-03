#include <Arduino.h>
#include <NewPing.h>




//variaveis
#define pino1 6
#define pino2 5
#define ent1 13
#define ent2 12
#define ent3 3
#define ent4 4
#define max 400
int distancia_E, distancia_C, distancia_D = 0;

//sensores
NewPing sonar1(8, 8, max);
NewPing sonar2(2, 2, max);
NewPing sonar3(10, 10, max);

//funcoes
int getd1();
int getd2();
int getd3();
void acelerar();
void parar();
void re();
void esquerda();
void direita();

void setup()
{

  Serial.begin(11500);
  Serial.println("Sistemas iniciando...");
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(ent1, OUTPUT);
  pinMode(ent2, OUTPUT);
  pinMode(ent3, OUTPUT);
  pinMode(ent4, OUTPUT);

}


void loop()
{

distancia_E = getd1();
distancia_C = getd2();
distancia_D = getd3();

  if((distancia_D <= alertadis) && (distancia_D > 5)) {
        esquerda();
  }

    if((distancia_C <= alertadis) && (distancia_C > 5)) {
        esquerda();
  }
    
      if((distancia_E <= alertadis) && (distancia_E > 5)) {
        direita();
  }
  
      if((distancia_E > alertadis) && (distancia_C > alertadis) && (distancia_D > alertadis) ){
        acelerar();
  }

}

int getd1()
{
  int distancia_E;
  distancia_E = sonar1.ping_cm();
  return distancia_E;
}

int getd2()
{
  int distancia_C;
  distancia_C = sonar2.ping_cm();
  return distancia_C;
}

int getd3()
{
  int distancia_D;
  distancia_D = sonar3.ping_cm();
  return distancia_D;
}

void acelerar()
{
  analogWrite(pino1, 500);
  analogWrite(pino2, 500);
  digitalWrite(ent1, LOW);
  digitalWrite(ent2, HIGH);
  digitalWrite(ent3, HIGH);
  digitalWrite(ent4, LOW);

}

void parar()
{

  analogWrite(pino1, 500);
  analogWrite(pino2, 500);
  digitalWrite(ent1,LOW);
  digitalWrite(ent2,LOW);
  digitalWrite(ent3,LOW);
  digitalWrite(ent4,LOW);

}

void re()
{
  
  analogWrite(pino1, 500);
  analogWrite(pino2, 500);
  digitalWrite(ent1,HIGH);
  digitalWrite(ent2,LOW);
  digitalWrite(ent3,LOW);
  digitalWrite(ent4,HIGH);

}

void direita()
{
  
  analogWrite(pino1, 500);
  analogWrite(pino2, 500);
  digitalWrite(ent1,LOW);
  digitalWrite(ent2,HIGH);
  digitalWrite(ent3,LOW);
  digitalWrite(ent4,LOW);

  }

void esquerda()
{
  
  analogWrite(pino1, 500);
  analogWrite(pino2, 500);
  digitalWrite(ent1,LOW);
  digitalWrite(ent2,LOW);
  digitalWrite(ent3,HIGH);
  digitalWrite(ent4,LOW);
    
  }
