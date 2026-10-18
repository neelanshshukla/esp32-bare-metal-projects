void setup() 
{
  // Set GPIO 2 as an output (the onboard LED)
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);   // Turn the LED on
  delay(1000);             // Wait 1 second
  digitalWrite(2, LOW);    // Turn the LED off
  delay(1000);             // Wait 1 second
}