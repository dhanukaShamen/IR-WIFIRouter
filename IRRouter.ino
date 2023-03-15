#include <IRremote.h>

const byte IR_RECEIVE_PIN = 2;

void setup()
{
   Serial.begin(9600);
   IrReceiver.begin(IR_RECEIVE_PIN);
   pinMode(13, OUTPUT);
   pinMode(5,OUTPUT);
   digitalWrite(13, HIGH);
   digitalWrite(5, HIGH);
}

void loop()
{
   if (IrReceiver.decode()){
   // Serial.println(IrReceiver.decodedIRData.command, DEC);

  if(IrReceiver.decodedIRData.command==2){
    digitalWrite(13, HIGH);
    Serial.println("WIFI Router is OFF");
  }

  if(IrReceiver.decodedIRData.command==1){
    digitalWrite(13, LOW);
    Serial.println("WIFI Router is ON");
  }
    delay(500);
    IrReceiver.resume();
  }
}