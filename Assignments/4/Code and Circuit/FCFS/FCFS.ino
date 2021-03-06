#include <Arduino_FreeRTOS.h>


void T1( void *pvParameters );
void T2( void *pvParameters );
void T3( void *pvParameters );
void T4( void *pvParameters );

int i=4,j=1,k=2,z=3;

void loop() {}


void setup() {
  Serial.begin(9600);
  xTaskCreate( T1, ( const char * ) "T1", 1024, NULL, 1 , NULL );    
  xTaskCreate( T2, ( const char * ) "T2", 1024, NULL, 2 , NULL );
  xTaskCreate( T3, ( const char * ) "T3", 1024, NULL, 3 , NULL );
  xTaskCreate( T4, ( const char * ) "T4", 1024, NULL, 4 , NULL );
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
   vTaskDelay( 3000*i / portTICK_PERIOD_MS );
  }
}


void T2( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  {
     vTaskDelay( 3000*j / portTICK_PERIOD_MS );
    Serial.print("T2 executing");
    Serial.println("");
    j = 4;
  }
}


void T3( void *pvParameters )
{
  (void) pvParameters;
  while(1)
  { 
     vTaskDelay( 3000*k / portTICK_PERIOD_MS );
   Serial.print("T3 Executing\n");
   Serial.println("");
   k = 4;
  }
}

void T4( void *pvParameters )
{
  unsigned long i = 0; 
  while(1)
  {
    vTaskDelay( 3000 * z / portTICK_PERIOD_MS );
    Serial.print("T4 executing");
    Serial.println("");
    z = 4;
  }
}
