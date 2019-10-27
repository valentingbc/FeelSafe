#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522
int cont = 0;
long tiempo = 0;
bool reseteo = false;

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación  serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos  el MFRC522
  Serial.println("Lectura del UID");
  tiempo = millis();
}

void loop() {

  //Si leemos la tarjeta
  //Verificamos que siga dentro de 5 segundos
    //Si es asi, aumentamos el contador
  //Si no
    //se reinicia contador y vuelve a estar habilitado 
  
  // Revisamos si hay nuevas tarjetas  presentes
  if ((tiempo + 5000) > millis())
  {
    if ( mfrc522.PICC_IsNewCardPresent())
    {
      cont++;
      Serial.print(cont);
      switch (cont)
      {
        case 1:
          Serial.println(" Nivel 1, sirena corta");
          tiempo = millis();
          break;
        case 2:
          Serial.println("Nivel 2, sirena constante");

          break;
        case 3:
          Serial.println("Nivel 3, alarma de auxilio, msn al 911");

          break;

      }
      //Seleccionamos una tarjeta
      if ( mfrc522.PICC_ReadCardSerial())
      {

        Serial.println();
        // Terminamos la lectura de la tarjeta  actual
        mfrc522.PICC_HaltA();
      }
    }
  }
  else
  {
    Serial.println(String(cont) + " veces leido");
    cont = 0;
    tiempo = millis();
  }
}
