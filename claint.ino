#include <ESP8266WiFi.h>

const char* ssid = "نام شبکه وای‌فای";
const char* password = "رمز عبور شبکه وای‌فای";
const char* server_ip = "آدرس IP سرور";
const int port = 80;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (!client.connected()) {
    Serial.println("Connecting to server...");
    client.connect(server_ip, port);
    delay(1000);
    int i = 1;
    client.print(String(i));
    Serial.print("Sent to server: ");
    Serial.println(i);
  }
  if (client.connected() && client.available()) {
    String data = client.readStringUntil('\n');
    int j = data.toInt();
    Serial.print("Received from server: ");
    Serial.println(j);
  }
}
