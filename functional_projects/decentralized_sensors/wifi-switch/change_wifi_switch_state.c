/*
 * ESP32 Electric Socket Control
 * ------------------------------
 * This C program communicates with an ESP32 server using UDP to control an electric
 * socket. It sends commands ("R1ON" to turn on and "R1OFF" to turn off) to control
 * the state of the electric socket. The program sets up a UDP socket, configures
 * the server address, and sends the appropriate command to the server to control
 * the socket.
 *
 * The server address (IP and port) is specified, and the program sends "R1ON" to
 * turn on the electric socket or "R1OFF" to turn it off. This program is an example
 * of a UDP client for remote control of an electric socket via an ESP32 device or
 * any other network server.
 *
 * Author:
 * Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.1.201"  // Replace with the IP address of your ESP32 server
#define SERVER_PORT 12345      // Replace with the port your ESP32 server is listening on

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    //server_addr.sin_addr.s_addr = INADDR_ANY;

#if 1
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(EXIT_FAILURE);
    }
#endif

    char message[] = "ROFF"; // Message to send
    int message_len = strlen(message);

    // Send the message to the server
    if (sendto(sockfd, message, message_len, 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error sending message");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server: %s\n", message);

    // Close the socket
    close(sockfd);

    return 0;
}

