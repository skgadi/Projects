

/*
DISPENSADOR SKIPUM
PROGRAMA ELABORADO POR: EMILIANO PRUNEDA 

FECHA DE INICIO: 
REVISIÓN: C 
FECHA ÚLTIMA DE REVISIÓN: 07 DE JULIO DEL 2020
*/

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27 //PARA LCD (SI NO SE VE, CAMBIAR A 0X3F)

LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7); 

#define boton1 8
#define boton2 9
#define boton3 10
#define boton4 11
#define boton5 12
#define boton6 13
#define boton7 A2

boolean CreditoReset = false;

int Rele1 = 4;
int Rele2 = 5;
int Rele3 = 6;
int Rele4 = 7;
int Rele5 = A3;
int Rele6 = A1;
int Rele7 = A0;   //Se conecta a LB4

//-----------------------SENSOR DE FLUJO YF-S201--------------------------
//Variables
volatile int NumPulsos; //variable para la cantidad de pulsos recibidos
const int PinSensor = 3;    //Sensor conectado en el pin 3, donde estaba el rele 5
float factor_conversion=7.11; //para convertir de frecuencia a caudal
float volumen = 0;
long dt=0; //variación de tiempo por cada bucle
long t0=0; //millis() del bucle anterior
//-----------------------------------------------------------------------

//------------------Función que se ejecuta en interrupción---------------
void ContarPulsos ()  
{ 
  NumPulsos++;  //incrementamos la variable de pulsos
} 

//------------------Función para obtener frecuencia de los pulsos--------
int ObtenerFrecuecia() 
{
  int frecuencia;
  NumPulsos = 0;   //Ponemos a 0 el número de pulsos
  interrupts();    //Habilitamos las interrupciones
  delay(1000);   //muestra de 1 segundo
  noInterrupts(); //Deshabilitamos  las interrupciones
  frecuencia=NumPulsos; //Hz(pulsos por segundo)
  return frecuencia;
}

int botonpresionado;

// Pin para el multimoneda
const int SignalPin = 2;
volatile int pulso = 0;

unsigned long MillisUltPulso = 0;
int PulsosAcum = 0;
int CreditoAcum = 0;
// El tiempo de pulso por cada moneda. 
int MaxTimePulse = 500; //Original 150
bool printOnceFlag = false;

// Caracteres para LCD
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

  
void setup() {

// Inicializamos la comunicacion serial, para ver los resultados en el monitor.
  Serial.begin(9600);

  //Pin del sensor de flujo
  pinMode(PinSensor, INPUT_PULLUP); 
  interrupts();
  //attachInterrupt(0,ContarPulsos,RISING);//(Interrupción 0(Pin3),función,Flanco de subida)
  attachInterrupt(digitalPinToInterrupt(PinSensor),ContarPulsos,RISING);//(Interrupción 0(Pin3),función,Flanco de subida)
  t0=millis();

    lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
    lcd.setBacklightPin(3,POSITIVE);// seteo de pata del LED de Back light
    lcd.setBacklight(HIGH);// Prendo el LED de back light

  lcd.createChar(1, smiley);
  
  lcd.createChar(2, frownie);
  
  lcd.createChar(3, armsDown);  
  
  lcd.createChar(4, armsUp); 


  //Agregamos la interrupcion con el pin indicado.
  pinMode(SignalPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SignalPin), coinInterrupt, RISING);

  pinMode (boton1, INPUT_PULLUP);
  pinMode (boton2, INPUT_PULLUP);
  pinMode (boton3, INPUT_PULLUP);
  pinMode (boton4, INPUT_PULLUP);
  pinMode (boton5, INPUT_PULLUP);
  pinMode (boton6, INPUT_PULLUP);
  pinMode (boton7, INPUT_PULLUP);
  
  pinMode(Rele1, OUTPUT);
  pinMode(Rele2, OUTPUT);
  pinMode(Rele3, OUTPUT);
  pinMode(Rele4, OUTPUT);
  pinMode(Rele5, OUTPUT);
  pinMode(Rele6, OUTPUT);
  pinMode(Rele7, OUTPUT);
  
  digitalWrite(Rele1, HIGH);
  digitalWrite(Rele2, HIGH);
  digitalWrite(Rele3, HIGH);
  digitalWrite(Rele4, HIGH);
  digitalWrite(Rele5, HIGH);
  analogWrite(Rele6, 255);
  analogWrite(Rele7, 255);

}


void coinInterrupt(){ 
  // Cuando recibe una moneda, manda pulso 
  pulso++;
  MillisUltPulso = millis();     
}


