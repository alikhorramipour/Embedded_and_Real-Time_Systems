#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>
const int sensor = A1;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void task_LDM(void *param);
void task_LDR(void *param);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Start");
  delay(1000);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(sensor, INPUT);
  xTaskCreate(task_LDM, "LDM", 100, NULL, 1, NULL);
  xTaskCreate(task_LDR, "LDR", 100, NULL, 1, NULL);
}

void loop() {}

void task_LDM(void *param){
  (void) param;
  while(1){
    lcd.clear();
    lcd.setCursor(0, 0);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    float vout, tempc, tempf;
    vout=analogRead(sensor); //Reading the value from sensor
    vout=(vout*500)/1023;
    tempc=vout; // Storing value in Degree Celsius
    tempf=(vout*1.8)+32; // Converting to Fahrenheit
    Serial.print("in DegreeC=\t");
    Serial.print(tempc);
    Serial.print(" in Fahrenheit=\t");
    Serial.print(tempf);
    Serial.println();
    lcd.print("DegreeC=\t");
    lcd.print(tempc);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
void task_LDR(void *param){
  (void) param;
  while(1){
    lcd.clear();
    lcd.setCursor(0, 0);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    float sensorVAL;
    sensorVAL=analogRead(sensor); //Reading the value from sensor
    Serial.print("LDR=\t");
    Serial.println(sensorVAL);
    lcd.print("LED=\t");
    lcd.print(sensorVAL);
    if (sensorVAL < 20){
      digitalWrite(10,HIGH);
    }
    else{
      digitalWrite(10,LOW);
    }
    vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}
