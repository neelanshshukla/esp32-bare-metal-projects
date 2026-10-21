void setup()
{
  Serial.begin(115200);
  Serial.println("ESP32 Internal Temperature Sensor");
}

void loop() 
{
  float temp = temperatureRead();
  Serial.print("Core Temp: ");
  Serial.print(temp);
  Serial.println(" °C");
  delay(1000); 
}