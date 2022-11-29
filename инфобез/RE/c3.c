#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define _WINSOCK_DEPRECATED_NO_WARNINGS

    #include <winsock2.h>

    #define bzero(b, len) \
        (memset((b), '\0', (len)), (void)0)
    #define read(a, b, c) recv(a, b, c, 0)
    #define write(a, b, c) send(a, b, c, 0)
    #define close closesocket
#else
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <sys/socket.h>
    #include <unistd.h>
#endif

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

#ifdef _WIN32
    void cleanup() { WSACleanup(); }
#endif

void func(int socksfd);

int main()
{
#ifdef _WIN32
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0)
    {
        perror("WSA Startup error: \n");
        return 0;
    }

    atexit(cleanup);
#endif

    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed...\n");
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0) {
        perror("socket bind failed...\n");
        exit(0);
    }

    if ((listen(sockfd, 5)) != 0) {
        perror("Listen failed...\n");
        exit(0);
    }

    len = sizeof(cli);

    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0) {
        perror("server acccept failed...\n");
        exit(0);
    }

    func(connfd);

    close(sockfd);
    
    return 0;
}

void func(int sockfd)
{
    char buff[MAX];
    int n;
    
    for (;;) {
        bzero(buff, MAX);

        read(sockfd, buff, sizeof(buff));
        printf("From client: %s\t To client : ", buff);

        bzero(buff, MAX);
        n = 0;
        while ((buff[n++] = getchar()) != '\n') {
            ;;
        }

        write(sockfd, buff, sizeof(buff));

        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}