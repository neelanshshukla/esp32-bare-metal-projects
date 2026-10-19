const int buttonPin = 0;
const int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
    pinMode(ledPin, OUTPUT); // set LED as OUTPUT

    pinMode(buttonPin, INPUT_PULLUP);

    Serial.begin(115200);
    Serial.println("Press the BOOT button!");
}

void loop() {
  // put your main code here, to run repeatedly:
   int buttonState = digitalRead(buttonPin);

   if(buttonState == LOW)
   {
    digitalWrite(ledPin, HIGH);
    Serial.println("Button is pressed! LED ON.");
   }
   else
   {
    digitalWrite(ledPin, LOW);
   }

   delay(50);
}
