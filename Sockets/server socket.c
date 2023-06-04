#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(void)
{
    char server_message[] = "The server has been received";
    int server_socket;
    int client_socket;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    /*Define server address*/
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    /*Bind the socket to the specified IP and port*/
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    /*Listening for connection*/
    listen(server_socket, 5);

    client_socket = accept(server_socket, NULL, NULL);
    
    /*Send the message*/
    send(client_socket, server_message, sizeof(server_message), 0);

    /*Close the socket*/
    close(server_socket);
     
    return (0);
}