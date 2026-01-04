// C++ code
int numLeds=5;
int LedPin[]={3,5,6,9,10}; //son los pines PWM
int potPin = A0; //pin del potenciometro

int division = 1024/numLeds;
int limInferior=0;
int limSuperior=0;
int pwmValor=0;
void setup()
{
  for (int i=0;i<numLeds;i++){
    pinMode(LedPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  int potValor = analogRead(potPin); //leida del valor del potenciometro
  for(int i=0;i<numLeds;i++){
    limInferior = i * division;
    limSuperior = (i+1) * division;
    
    if (potValor >= limInferior && potValor <= limSuperior ){
      pwmValor = map(potValor, limInferior,limSuperior,0,255); //map hara una rescalacion de los valores
    }else if(potValor > limSuperior){
      pwmValor=255;
    }else{
      pwmValor=0; //apaga el led sino esta en el rango
    }
    analogWrite(LedPin[i],pwmValor);
    
  }
}