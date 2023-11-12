#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EL_STR_SIZE         16
#define DEFAULT_US_PORT         50000

#define EL_SERVER_IP            "192.168.1.201"  // Replace with the IP address of your ESP32 server
#define DEFAULT_ELEC_PORT       12345

#define BUFFER_SIZE             1024
#define SEND_MSG_SIZE           8

// Define data structures for storing configuration and states
typedef struct us_web_common {
    int us_port_no;
    int elec_port_no;
    char elec_ip[16]; // IP address for the electric socket
} us_web_common_t;


typedef struct el_socket_states {
    bool el_sock_1;
    bool el_sock_2;
} el_socket_states_t;

typedef struct full_project_info {
    us_web_common_t connection_info;
    el_socket_states_t el_sock_status;
    float version_no;
} full_project_info_t;


