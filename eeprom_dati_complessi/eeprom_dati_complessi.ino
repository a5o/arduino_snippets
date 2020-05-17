#include <EEPROM.h>


//preso da: https://www.settorezero.com/wordpress/salvataggio-dati-complessi-in-eeprom/

//*****************************************************************************
//Funzione per salvare dati complessi in EEPROM
//*****************************************************************************
void to_eeprom (void *ptr,unsigned char dim,unsigned char start_position)
{
 unsigned char k,mom;
 for (k=0;k<dim;k++)
 {
 mom = ((unsigned char*) ptr)[k];
 EEPROM.write(start_position+k,mom);
 }    
 
 return;
}
//*****************************************************************************
//Funzione per recuperare dati complessi in EEPROM
//*****************************************************************************
void from_eeprom (void *ptr,unsigned char dim,unsigned char start_position)
{
 unsigned char k,mom;
 for (k=0;k<dim;k++)
 {
 mom = EEPROM.read(start_position+k);
 ((unsigned char*) ptr)[k]=mom;
 }    
 
 return;
}
//**************************************************************************/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  float dato=0.00;
  to_eeprom (&dato, 4, 0x00);
}

void loop() {
  // put your main code here, to run repeatedly:
  float dato;
  from_eeprom (&dato, 4, 0x00);
  Serial.println(dato);
  delay(1000000);
}
