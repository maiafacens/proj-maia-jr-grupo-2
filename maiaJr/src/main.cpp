#include <Arduino.h>


//variaveis
#define pino1 3
#define pino2 9
#define ent1 10
#define ent2 2
#define ent3 11
#define ent4 12
#define trig1 5
#define ech1 4
#define trig2 6
#define ech2 7
#define trig3 13
#define ech3 8


int ultimaAt1;
int ultimaAt2;
int ultimaAt3;
int distancia_E;
int distancia_C;
int distancia_D;
const int alertadis = 40;
unsigned long tempo = 0;
const unsigned long intervalo = 1500;

//funcoes
void acelerar();
void parar();
void esquerda();
void direita();
int getDistance1();
int getDistance2();
int getDistance3();

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
  pinMode(trig1, OUTPUT);
  pinMode(ech1,INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(ech2,INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(ech3,INPUT);

  

}

void loop() 
{
  
  distancia_E = getDistance1();
  distancia_C = getDistance2();
  distancia_D = getDistance3();


  if((distancia_D <= alertadis) && (distancia_D > 5)) {
    while(millis() - tempo <= intervalo){
      parar();
      if(millis() - tempo >= intervalo){
        break;
      }
    }
    esquerda();
  }

    if((distancia_C <= alertadis) && (distancia_C > 5)) {
      while(millis() - tempo <= intervalo){
        parar();
        if(tempo >= intervalo){ 
          break;
      }
    }
    esquerda();
  }
    
      if((distancia_E <= alertadis) && (distancia_E > 5)) {
        while(millis() - tempo <= intervalo){
          
          parar();
          if(tempo >= intervalo){ 
            break;
      }
    }
    direita();
  }
  
  if((distancia_E > alertadis) && (distancia_C > alertadis) && (distancia_D > alertadis) ){
    acelerar();
  }




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


int getDistance1()
{

  int duration, distance_E;
  digitalWrite(trig1,LOW);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig1,LOW);
  duration = pulseIn(ech1,HIGH);
  distance_E = duration/58.2;
  return distance_E;

}

int getDistance2()
{
  int duration, distance_C;
  digitalWrite(trig2,LOW);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig2,LOW);
  duration = pulseIn(ech2,HIGH);
  distance_C = duration/58.2;
  return distance_C;
}

int getDistance3()
{
  int duration, distance_D;
  digitalWrite(trig3,LOW);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig3,LOW);
  duration = pulseIn(ech3,HIGH);
  distance_D = duration/58.2;
  return distance_D;
}