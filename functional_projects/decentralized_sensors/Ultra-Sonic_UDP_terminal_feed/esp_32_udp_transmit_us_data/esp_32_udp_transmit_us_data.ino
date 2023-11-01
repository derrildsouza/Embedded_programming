#include "WiFi.h"
#include "AsyncUDP.h"

const char * ssid = "";
const char * password = "";
#define UDP_PORT        50000

#define TRANSMIT_LED_GPIO 26

bool tx_led_state =  0;    // the number of the LED pin
unsigned int tx_delay_ms = 100;

const int trigPin = 5;
const int echoPin = 18;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;


AsyncUDP udp;
static int static_val = 0;
char buffer_data[8];
int i =0;

void setup()
{
      pinMode(TRANSMIT_LED_GPIO, OUTPUT);
    digitalWrite(TRANSMIT_LED_GPIO, LOW);
    
    Serial.begin(115200); // Starts the serial communication
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    
    //Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
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
            //for (i = 0; i< 30; i++) {
            //snprintf(buffer_data, 8, "%d", static_val);
            //packet.printf(buffer_data);
            //static_val++;
            //delay(1000);
            //}
        });
    }
}

void get_sensor_data()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance in the Serial Monitor
 // Serial.print("Distance (cm): ");
  //Serial.println(distanceCm);
  snprintf(buffer_data, 8, "%f", distanceCm);
  //Serial.print("Distance (inch): ");
  //Serial.println(distanceInch);


}
void loop()
{
    get_sensor_data();
    //Send broadcast
    udp.broadcast(buffer_data);
    Serial.print(".");
    transmit_delay(tx_delay_ms);
}
void transmit_delay(const unsigned int delay_val)
{
    tx_led_state = !tx_led_state;

    delay(delay_val/2);
    digitalWrite(TRANSMIT_LED_GPIO, tx_led_state);
    delay(delay_val/2);

}
