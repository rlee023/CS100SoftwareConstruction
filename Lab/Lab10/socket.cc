#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

#define SERV_PATH "./serv.txt"

using namespace std;

void client()
{
    sleep(5);

    int portno, sockfd, newsockfd; 
    struct sockaddr_un cli_addr;
    struct sockaddr_un serv_addr; 
    int n, servlen, clilen;
    
    //create a socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    //init
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SERV_PATH);
    servlen =strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
    
    //connect
    if (connect(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0)
        cout<<"Client failed. Couldn't connect" << endl;

    //read 
    int toRead;
    int amountRead;
    while (amountRead = read(sockfd, &toRead, sizeof(int)))
    {
    	cout << "YO\n";
        if (amountRead < 0)
            cout << "Client Read Error" << endl;
        cout << toRead <<endl;
        sleep(1);
    }

    close(sockfd);

    exit(0);
}

void server(int pid)
{
    struct sockaddr_un serv_addr, cli_addr;
    int  n, servlen;
    int sockfd, newsockfd, portno, clilen;

    //creat socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    //init
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SERV_PATH);
    unlink(serv_addr.sun_path);
    servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

    //bind
    if (bind(sockfd, (struct sockaddr*)&serv_addr, servlen) < 0)
        cout << "Server can't bind" << endl;
    int status; 
    //listen
    if (listen(sockfd, 5) < 0)
        cout << "Couldn't listen..." << endl;
    
    //accept
    int newsocketfd;
    if ((newsocketfd = accept(sockfd, (struct sockaddr*) &cli_addr, (socklen_t*) &clilen)) < 0)
        cout << "Server can't accept..." << endl;

    //write
    int buffer[256];
    for (size_t i=0; i< 200; ++i)
        buffer[i] = i+1;
    int written;
    if ((written = write(newsocketfd, buffer, sizeof(int)*10)) < 0)
        cout << "Server could not write" << endl;
    wait(&pid);
    close(newsocketfd);
    close(sockfd);

    waitpid(pid, NULL, 0);
}

int main()
{
    
    int pid = fork();
    int status; 

    if (pid < 0)
    {
        cout<<"Fork Failed "<<endl;
        exit(1);
    }
    if(pid == 0){
    	wait(&status); 
        client();
    }
    else if(pid > 0){
        server(pid);
     }
}
