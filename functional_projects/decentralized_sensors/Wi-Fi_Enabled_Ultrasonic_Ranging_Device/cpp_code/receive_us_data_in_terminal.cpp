/*
 * Ultrasonic Sensor Data Receiver
 * -------------------------------
 * This CPP program sets up a UDP socket to connect to an ultrasonic sensor
 * that is connected to a Wi-Fi chip. It listens on a specified port, receives
 * data from the sensor, and prints the received messages to the console.
 *
 * It provides a simple example of a UDP server that continuously listens for
 * incoming data and processes it. In this case, the data received is expected
 * to be ultrasonic sensor readings.
 *
 * Author: DelD
 * Date: 03-March-2024
 */

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 50000       // Port number for communication
#define BUFFER_SIZE 1024 // Size of the receive buffer

int main() {
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t addrLen = sizeof(cliaddr);

  // Create UDP socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Configure server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  // Bind socket to the server address
  if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Receive and print messages from the server
  char buffer[BUFFER_SIZE];
  int n;
  while (1) {
    n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr*)&cliaddr, &addrLen);
    if (n > 0) {
      buffer[n] = '\0';
      std::cout << "Received: " << buffer << std::endl;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}

