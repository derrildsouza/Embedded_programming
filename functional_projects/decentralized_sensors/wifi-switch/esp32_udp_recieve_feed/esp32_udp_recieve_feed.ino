
/*
  File: relay_control.cpp
  Author: [Your Name]
  Date: [Date]

  Description: This file contains the code for an ESP32-based device that controls relays based on UDP commands. It connects to a WiFi network, listens for UDP packets, and toggles relays based on the received commands.

  License: 
  This code is released under the Apache License 2.0. You are free to modify and distribute this code for any purpose, with or without changes. Please see the LICENSE file for the full text of the Apache License 2.0.

  Disclaimer: 
  This code is provided as-is, without any warranty or support. Use it at your own risk.

  Contact: 
  For any questions or inquiries, please contact [Your Contact Information].
*/

#include <WiFi.h>
#include <AsyncUDP.h>

#define RELAY1  15
#define RELAY2  4

const char* ssid = "your_ssid";  // Replace with your WiFi network name
const char* password = "your_password";  // Replace with your WiFi password
const int udpPort = 12345;  // Port number for UDP communication

AsyncUDP udp;
char received_data[128];

void setup() {
  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1, HIGH);
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY2, HIGH);
  delay(100);
  Serial.begin(115200);
  // Set your Static IP address
  IPAddress local_IP(192, 168, 1, 201);
  // Set your Gateway IP address
  IPAddress gateway(192, 168, 1, 1);

  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8);   //optional
  IPAddress secondaryDNS(8, 8, 4, 4); //optional
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.printf("I am listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), udpPort);

  // Start the UDP server
  if (udp.listen(udpPort)) {
    Serial.printf("UDP server started on port %d\n", udpPort);
    udp.onPacket([](AsyncUDPPacket packet) {
      // Handle incoming packet
      delay(100);
      Serial.print("Received packet from ");
      Serial.print(packet.remoteIP());
      Serial.print(":");
      Serial.print(packet.remotePort());
      Serial.print(", length: ");
      Serial.print(packet.length());
      Serial.print(", data: ");
      Serial.write(packet.data(), packet.length());
      Serial.println();
      memset(received_data, 0, sizeof(received_data));
      strncpy(received_data, (const char *)packet.data(), packet.length());
      Serial.println(received_data);
      // You can process the received data here
      if (strcmp(received_data, "R1ON") == 0){
        Serial.println("Relay 1 ON");
        digitalWrite(RELAY1, LOW);
      } else if (strcmp(received_data, "R1OFF") == 0) {
        Serial.println("Relay 1 OFF");
        digitalWrite(RELAY1, HIGH);
      } else if (strcmp(received_data, "R2ON") == 0){
        Serial.println("Relay 2 ON");
        digitalWrite(RELAY2, LOW);
      } else if (strcmp(received_data, "R2OFF") == 0) {
        Serial.println("Relay 2 OFF");
        digitalWrite(RELAY2, HIGH);
      } else if (strcmp(received_data, "ROFF") == 0) {
        Serial.println("Relays OFF");
        digitalWrite(RELAY2, HIGH);
        digitalWrite(RELAY1, HIGH);
      } else if (strcmp(received_data, "RON") == 0) {
        Serial.println("Relays ON");
        digitalWrite(RELAY1, LOW);
        digitalWrite(RELAY2, LOW);
      }
    });
  } else {
    Serial.println("Failed to start UDP server");
  }
}

void loop() {
  // Nothing to do here because we're using async callbacks
}
 
