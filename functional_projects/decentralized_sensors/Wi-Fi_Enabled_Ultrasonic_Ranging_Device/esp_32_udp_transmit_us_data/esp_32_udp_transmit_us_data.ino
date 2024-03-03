/*
  File: 
  Author: DelD
  Date: 03-March-2024

  Description: This file contains the code for an ESP32-based device that reads
  data from an ultrasonic sensor and broadcasts it over UDP. It also connects
  to a WiFi network and blinks an LED to indicate data transmission.

  License:
  You are free to modify and distribute this code for any purpose,
  with or without changes.

  Disclaimer:
  This code is provided as-is, without any warranty or support.
  Use it at your own risk.

  Contact: 
  For any questions or inquiries, please contact
*/

#include "WiFi.h"
#include "AsyncUDP.h"

#define UDP_PORT            50000
#define TRANSMIT_LED_GPIO   26
#define SOUND_SPEED         0.034

const char * ssid = "your_ssid";  // Replace with your WiFi network name
const char * password = "your_password";  // Replace with your WiFi password

bool tx_led_state =  0;    // the state of the LED pin
unsigned int tx_delay_ms = 100;  // delay time in milliseconds

const int trigPin = 5;  // Pin connected to the trigger pin of the ultrasonic sensor
const int echoPin = 18;  // Pin connected to the echo pin of the ultrasonic sensor

long duration;  // Time taken for the ultrasonic wave to return
float distanceCm;  // Distance measured in centimeters

AsyncUDP udp;  // AsyncUDP instance for UDP communication
static int static_val = 0;  // Static variable for demonstration
char buffer_data[8];  // Buffer to store sensor data

/**
 * @brief Initializes the required components and connects to WiFi
 */
void setup()
{
    pinMode(TRANSMIT_LED_GPIO, OUTPUT);  // Set the transmit LED pin as an output
    digitalWrite(TRANSMIT_LED_GPIO, LOW);  // Initialize the LED as off

    Serial.begin(115200);  // Starts the serial communication
    pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

    WiFi.mode(WIFI_STA);  // Set WiFi mode to station (client)
    WiFi.begin(ssid, password);  // Connect to the WiFi network
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    if(udp.listen(UDP_PORT)) {
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
        udp.onPacket([](AsyncUDPPacket packet) {
            Serial.print("UDP Packet Type: ");
            Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
            Serial.print(", From: ");
            Serial.print(packet.remoteIP());
            Serial.print(":");
            Serial.print(packet.remotePort());
            Serial.print(", To: ");
            Serial.print(packet.localIP());
            Serial.print(":");
            Serial.print(packet.localPort());
            Serial.print(", Length: ");
            Serial.print(packet.length());
            Serial.print(", Data: ");
            Serial.write(packet.data(), packet.length());
            Serial.println();

            //reply to the client
            packet.printf("Got %u bytes of data", packet.length());
        });
    }
}

/**
 * @brief Reads the ultrasonic sensor data and stores it in the buffer
 */
void get_sensor_data()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  snprintf(buffer_data, 8, "%f", distanceCm);
}

/**
 * @brief Main loop for sending sensor data via UDP broadcast
 */
void loop()
{
    get_sensor_data();  // Read sensor data
    udp.broadcast(buffer_data);  // Send broadcast
    Serial.print(".");  // Print a dot to indicate data transmission
    transmit_delay(tx_delay_ms);  // Delay before next transmission
}

/**
 * @brief Delays the transmission and toggles the LED state
 * @param delay_val The delay time in milliseconds
 */
void transmit_delay(const unsigned int delay_val)
{
    tx_led_state = !tx_led_state;  // Toggle the LED state
    delay(delay_val/2);  // Delay half of the specified time
    digitalWrite(TRANSMIT_LED_GPIO, tx_led_state);  // Toggle the LED
    delay(delay_val/2);  // Delay the remaining time
}

