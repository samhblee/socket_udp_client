#include <bits/stdc++.h>
#include <sys/socket.h>
#include <strings.h>
#include <rpc/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT        2345
#define SERVER_IP   "127.0.1"

int main() {
    int s;
    int len;

    struct sockaddr_in addr;
    int addr_len;
    addr_len = sizeof(struct sockaddr_in);
    char buffer[256];
    // create socket
    if ( (s = socket( AF_INET, SOCK_DGRAM, 0  )) < 0)
    {
        perror("socket");
        exit(1);
    };

    // fill socket struct
    bzero( &addr, sizeof(addr) );
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr( SERVER_IP );
    while(1)
    {
        bzero(buffer, sizeof(buffer));
        len = read( STDIN_FILENO , buffer, sizeof(buffer) );
        sendto(s, buffer, len, 0, reinterpret_cast<const sockaddr *>(&addr), sizeof(addr));
        printf("sendto : %s", buffer);
    }

    return 0;
}
