#include <Arduino_FreeRTOS.h>


void T1( void *pvParameters );
void T2( void *pvParameters );
void T3( void *pvParameters );
void T4( void *pvParameters );



const uint32_t dT1 = 30;
const uint32_t dT2 = 20;
const uint32_t dT3 = 10;
const uint32_t dT4 = 40;

int i=1, j=2, k=3 , z=4;


void loop() {}


void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  xTaskCreate( T1, ( const char * ) "T1", 1024, (void *)&dT1, 1 , NULL );    
  xTaskCreate( T2, ( const char * ) "T2", 1024, (void *)&dT2, 1 , NULL );
  xTaskCreate( T3, ( const char * ) "T3", 1024, (void *)&dT3, 1 , NULL );
  xTaskCreate( T4, ( const char * ) "T4", 1024, (void *)&dT4, 1 , NULL );
  vTaskStartScheduler();
}

    

/*-----------------------------------------------------------*/

void T1( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  {
   vTaskDelay( 3000*j / portTICK_PERIOD_MS );
   digitalWrite(11,HIGH);
   digitalWrite(10,LOW);
   digitalWrite(9,LOW);
   digitalWrite(8,LOW); 
   Serial.print("T1 Executing");
   Serial.println("");
   j = 4;
    
  }
}


void T2( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  {
    vTaskDelay( 3000*i / portTICK_PERIOD_MS );
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
    Serial.print("T2 executing");
    Serial.println("");
    i = 4;
  }
}


void T3( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  {
   digitalWrite(11,LOW);
   digitalWrite(10,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(8,LOW); 
   Serial.print("T3 Executing\n");
   Serial.println("");
   vTaskDelay( 3000*z / portTICK_PERIOD_MS );
   z = 4;
  }
}

void T4( void *pvParameters )
{
  unsigned long i = 0; 
  while(1)
  {
    vTaskDelay( 3000*k / portTICK_PERIOD_MS );
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    Serial.print("T4 executing");
    Serial.println("");
    k =4;
    
  }
}
