#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

String HTML = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>WiFi-Dashboard</title>
    <style>
       body { background: white; color: #000; font-family: monospace; text-align: center; margin: 0px; }
       h1 { color: black; background-color: rgb(231, 144, 63); margin: 0px; font-size: 2.5rem; padding: 15px 0px; border-bottom: 2px solid #1e1e1d; margin-bottom: 20px; }
       .subtitle { color: #1e1e1d; font-size: 0.9rem; margin-bottom: 30px; }
       .card { background: white; border: 1px solid #ddd; box-shadow: 0 2px 5px rgba(0,0,0,0.1); border-radius: 4px; padding: 20px; margin: 15px auto; max-width: 600px; text-align: left; }
       .network { margin-bottom: 20px; } 
       .ssid { font-weight: bold; font-size: 1.1rem; color: black; margin-bottom: 5px; }
       .details { font-size: 0.9rem; color: #555; display: flex; justify-content: space-between; }
       .percent { color: #2ea043; font-weight: bold; }
   </style>
</head>

<body>
  <h1>WiFi Dashboard</h1>
  <div class="subtitle">By Neelansh Shukla</div>
  
  <div class="card" id="network-list">
    Scanning......
  </div>

   <script>
     function fetchNetworks()
      {
        fetch('/scan')
        .then(response => response.json())
        .then(data => {
          let html = '';
          if(data.length === 0)
           {
            html = '<div>No networks found.</div>';
           }
           else 
           {
            data.forEach(net => {
              let percent = Math.max(0, Math.min(100, 2 * (net.rssi + 100)));

              html += `
                <div class="network">
                  <div class="ssid">${net.ssid || 'Hidden Network'}</div>
                  <div class="details">
                    <span>Signal: ${net.rssi} dBm <span class="percent">(${percent}%)</span></span>
                    <span>Channel: ${net.channel}</span>
                  </div>
                </div>
               `;
             });
          }
          document.getElementById('network-list').innerHTML = html;
        });
     }

      fetchNetworks();
      setInterval(fetchNetworks, 5000);
  </script>
</body>
</html>)rawliteral";  // yaha HTML/CSS/JS wala part khatam

void handleRoot() 
{
  server.send(200, "text/html", HTML);
}

void handleScan() 
{
  int n = WiFi.scanNetworks();
  String json = "[";
  
  for (int i = 0; i < n; ++i) 
  {
    if (i > 0) json += ",";
    json += "{";
    json += "\"ssid\":\"" + WiFi.SSID(i) + "\",";
    json += "\"rssi\":" + String(WiFi.RSSI(i)) + ",";
    json += "\"channel\":" + String(WiFi.channel(i)); 
    json += "}";
  }
  json += "]";
  
  server.send(200, "application/json", json);
  WiFi.scanDelete();
}

void setup() 
{
  Serial.begin(115200);
  
  WiFi.softAP("WiFi_dashboard", "apn");
  WiFi.mode(WIFI_AP_STA); 
  
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/scan", handleScan); 
  server.begin();
}

void loop() 
{
  server.handleClient();
}