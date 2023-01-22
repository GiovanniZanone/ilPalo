#include <WiFiNINA.h>
#include <Arduino_MKRIoTCarrier.h>

//change these values to your Wifi name and password
const char* ssid = "";
const char* password = "";

int motionSensorPin = A5; // Pin that the motion sensor is connected to
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password); // Connect to the WiFi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP address: "); 
  Serial.println(WiFi.localIP());//insert this IP in the url of js code
  pinMode(motionSensorPin, INPUT); // Set the motion sensor pin as an input
  server.begin();
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\r');
        if (request.indexOf("GET /motion") != -1) {
          int motionDetected = digitalRead(motionSensorPin); // Read the state of the motion sensor
          if (motionDetected == HIGH) { // If motion is detected
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/plain");
            client.println("Connection: close");
            client.println();
            client.println("1");
              Serial.print("1"); 

          }
          else {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/plain");
            client.println("Connection: close");
            client.println();
            client.println("0");
            Serial.print("0"); 

          }
        }
        break;
      }
    }
    client.stop();
  }
}
