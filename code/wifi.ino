#include <ESP8266WiFi.h>

const char* ssid = "your_SSID"; // Your SSID
const char* password = "your_PASSWORD"; // Your password
IPAddress serverIP(192, 168, 1, 100); // IP address of the NodeMCU

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(10);

  // Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (!client.connect(serverIP, 80)) {
    Serial.println("Connection failed");
    delay(5000);
    return;
  }

  // Send data to NodeMCU
  client.println("Hello from Wemos D1 Mini!");

  // Read data from NodeMCU
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  delay(5000);
}
