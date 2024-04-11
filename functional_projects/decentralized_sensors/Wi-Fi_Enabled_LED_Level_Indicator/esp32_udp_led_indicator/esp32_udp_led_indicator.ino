
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

#define LED 2

#define NUM_LEDS  8

#define RED_L1    18
#define RED_L2    19
#define YELLOW_L3 21
#define YELLOW_L4 22
#define BLUE_L5   23
#define BLUE_L6   25
#define GREEN_L7  26
#define GREEN_L8  27

#define MAX_PERCENTAGE  96



const char* ssid = "ssid";  //TODO: Replace with your WiFi network name
const char* password = "psswd";  //TODO: Replace with your WiFi password
const int udpPort = 50002;  // Port number for UDP communication

unsigned int percent_value = 0;  // Variable representing percentage (0 to 100%)
const int led_pins[NUM_LEDS] = {RED_L1, RED_L2,
                                YELLOW_L3, YELLOW_L4,
                                BLUE_L5, BLUE_L6,
                                GREEN_L7, GREEN_L8};  // GPIO pins for the LEDs

AsyncUDP udp;
char received_data[128]; //TODO:set macro

void setLeds(int recd_percent) {

  // Turn OFF all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(led_pins[i], LOW);
    //delay(500);
  }

  // Set bits based on water level
  if (recd_percent >= 0 && recd_percent <= 14) {
    for (int i = 0; i < 1; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else if (recd_percent > 14 && recd_percent <= 28) {
    for (int i = 0; i < 2; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else if (recd_percent > 28 && recd_percent <= 42) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else if (recd_percent > 42 && recd_percent <= 56) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else if (recd_percent > 56 && recd_percent <= 70) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else if (recd_percent > 70 && recd_percent <= 84) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else if (recd_percent > 84 && recd_percent <= 98) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  } else {
     for (int i = 0; i < 8; i++) {
      digitalWrite(led_pins[i], HIGH);
    }
  }
#if 0
  // Update LEDs based on the LED mask
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(led_pins[i], (ledsMask >> i) & 1);
  }
 #endif
}

void setup() {

  // Set pin mode
  pinMode(LED,OUTPUT);

  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(led_pins[i], OUTPUT);
  }

  Serial.begin(115200);
  // Set your Static IP address
  IPAddress local_IP(192, 168, 1, 202); //this device IP
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
      percent_value = atoi(received_data);
      //add checks
      setLeds(percent_value);
    });
  } else {
    Serial.println("Failed to start UDP server");
  }
}

void loop() {
  // Nothing to do here because we're using async callbacks
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);

}

