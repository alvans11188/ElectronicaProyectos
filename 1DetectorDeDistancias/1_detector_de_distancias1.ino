// C++ code
//
int trig=2;
int echo=3;
int tiempo;
int distancia;
//declarando los leds
int rojo=4;
int amarillo=5;
int verde=6;


void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(rojo,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(verde,OUTPUT);
}

void loop()
{
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  tiempo=pulseIn(echo,HIGH);
  distancia=tiempo/58.2; //este valor me permite conocer la distancia en cm
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");
  delay(500);
  
  //VERIFICACION DE LA DISTANCIA , las distancias se colocaron en 5 10 debido a que al momento de realizar la prueba fisica los valores de 100 200 etc, no eran posibles detectarlos
  if (distancia <= 5){
    digitalWrite(rojo,HIGH);
    digitalWrite(amarillo,LOW);
    digitalWrite(verde,LOW);
  }else if (distancia > 5 && distancia <= 10){
    digitalWrite(rojo,LOW);
    digitalWrite(amarillo,HIGH);
    digitalWrite(verde,LOW);
  }else{
    digitalWrite(rojo,LOW);
    digitalWrite(amarillo,LOW);
    digitalWrite(verde,HIGH);
  }
  delay(500);
}
