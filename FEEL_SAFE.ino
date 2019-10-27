#include <SoftwareSerial.h>
#include <VirtualWire.h>
SoftwareSerial SIM900(7, 8); //Seleccionamos los pines 7 como Rx y 8 como Tx Para arduino Uno desde

const uint8_t msg_r;          //En esta variable almacenaremos el mensage que emitira cada arduino para controlar el radio, dos calles seria lo ideal
const uint8_t msg_t;          //En esta variable almacenaremos el mensage que emitira cada arduino para controlar el radio, dos calles seria lo ideal
uint8_t dato;
uint8_t rele = 12;                 //Salida de relevador a el speaker de alerta
uint8_t level_3 = 11;                 //Salida de activacion a el speaker de alerta nivel 2
uint8_t level_2 = 10;                 //Salida de activacion a el speaker de alerta nivel 2
uint8_t level_1 = 9;                  //Salida de activacion a el speaker de alerta nivel 1
char presbtn = 'ok' ;
int sig_alar = 0;
uint8_t ident = 0;


void setup() 
{
    pinMode (level_1, OUTPUT);
    pinMode (level_2, OUTPUT);
    pinMode (level_3, OUTPUT);
    pinMode (rele, OUTPUT);
    // Se inicializa el RF
    vw_setup(2000);           // velocidad: Bits per segundo
    vw_set_tx_pin(2);         //Pin 2 como salida para el RF 
    vw_setup(2000);           // velocidad: Bits per segundo
    vw_set_rx_pin(3);         //Pin 2 como entrada del RF
    SIM900.begin(19200);      //Inicializacion de shelld para llamada a seguridad publica
    Serial.begin(19200);      //Inicializacion del sistema de llamadas
    delay(1000);              //Tiempo de espera para comenzar con el programa 
    attachInterrupt(vw_get_message((uint8_t *)dato,sizeof(dato)),contador_de_pulso,dato == presbtn);      //Por medio de interrupciones contara los pulsos para determinar el tipo de alarma
}

void loop() 
{
    
    vw_rx_start();
    uint8_t vw_get_message(uint8_t ident);
     
if(ident == 0)
{
    if(sig_alar == 1)
    {  
    const char *msg = "tvo";
    uint8_t ident = 1;
    delay(200);
    }
    else
    {
    if(sig_alar == 2)
    {  
    const char *msg = "alrt";
    uint8_t ident = 1;
    delay(200);
    }
    else
    {
    if(sig_alar == 3)
    {  
    const char *msg = "ayuda";
    uint8_t ident = 1;
    delay(200);
    }
    }
    }
    }
    else
    {
    if(ident == 1)
    {
     if(sig_alar == 1)
    {  
    const char *msg = "tvo";
    uint8_t ident = 2;
    delay(200);
    }
    else
    {
    if(sig_alar == 2)
    {  
    const char *msg = "alrt";
    uint8_t ident = 2;
    delay(200);
    }
    else
    {
    if(sig_alar == 3)
    {  
    const char *msg = "ayuda";
    uint8_t ident = 2;
    delay(200);
    }
    }
    }
    }
        else
    {
    if(ident == 2)
    {
     if(sig_alar == 1)
    {  
    const char *msg = "tvo";
    uint8_t ident = 3;
    delay(200);
    }
    else
    {
    if(sig_alar == 2)
    {  
    const char *msg = "alrt";
    uint8_t ident = 3;
    delay(200);
    }
    else
    {
    if(sig_alar == 3)
    {  
    const char *msg = "ayuda";
    uint8_t ident = 3;
    delay(200);
    }
    }
    }
    }     
    }
    }
}
 void vw_tx_start()          // Se inicia como transmisor
{
if(ident == 0)
{
    if(sig_alar == 1)
    {  
    const char *msg = "tvo";
    ident = 0;
     //Cuando funciona como emisor para conectar con otros arduinos para limitar el radio de accion
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    uint8_t vw_send(uint8_t ident = 1);
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
    }
    else
    {
    if(sig_alar == 2)
    {  
    const char *msg = "alrt";
     //Cuando funciona como emisor para conectar con otros arduinos para limitar el radio de accion
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    uint8_t vw_send(uint8_t ident = 1);
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
    }
    else
    {
    if(sig_alar == 3)
    {  
    const char *msg = "ayuda";
     //Cuando funciona como emisor para conectar con otros arduinos para limitar el radio de accion
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    uint8_t vw_send(uint8_t ident = 1);
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
    }
    }
    }
    }
    else
    {
      if(ident == 2)
      {
            if(sig_alar == 1)
    {  
    const char *msg = "tvo";
     //Cuando funciona como emisor para conectar con otros arduinos para limitar el radio de accion
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    uint8_t vw_send(uint8_t ident = 1);
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
    }
    else
    {
    if(sig_alar == 2)
    {  
    const char *msg = "alrt";
     //Cuando funciona como emisor para conectar con otros arduinos para limitar el radio de accion
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    uint8_t vw_send(uint8_t ident = 2);
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
    }
    else
    {
    if(sig_alar == 3)
    {  
    const char *msg = "ayuda";
     //Cuando funciona como emisor para conectar con otros arduinos para limitar el radio de accion
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    uint8_t vw_send(uint8_t ident = 2);
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    delay(200);
    }
    }
    }
    }
    }
    }
 





void contador_de_pulso()
{
  unsigned long tiempo_2;
  unsigned long tiempo_1 = millis();
  sig_alar ++;
  if((tiempo_1 -= tiempo_2) >5000 )
  {
    ident =0;
    return(sig_alar);
  }
  tiempo_2 = tiempo_1;  
}
