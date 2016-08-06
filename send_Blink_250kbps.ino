// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;
const int LED=5;
MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(9600);
     pinMode(LED,OUTPUT);
     digitalWrite(LED,LOW);

START_INIT:

    if(CAN_OK == CAN.begin(CAN_250KBPS,MCP_8MHz))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init ok!");
          digitalWrite(LED,HIGH);
           delay(200);
           digitalWrite(LED,LOW);
           delay(200);
           digitalWrite(LED,HIGH);
           delay(200);
           digitalWrite(LED,LOW);
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        digitalWrite(LED,HIGH);
           delay(100);
           digitalWrite(LED,false);
           delay(200);
           digitalWrite(LED,HIGH);
           delay(100);
           digitalWrite(LED,false);
           delay(200);
           digitalWrite(LED,HIGH);
           delay(800);
            digitalWrite(LED,false);
           delay(200);
        goto START_INIT;
    }
    
}

unsigned char stmpON[8] = {0,0,1,0,0,0,0,0};
unsigned char stmpOFF[8] = {0,0,0,0,0,0,0,0};

void loop()
{   Serial.println("In loop");
    // send data:  id = 0x00, standrad frame, data len = 8, stmp: data buf
    CAN.sendMsgBuf(0x80,0, 8, stmpON);
      digitalWrite(LED,HIGH);
    delay(4000);                       // send data per 100ms
     CAN.sendMsgBuf(0x80,0, 8, stmpOFF);
                          // send data per 100ms
     digitalWrite(LED,LOW);
      delay(4000);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
