/*
 * Percentage setter on server
 * -----------------------
 * This C program establishes a UDP connection with an ESP32 server to set the received percentage level.
 * The program sets up a UDP socket, configures the server address, and sends the message to
 * set the percentage level.
 *
 * The server address (IP and port) is specified, and the program sends a value
 * between 0-100 as the message to the server to set the percentage level.
 *
 * Author: DelD
 * Date: 03-April-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.1.202"  // Replace with the IP address of your ESP32 server
#define SERVER_PORT 50002      // Replace with the port your ESP32 server is listening on

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

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(EXIT_FAILURE);
    }

    char message[] = "90"; // Message to send
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

