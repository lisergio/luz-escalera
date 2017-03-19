#include <Ultrasonic.h>

Ultrasonic ultrasubir(13,12,7540);   // (Trig,Echo)
Ultrasonic ultrabajar(11,10,7540);  // (Trig,Echo)

// para aumentar la distancia max del sensor... centímetros * 58 = Max.TimeOut 130cm*58=7540
// asi tendremos una distancia maxima de 130cm

int SensorLuz = A0;
int SensorAjusteLuz = A1;
int ValorSensorLuz= 0;
int ValorAjusteLuz=0;
int tiempo = 200;
int ValorAjusteVelocidad = A2;
int ValorAjusteDistancia = A3;
int distancia;
int reloj = 8;

int led1 = 22;
int led2 = 24;
int led3 = 26;
int led4 = 28;
int led5 = 30;
int led6 = 32;
int led7 = 34;
int led8 = 36;
int led9 = 38;
int led10 = 40;
int led11 = 42;
int led12 = 44;
int led13 = 46;
int led14 = 48;
int led15 = 50;
int led16 = 52;
int led17 = 23;


void setup() 
{
  Serial.begin(9600);
  
  pinMode (reloj,INPUT);
  
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  pinMode (led5,OUTPUT);
  pinMode (led6,OUTPUT);
  pinMode (led7,OUTPUT);
  pinMode (led8,OUTPUT);
  pinMode (led9,OUTPUT);
  pinMode (led10,OUTPUT);
  pinMode (led11,OUTPUT);
  pinMode (led12,OUTPUT);
  pinMode (led13,OUTPUT);
  pinMode (led14,OUTPUT);
  pinMode (led15,OUTPUT);
  pinMode (led16,OUTPUT);
  pinMode (led17,OUTPUT);
  
  digitalWrite (led1,LOW);
  digitalWrite (led2,LOW);
  digitalWrite (led3,LOW);
  digitalWrite (led4,LOW);
  digitalWrite (led5,LOW);
  digitalWrite (led6,LOW);
  digitalWrite (led7,LOW);
  digitalWrite (led8,LOW);
  digitalWrite (led9,LOW);
  digitalWrite (led10,LOW);
  digitalWrite (led11,LOW);
  digitalWrite (led12,LOW);
  digitalWrite (led13,LOW);
  digitalWrite (led14,LOW);
  digitalWrite (led15,LOW);
  digitalWrite (led16,LOW);
  digitalWrite (led17,LOW);  
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
Serial.print("Ajuste de Luz: ");
Serial.println(ValorAjusteLuz);
Serial.println("");
Serial.print("Valor real de luz: ");
Serial.println(ValorSensorLuz);
Serial.println("");
Serial.print("Ajuste del tiempo de cadencia: ");
Serial.print(tiempo);
Serial.println(" ms");
Serial.println("");
if (reloj == LOW)
{
  Serial.println("El estado del reloj es OFF");
  Serial.println("");
}
else
{
  Serial.println("El estado del reloj es ON"); 
  Serial.println(""); 
}
delay(50);
 if (ValorAjusteLuz > ValorSensorLuz)
  {  
    if (reloj == HIGH)
    {
      Serial.print("Ajuste de distancia: ");
      Serial.print(distancia);
      Serial.println(" cm");
      Serial.println("");
      Serial.print("Distancia medida en la subida: ");
      Serial.print(ultrasubir.Ranging(CM));
      Serial.println(" cm");
      Serial.println("");
      Serial.print("Distancia medida en la bajada: ");
      Serial.print(ultrabajar.Ranging(CM));
      Serial.println(" cm");
      Serial.println("");
      if (ultrasubir.Ranging(CM)<distancia)
      {
        subir_escaleras();
      }
      delay(50);
  
      if (ultrabajar.Ranging(CM)<distancia)
      {
        bajar_escaleras();
      }
      delay(50);
    }
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
  delay(tiempo);  
  digitalWrite (led10,HIGH);
  delay(tiempo);
  digitalWrite (led11,HIGH);
  delay(tiempo);
  digitalWrite (led12,HIGH);
  delay(tiempo);
  digitalWrite (led13,HIGH);
  delay(tiempo);
  digitalWrite (led14,HIGH);
  delay(tiempo);
  digitalWrite (led15,HIGH);
  delay(tiempo);
  digitalWrite (led16,HIGH);
  delay(tiempo);
  digitalWrite (led17,HIGH);  
  
  
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
  delay(tiempo);  
  digitalWrite (led10,LOW);
  delay(tiempo);
  digitalWrite (led11,LOW);
  delay(tiempo);
  digitalWrite (led12,LOW);
  delay(tiempo);
  digitalWrite (led13,LOW);
  delay(tiempo);
  digitalWrite (led14,LOW);
  delay(tiempo);
  digitalWrite (led15,LOW);
  delay(tiempo);
  digitalWrite (led16,LOW);
  delay(tiempo);
  digitalWrite (led17,LOW); 
}

void bajar_escaleras()
{
  digitalWrite (led17,HIGH);
  delay(tiempo);
  digitalWrite (led16,HIGH);
  delay(tiempo);
  digitalWrite (led15,HIGH);
  delay(tiempo);
  digitalWrite (led14,HIGH);
  delay(tiempo);
  digitalWrite (led13,HIGH);
  delay(tiempo);
  digitalWrite (led12,HIGH);
  delay(tiempo);
  digitalWrite (led11,HIGH);
  delay(tiempo);
  digitalWrite (led10,HIGH);
  delay(tiempo);  
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
  
  digitalWrite (led17,LOW);
  delay(tiempo);  
  digitalWrite (led16,LOW);
  delay(tiempo);  
  digitalWrite (led15,LOW);
  delay(tiempo);
  digitalWrite (led14,LOW);
  delay(tiempo);
  digitalWrite (led13,LOW);
  delay(tiempo);
  digitalWrite (led12,LOW);
  delay(tiempo); 
  digitalWrite (led11,LOW);
  delay(tiempo);
  digitalWrite (led10,LOW);
  delay(tiempo);  
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





