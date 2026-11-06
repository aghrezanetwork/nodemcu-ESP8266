#include <ESP8266WiFi.h>

const char* ssid = "نام شبکه وای‌فای";
const char* password = "رمز عبور شبکه وای‌فای";
const int port = 80;

WiFiServer server(port);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.begin();
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    while (client.connected()) {
      if (client.available()) {
        String data = client.readStringUntil('\n');
        int i = data.toInt();
        Serial.print("Received from client: ");
        Serial.println(i);
        int j = 2;
        client.print(String(j));
        Serial.print("Sent to client: ");
        Serial.println(j);
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
