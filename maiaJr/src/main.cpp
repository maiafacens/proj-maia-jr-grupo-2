#define TRIG_PIN 5
#define ECHO_PIN 2
#define ini1 10
#define ini2 9
#define ini3 11
#define ini4 12
#define distancemax 400
#define alertdis 30
#define VELOCITY  90
#define VELOCITY_BACK 70
#define port1 13
#define port2 2

String message = "";

int ultimaAt;

//functions
int getDistance();
void velocity(int vel);
void goFoward();
void findWay();
//variable of motor speeds
int motor1sp, motor2sp = 0;

//config
void setup() {

    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN,INPUT);
    pinMode(port1, OUTPUT);
    pinMode(port2, OUTPUT);
    pinMode(ini1, OUTPUT);
    pinMode(ini2,OUTPUT);
    pinMode(ini3,OUTPUT);
    pinMode(ini4,OUTPUT);

    velocity(VELOCITY);
}

//repeat code
void loop() {

  int distance = getDistance();
  if(distance != ultimaAt){
    Serial.println(distance);
    ultimaAt = distance;
  }

  if ((distance > alertdis) && (distance < 0)){
    goFoward();
    velocity(VELOCITY);
  }
  if((distance < alertdis) && (distance > 5)){
    findWay();
  }
  else if ((distance < 0) || (distance > alertdis))
  {
    goFoward();
  }
  else{
  velocity(VELOCITY);
  }
}

//scan distance sensor
int getDistance(){
  int distance, duration = 0;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration/58.2;

  delay(10);
  return distance;


}

void goFoward(){
  message ="Foward";

  //set Motor 1 On foward
  digitalWrite(ini2,HIGH);
  digitalWrite(ini1,LOW);

  //set Motor 2 On foward
  digitalWrite(ini3, HIGH);
  digitalWrite(ini4, LOW);

  Serial.println(message);
}

void velocity(int vel){
  analogWrite(port1, vel);
  analogWrite(port2, vel);
}

void findWay(){

  message = "find a way!";

  //Set motor 1 
  digitalWrite(ini1,HIGH);
  digitalWrite(ini2,LOW);

  //set motor 2
  digitalWrite(ini3,LOW);
  digitalWrite(ini4,LOW);

  Serial.println(message);
}