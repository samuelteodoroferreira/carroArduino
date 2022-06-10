// Ultrasonic_hc_sr04
#include <Ultrasonic.h>

int IN1 = 6;
int IN2 = 7;
int IN3 = 8;
int IN4 = 9;


int pino_trigger = A4;
int pino_echo = A5;
Ultrasonic ultrasonic(pino_trigger, pino_echo);


void setup() {

  Serial.begin(9600);
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
  //Le as informacoes do sensor, em cm e pol
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.println(cmMsec);
  delay(200);

  motorA_frente();
  motorB_frente();
  
  if(cmMsec <= 17){  
     motorA_tras();
     motorB_tras();
     
     if(cmMsec <= 17){
      motorA_frente();
      motorA_tras();
     }
    }
}


void parar(){
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(500);

  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(500);
}

void motorA_frente(){
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000);
}

void motorA_tras(){
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000);
}

void motorB_frente(){
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000);
}

void motorB_tras(){
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
}
