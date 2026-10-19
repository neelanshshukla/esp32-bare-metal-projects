#include <WiFi.h>
#include <WebServer.h>

// Create the WebServer object on port 80 (standard HTTP port)
WebServer server(80);

const int ledPin = 2; // Onboard LED

// This is the HTML/CSS page that will be served to the user
String HTML = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Web Server</title>
  <style>
    body { background: #0d0d0d; color: #ffffff; font-family: system-ui, sans-serif; text-align: center; padding-top: 50px; }
    h1 { color: #2ea043; }
    .btn { padding: 15px 30px; font-size: 18px; border: none; border-radius: 8px; cursor: pointer; margin: 10px; font-weight: bold; }
    .btn-on { background: #2ea043; color: white; }
    .btn-off { background: #da3633; color: white; }
  </style>
</head>
<body>
  <h1>ESP32 Web Server</h1>
  <p>Control the onboard LED from your browser!</p>
  <a href="/on"><button class="btn btn-on">Turn ON</button></a>
  <a href="/off"><button class="btn btn-off">Turn OFF</button></a>
</body>
</html>
)rawliteral";

// Function to handle the root URL "/"
void handleRoot() {
  server.send(200, "text/html", HTML);
}

// Function to handle "/on"
void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", HTML); // Reload the page
}

// Function to handle "/off"
void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", HTML); // Reload the page
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Start with LED off

  // 1. Create a WiFi Access Point
  Serial.println("Setting up Access Point...");
  WiFi.softAP("ESP32_Network", "12345678");
  
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP()); // Should be 192.168.4.1

  // 2. Link the URLs to the functions
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  // 3. Start the server
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  // Listen for incoming client requests
  server.handleClient();
}