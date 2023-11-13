/*
  File: us_web_common.h
  Author:
  Date:

  Description: This file contains the data structures and constants for an
  ESP32-based web server and electric socket control.
  It defines the configuration, states, and project information for the system.

  License: 
  You are free to modify and distribute this code for any purpose, with or
  without changes.

  Disclaimer: 
  This code is provided as-is, without any warranty or support. Use it at your
  own risk.

  Contact: 
  For any questions or inquiries, please contact [Your Contact Information].
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_EL_STR_SIZE         16
#define DEFAULT_US_PORT         50000

#define EL_SERVER_IP            "192.168.1.201"  // Replace with the IP address of your ESP32 server
#define DEFAULT_ELEC_PORT       12345

#define BUFFER_SIZE             1024
#define SEND_MSG_SIZE           8

// Define data structures for storing configuration and states
typedef struct us_web_common {
    int us_port_no;  // Port number for the ultrasonic WiFi sensor
    int elec_port_no;  // Port number for the electric socket
    char elec_ip[MAX_EL_STR_SIZE];  // IP address for the electric socket
} us_web_common_t;

typedef struct el_socket_states {
    bool el_sock_1;  // State of electric socket 1
    bool el_sock_2;  // State of electric socket 2
} el_socket_states_t;

typedef struct full_project_info {
    us_web_common_t connection_info;  // Configuration for web server and electric socket
    el_socket_states_t el_sock_status;  // States of electric sockets
    float version_no;  // Version number of the project
} full_project_info_t;