void loop() 
{
  
  digitalWrite(boton1, HIGH);
  digitalWrite(boton2, HIGH);
  digitalWrite(boton3, HIGH);
  digitalWrite(boton4, HIGH);
  digitalWrite(boton5, HIGH);
  digitalWrite(boton6, HIGH);
  analogWrite(boton7, 255);
  
  digitalWrite(Rele1, HIGH);
  digitalWrite(Rele2, HIGH);
  digitalWrite(Rele3, HIGH);
  digitalWrite(Rele4, HIGH);
  digitalWrite(Rele5, HIGH);
  analogWrite(Rele6, 255);
  analogWrite(Rele7, 255);
  
  // En cero
   if (CreditoAcum == 0) {
  lcd.clear();
  int delayTime = 400;  
  lcd.setCursor(1,0);
  lcd.print("Bienvenido a "); 
  lcd.write(1);  

  lcd.setCursor(6,1);
  lcd.print("KIPU");

  lcd.setCursor(14, 1);
  lcd.write(3); 
  
  lcd.setCursor(2, 1);  
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(2, 1);  
  lcd.write(4);
  delay(delayTime); 

  lcd.setCursor(14, 1);  
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(14, 1);  
  lcd.write(4);
  delay(delayTime); 
   }
   
//Calculamos los milisegundos de la ultima ejecusion menos el ultimo tiempo que se genero un pulso.
unsigned long lastTime = millis() - MillisUltPulso;

//Validamos si hay algun pulso, si es asi tambien se valida que el ultimo tiempo asignado sea mayor a la cantidad de milisegundos establecidos.
if((pulso > 0) && (lastTime >= MaxTimePulse)){

    PulsosAcum = pulso;
    pulso = 0;        
    CreditoAcum = CreditoAcum + PulsosAcum ; 
    printOnceFlag = true; 

}

  
  if (CreditoAcum > 0){
   lcd.clear(); //Limpio lcd
   lcd.setCursor ( 4, 0 );
   lcd.print("Credito:");
   lcd.setCursor(7,1);
   lcd.print("$");
   lcd.setCursor ( 8, 1 );
   lcd.print(CreditoAcum);
   //delay(1000);
   
  if(CreditoReset == true)
  {
    delay(5000);
    CreditoAcum = 0;
    CreditoReset = false; // Se iguala a 'false' para que pueda 
                          // leer creditos nuevamente
  }
  

  // LITRO
  // Aromas
    
   if ((CreditoAcum >= 10 && CreditoAcum <=34 )&& digitalRead(boton1) == LOW) {  
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    digitalWrite(Rele1, LOW);
    
    while(volumen < 1)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(49000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(33770);   //Original delay(33570);
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
     }

   //PINO AMARRRILLO

    if ((CreditoAcum >= 10 && CreditoAcum <=34 ) && digitalRead(boton2) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    digitalWrite(Rele2, LOW);

    while(volumen < 1)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(17000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(53000);  
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //CHLOROS
    
    if ((CreditoAcum >= 10 && CreditoAcum <=34 ) && digitalRead(boton3) == LOW) 
    {
    /*lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    digitalWrite(Rele3, LOW);*/
    
    while(volumen < 1)
    {
      digitalWrite(Rele3, LOW);
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
      /*lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Volumen");
      lcd.setCursor(0,1);
      lcd.print(volumen);*/
      //Llamada a la función que muestra los resultados en el LCD 16*2
      LCD_1602();
    }
    digitalWrite(Rele3, HIGH);
    volumen = 0;
    //delay(9500);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(24000);
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //AZULSUAVE
    
    if ((CreditoAcum >= 10 && CreditoAcum <=34 ) && digitalRead(boton4) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    digitalWrite(Rele4, LOW);

    while(volumen < 1)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(24500);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(30510);    
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //COLORES
    
    if ((CreditoAcum >= 15 && CreditoAcum <=54 ) && digitalRead(boton5) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    digitalWrite(Rele5, LOW);
    
    while(volumen < 1)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(12000);    
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //LAVATRASTES
    
    if ((CreditoAcum >= 15 && CreditoAcum <=54 ) && digitalRead(boton6) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    analogWrite(Rele6, 0);
    
    while(volumen < 1)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(9700);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(9400);    
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //JABON ZITO
    
    if ((CreditoAcum >= 15 && CreditoAcum <=54 ) && digitalRead(boton7) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Litro");
    analogWrite(Rele7, 0);
    while(volumen < 1)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    delay(11200);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(9400);    
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }
    
    ////////////////////////////GALÓN

    //AROMAS
    
       if (CreditoAcum >= 35 && digitalRead(boton1) == LOW) { 
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    digitalWrite(Rele1, LOW);
    
    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(164000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(137000);   //Original delay(122457);
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
     }

    //AMARILLO PINO

    if (CreditoAcum >= 35 && digitalRead(boton2) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    digitalWrite(Rele2, LOW);

    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(52000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(188300); 
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //CHLOROS
    
    if (CreditoAcum >= 35 && digitalRead(boton3) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    digitalWrite(Rele3, LOW);

    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(38400);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(94000);    //Original delay(106280);
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    //AZULSUAVE
    
    if (CreditoAcum >= 35 && digitalRead(boton4) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    digitalWrite(Rele4, LOW);

    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(84000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(123080);     //Original delay(70580);
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    // COLORES
    
    if (CreditoAcum >= 55 && digitalRead(boton5) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    digitalWrite(Rele5, LOW);

    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(40000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(38400);    
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }

    // LAVATRASTES
    
    if (CreditoAcum >= 55 && digitalRead(boton6) == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    analogWrite(Rele6, 0);
    
    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(39200);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(41060);    //Original delay(39660); 
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }
    
    // JABON ZITO
    
    if (CreditoAcum >= 55 && digitalRead(boton7) == 255) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Entregando...");
    lcd.setCursor(2, 1);
    lcd.print("Galon");
    analogWrite(Rele7, 0);

    while(volumen < 4)
    {
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/1000); // volumen(L)=caudal(L/s)*tiempo(s)
    }
    volumen = 0;
    //delay(40000);   //Tiempo asignado a todos para control de potencia en la bomba
    //delay(41060);    //Original delay(39660); 
    CreditoReset = true;   //Se iguala a 'true' para que en el bucle de creditos,
                         //no se acumulen y se reseteen.
    }
  }
 }

void LCD_1602()
{
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Volumen");
   lcd.setCursor(0,1);
   lcd.print(volumen);
}
     
