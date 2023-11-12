/*
 * Project Description:
 * ---------------------
 * This C program is part of a project that involves the control of electric switch sockets
 * based on data received from an ultrasonic distance sensor. The program establishes
 * connections with both the ultrasonic sensor and electric switch sockets, processes
 * sensor data, and controls the state of the electric sockets accordingly.
 *
 * It allows users to configure communication ports and IP addresses through command-line
 * arguments and continuously monitors the distance data from the ultrasonic sensor.
 * When predefined conditions are met, it sends commands to turn on or off the electric
 * switch sockets.
 *
 * The program demonstrates how to use UDP sockets for communication, parse command-line
 * arguments, and interact with different hardware devices for automation purposes.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include "us_web_com.h"

// Function to parse command line arguments and update configuration
int parse_cmd_args(full_project_info_t *ctx, int argc, char **argv)
{
    int us_port_no = 0;
    int socket_port_no = 0;
    char *elec_ip = NULL;  // Variable to store the electric socket IP address
    int opt = 0;
    while ((opt = getopt(argc, argv, "U:S:I:")) != -1) {
        switch(opt) {
            case (int) 'U':
                printf("case US PORT no.\n");
                us_port_no = atoi(optarg);
                break;
            case (int) 'S':
                printf("case Socket PORT no.\n");
                socket_port_no = atoi(optarg);
                break;
            case (int) 'I':
                printf("case Electric Socket IP address.\n");
                elec_ip = optarg;
                break;
            default:
                printf("Invalid\n");
                break;
        }
    }

    if (us_port_no > 0) {
        ctx->connection_info.us_port_no = us_port_no;
    } else {
        ctx->connection_info.us_port_no = DEFAULT_US_PORT;
    }
    if (socket_port_no > 0) {
        ctx->connection_info.elec_port_no = socket_port_no;
    } else {
        ctx->connection_info.elec_port_no = DEFAULT_ELEC_PORT;
    }

    if (elec_ip != NULL) {
        // Copy the provided IP address to the structure
        strncpy(ctx->connection_info.elec_ip, elec_ip, sizeof(ctx->connection_info.elec_ip));
    } else {
        // Use a default IP address if not provided
        strncpy(ctx->connection_info.elec_ip, EL_SERVER_IP, sizeof(ctx->connection_info.elec_ip));
    }
    printf("us_port_no: %d\n", ctx->connection_info.us_port_no);
    printf("socket_port_no: %d\n", ctx->connection_info.elec_port_no);
    printf("elec_ip: %s\n", ctx->connection_info.elec_ip);
    return 0;
}

// Function to receive data from the ultrasonic sensor
int get_us_data(full_project_info_t *ctx, int sockfd)
{
    char recv_buffer[BUFFER_SIZE] = {0};;
    int recv_bytes = 0;
    struct sockaddr_in recv_addr;
    socklen_t addrlen = sizeof(recv_addr);
    //Receive the messages from the server
    recv_bytes = recvfrom(sockfd, recv_buffer, BUFFER_SIZE -1, 0,
            (struct sockaddr *)&recv_addr, &addrlen);
    if (recv_bytes > 0) {
        recv_buffer[recv_bytes] = '\0';
        printf("Received: %s\t", recv_buffer);
        printf("from IP address %s\n", inet_ntoa(recv_addr.sin_addr));
        return atoi(recv_buffer);
    } else {
        printf("No remote data!!!!!\n");
        return -1;
    }
}

// Function to set up a connection to the ultrasonic sensor
int setup_us_connection(full_project_info_t *ctx)
{
    int sockfd = 0;
    struct sockaddr_in us_servaddr;

    //create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    //Configure Server address
    memset(&us_servaddr, 0, sizeof(us_servaddr));
    us_servaddr.sin_family = AF_INET;
    us_servaddr.sin_port = htons(ctx->connection_info.us_port_no);
    us_servaddr.sin_addr.s_addr = INADDR_ANY;

    //bind socket to server address
    if (bind(sockfd, (const struct sockaddr*)&us_servaddr, sizeof(us_servaddr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    return sockfd;
}

// Function to connect to an electric socket and update its state
int connect_and_update_elec_socket(full_project_info_t *ctx)
{
    int sockfd;
    struct sockaddr_in server_addr;
    char message[SEND_MSG_SIZE] = {0}; // Message to send
    int message_len = 0;

    // Create a UDP socket for communication with the electric socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set up the server address for the electric socket
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ctx->connection_info.elec_port_no);
    //server_addr.sin_addr.s_addr = INADDR_ANY;

    // Convert the IP address from a string to binary format
    if (inet_pton(AF_INET, EL_SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        return -1;
    }
    // Construct the message based on the state of the electric socket
    if (ctx->el_sock_status.el_sock_1 == 1) {
        strncpy(message, "R1ON", sizeof(message));
    } else {
        strncpy(message, "R1OFF", sizeof(message));
    }
    message_len = strlen(message);
    // Send the message to the electric socket
    // send multiple times to avoid loss of packet
    if (sendto(sockfd, message, message_len, 0, (struct sockaddr*)&server_addr,
                                    sizeof(server_addr)) == -1) {
        perror("Error sending message");
        close(sockfd);
        return -1;
    }

    printf("Message sent to server: %s\n", message);
    // Close the socket for the electric socket
    close(sockfd);

    return 0;
}

// Function to check and update the state based on ultrasonic sensor data
bool check_and_update_state(full_project_info_t *ctx, int us_val)
{
    static unsigned int status_flag = 0;

    if ((us_val < 20) && (status_flag == 1)) {
        ctx->el_sock_status.el_sock_1 = 0;
        status_flag = 0;
    } else if ((us_val > 200) && (status_flag == 0)) {
        ctx->el_sock_status.el_sock_1 = 1;
        status_flag = 1;
    } else {
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    int us_sockfd = 0;
    int distance_val = 0;
    int el_sockfd = 0;
    char set_state[MAX_EL_STR_SIZE] = {0};
    bool change_state = 0;
    full_project_info_t ctx = {0};
    memset(&ctx, 0, sizeof(ctx));
    parse_cmd_args(&ctx, argc, argv);

    /* create connection with ultrasonic distance sensor */
    us_sockfd = setup_us_connection(&ctx);

    while (1) {
        /* Receive ultrasonic sensor data */
        distance_val = get_us_data(&ctx, us_sockfd);
        printf("distance_val: %d\n", distance_val);

        // Check and update the state based on the received data
        change_state = check_and_update_state(&ctx, distance_val);
        if (change_state == 1) {
            // Create a connection with an electric switch socket and change its state
            el_sockfd = connect_and_update_elec_socket(&ctx);
        }
    }

    // Close the ultrasonic sensor socket
    close(us_sockfd);
    return 0;
}
