//Programa para el Arduino Uno usado para el control del ESC 30 A del motor de cd sin escobillas 
#include<Servo.h>

Servo ESC; //Crear un objeto de clase servo

int vel = 1000; //amplitud del pulso

void setup()
{
 //Asignar un pin al ESC
 ESC.attach(9);

 //Activar el ESC
 ESC.writeMicroseconds(1000); //1000 = 1ms
 //Cambia el 1000 anterior por 2000 si
 //tu ESC se activa con un pulso de 2ms
 delay(2000); //Esperar 5 segundos para hacer la activacion
  
 //Iniciar puerto serial
 Serial.begin(9600);
 Serial.setTimeout(10);
}


void loop()
{
  //Control de velocidad del Motor de cabeceo
   vel = analogRead(A0); //Leer un entero por serial
   vel= map(vel, 0, 1023,1000,2000); //Se mapea vel dentro de un mínimo y un máximo
   ESC.writeMicroseconds(vel); //Generar un pulso con el número recibido
}
