#define pino1 3
#define pino2 9
#define ent1 10
#define ent2 2
#define ent3 11
#define ent4 12
void setup()
{
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(ent1, OUTPUT);
  pinMode(ent2, OUTPUT);
  pinMode(ent3, OUTPUT);
  pinMode(ent4, OUTPUT);

}

void loop() 
{
  int velocidade = 500;
  analogWrite(pino1,velocidade);
  analogWrite(pino2,velocidade);

  digitalWrite(ent1, HIGH);
  digitalWrite(ent2, LOW);




}