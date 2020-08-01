#include <Arduino_FreeRTOS.h>


void T1( void *pvParameters );
void T2( void *pvParameters );
void T3( void *pvParameters );
void T4( void *pvParameters );



const uint32_t dT1 = 30;
const uint32_t dT2 = 20;
const uint32_t dT3 = 10;
const uint32_t dT4 = 40;


void loop() {}


void setup() {
  Serial.begin(9600);
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
   Serial.print("T1 Executing");
   Serial.println("");
   vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
  }
}


void T2( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  {
    Serial.print("T2 executing");
    Serial.println("");
    vTaskDelay( 2000 / portTICK_PERIOD_MS );
  }
}


void T3( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  { 
   Serial.print("T3 Executing\n");
   Serial.println("");
   vTaskDelay( 3000 / portTICK_PERIOD_MS );
  }
}

void T4( void *pvParameters )
{
  unsigned long i = 0; 
  while(1)
  {
    Serial.print("T4 executing");
    Serial.println("");
    vTaskDelay( 4000 / portTICK_PERIOD_MS );
  }
}
