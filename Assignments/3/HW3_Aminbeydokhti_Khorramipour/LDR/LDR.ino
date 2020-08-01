const int sensor=A2; // Assigning analog pin A0 to variable 'sensor'
int sensorVAL;
void setup() {
pinMode(sensor,INPUT); // Configuring sensor pin as input
pinMode(10, OUTPUT);
Serial.begin(9600);
}

void loop() {
sensorVAL=analogRead(sensor); //Reading the value from sensor
Serial.println(sensorVAL);
if (sensorVAL < 20){
  digitalWrite(10,HIGH);
}
else{
  digitalWrite(10,LOW);
}
delay(500); //Delay of 1 second for ease of viewing 
}
