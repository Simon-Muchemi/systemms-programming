#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main (void){

    /*Socket creation*/
    int network_socket;
    int connection_status;

    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    /*Specify an address for the socket*/
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002); // 9002- port to be connected to
    server_address.sin_addr.s_addr = INADDR_ANY;

    connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) ;

    if (connection_status == -1)
    {
        printf("Error in connection");
    }

    /*Receive data from the server*/
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);
    
    /*Print out data received*/
    printf("Server sent data: %s\n", server_response);

    /*Close the socket*/
    close(network_socket); 
    return (0);
}