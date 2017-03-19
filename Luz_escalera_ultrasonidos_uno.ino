#include <Ultrasonic.h>

Ultrasonic ultrasubir(13,12,6031);   // (Trig,Echo)
Ultrasonic ultrabajar(11,10,6031);  // (Trig,Echo)

// para aumentar la distancia max del sensor... centímetros * 58 = Max.TimeOut 130cm*58=7540
// asi tendremos una distancia maxima de 130cm

int SensorLuz = A0;
int SensorAjusteLuz = A1;
int ValorSensorLuz;
int ValorAjusteLuz;
int tiempo;
int ValorAjusteVelocidad = A2;
int ValorAjusteDistancia = A3;
int distancia;

int led1 = 0;
int led2 = 1;
int led3 = 2;
int led4 = 3;
int led5 = 4;
int led6 = 5;
int led7 = 6;
int led8 = 7;
int led9 = 8;

void setup() 
{
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  pinMode (led5,OUTPUT);
  pinMode (led6,OUTPUT);
  pinMode (led7,OUTPUT);
  pinMode (led8,OUTPUT);
  pinMode (led9,OUTPUT);
  
  digitalWrite (led1,LOW);
  digitalWrite (led2,LOW);
  digitalWrite (led3,LOW);
  digitalWrite (led4,LOW);
  digitalWrite (led5,LOW);
  digitalWrite (led6,LOW);
  digitalWrite (led7,LOW);
  digitalWrite (led8,LOW);
  digitalWrite (led9,LOW);
}

void loop()
{
  ValorSensorLuz = analogRead(SensorLuz);  
  ValorAjusteLuz = analogRead(SensorAjusteLuz);
  distancia = analogRead(ValorAjusteDistancia)/10; 
  tiempo = analogRead(ValorAjusteVelocidad);
  if (tiempo<250)
  {
    tiempo=250;
  }
 if (ValorAjusteLuz > ValorSensorLuz)
  {   
    if (ultrasubir.Ranging(CM)<distancia)
    {
      subir_escaleras();
    }
    delay(20);

    if (ultrabajar.Ranging(CM)<distancia)
    {
      bajar_escaleras();
    }
    delay(20);
  }
}


void subir_escaleras()
{
  digitalWrite (led1,HIGH);
  delay(tiempo);
  digitalWrite (led2,HIGH);
  delay(tiempo);
  digitalWrite (led3,HIGH);
  delay(tiempo);
  digitalWrite (led4,HIGH);
  delay(tiempo);
  digitalWrite (led5,HIGH);
  delay(tiempo);
  digitalWrite (led6,HIGH);
  delay(tiempo);
  digitalWrite (led7,HIGH);
  delay(tiempo);
  digitalWrite (led8,HIGH);
  delay(tiempo);
  digitalWrite (led9,HIGH);
  
  delay(5000);
  
  digitalWrite (led1,LOW);
  delay(tiempo);  
  digitalWrite (led2,LOW);
  delay(tiempo);
  digitalWrite (led3,LOW);
  delay(tiempo);
  digitalWrite (led4,LOW);
  delay(tiempo);
  digitalWrite (led5,LOW);
  delay(tiempo); 
  digitalWrite (led6,LOW);
  delay(tiempo);
  digitalWrite (led7,LOW);
  delay(tiempo);
  digitalWrite (led8,LOW);
  delay(tiempo);
  digitalWrite (led9,LOW);

}

void bajar_escaleras()
{
  digitalWrite (led9,HIGH);
  delay(tiempo);
  digitalWrite (led8,HIGH);
  delay(tiempo);
  digitalWrite (led7,HIGH);
  delay(tiempo);
  digitalWrite (led6,HIGH);
  delay(tiempo);
  digitalWrite (led5,HIGH);
  delay(tiempo);
  digitalWrite (led4,HIGH);
  delay(tiempo);
  digitalWrite (led3,HIGH);
  delay(tiempo);
  digitalWrite (led2,HIGH);
  delay(tiempo);
  digitalWrite (led1,HIGH);
  
  delay(5000);
  
  digitalWrite (led9,LOW);
  delay(tiempo);  
  digitalWrite (led8,LOW);
  delay(tiempo);  
  digitalWrite (led7,LOW);
  delay(tiempo);
  digitalWrite (led6,LOW);
  delay(tiempo);
  digitalWrite (led5,LOW);
  delay(tiempo);
  digitalWrite (led4,LOW);
  delay(tiempo); 
  digitalWrite (led3,LOW);
  delay(tiempo);
  digitalWrite (led2,LOW);
  delay(tiempo);
  digitalWrite (led1,LOW);
}

