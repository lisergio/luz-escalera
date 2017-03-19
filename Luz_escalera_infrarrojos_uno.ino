


int SensorSubir = A0;
int ValorSensorSubir = 0;
int SensorBajar = A1;
int ValorSensorBajar = 0;
int SensorLuz = A2;
int ValorSensorLuz= 0;
int SensorAjusteSubir = A3;
int ValorAjusteSubir = 0;
int SensorAjusteBajar = A4;
int ValorAjusteBajar = 0;
int SensorAjusteLuz = A5;
int ValorAjusteLuz = 0;
int tiempo = 200;

int total = 0;
int x= 0;
int subir[10];
int bajar[10];
int luz;

int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;
int led6 = 9;
int led7 = 10;
int led8 = 11;
int led9 = 12;
int SubirTiempo = 2;
int BajarTiempo = 3;


void setup() 
{
Serial.begin(9600);

pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
pinMode (led4,OUTPUT);
pinMode (led5,OUTPUT);
pinMode (led6,OUTPUT);
pinMode (led7,OUTPUT);
pinMode (led8,OUTPUT);
pinMode (led9,OUTPUT);
pinMode (SubirTiempo,INPUT);
pinMode (BajarTiempo,INPUT);
  
  


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



void loop() 
{  

  //leer el valor del sensor de luz 
  
ValorSensorLuz = analogRead(SensorLuz);
  
ValorAjusteLuz = analogRead(SensorAjusteLuz); 

if (digitalRead(BajarTiempo) == LOW)
{
  if ( tiempo > 50)
  {    
    tiempo = tiempo - 25;
    delay(100);
  }
}

if ( digitalRead(SubirTiempo) == LOW)
{
  if (tiempo < 500)
  {    
  tiempo = tiempo + 25;
  delay(100);
  }
}


 //Comparar el valor de ajuste del potenciometro con el del sensor
 
 if (ValorAjusteLuz > ValorSensorLuz)
  { 
    //Leer el valor del sensor y calcular una media de 10 lecturas
    
    for (x = 0; x < 10; x= x+1)
      {
      subir[x] = analogRead(SensorSubir);
      delay(2);
      }
      x = 0;
      total = 0;
      for (x = 0 ; x < 10 ; x = x+1)
      {
      total = total + subir[x];
      }
      x = 0;
      ValorSensorSubir = total/10;
      total= 0;

    //Leer el valor del sensor y calcular una media de 10 lecturas

    for (x = 0; x < 10; x= x+1)
      {
      bajar[x] = analogRead(SensorBajar);
      delay(2);
      }
      x = 0;
      total = 0;
    for (x = 0 ; x < 10 ; x = x+1)
      {
      total = total + bajar[x];
      }
      x= 0;
      ValorSensorBajar = total/10;
      total= 0;
    
    //Guardar el valor del potenciometro de ajuste de distancia
    
    ValorAjusteSubir = analogRead(SensorAjusteSubir);
    
    //Guardar el valor del potenciometro de ajuste de distancia    
    
    ValorAjusteBajar = analogRead(SensorAjusteBajar);

    //Comparar el valor de ajuste del potenciometro con el del sensor

    if (ValorAjusteSubir < ValorSensorSubir)
      {
        
        Serial.print(ValorSensorSubir);
        Serial.print("  ");
        Serial.print(ValorAjusteSubir);
        Serial.println("");
      subir_escaleras();
      }

    //Comparar el valor de ajuste del potenciometro con el del sensor

    if (ValorAjusteBajar < ValorSensorBajar)
      {
        Serial.print(ValorSensorBajar);
        Serial.print("  ");
        Serial.print(ValorAjusteBajar);
        Serial.println("");
      bajar_escaleras();
      }

  }
    delay(30);
}
