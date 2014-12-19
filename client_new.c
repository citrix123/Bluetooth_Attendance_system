//gcc client1.c-o clientMain -lbluetooth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h> // BT header
#include <time.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

typedef struct BTdata{
	char Time[30];
	char addr[19];
	}BT_INFO;

int main(int argc, char *argv[])
{
	char buff[100];
    time_t now = time (0);  
      BT_INFO bt;
	int sockfd, portno = 51717, n;
    char serverIp[] = "192.168.3.14";
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    
    while(1)
    {
    if (argc < 3) {
      // error( const_cast<char *>( "usage myClient2 hostname port\n" ) );
      printf( "contacting %s on port %d\n", serverIp, portno );
      // exit(0);
    }
    if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 )
        error( "ERROR opening socket");

    if ( ( server = gethostbyname( serverIp ) ) == NULL )
        error("ERROR, no such host\n");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");  
    while(1){
 
	//****  BT Searching starts *******    

    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };

    dev_id = hci_get_route(NULL);
    sock = hci_open_dev( dev_id );
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    len  = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    
    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("hci_inquiry");

    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), 
            name, 0) < 0)
        strcpy(name, "[unknown]");
        printf("%s  %s\n", addr, name);

    
    printf("Please enter the message: \n");
    bzero(buffer,256);
    strftime (buff, 100, "%Y-%m-%d %H:%M:%S", localtime (&now));  //time format according to mysql
    strcpy(bt.Time , buff);
	strcpy(bt.addr, addr);

    printf("%s %s\n" ,bt.Time,bt.addr);  
    //n = write(sockfd,buffer,strlen(buffer));
    n = send(sockfd,(void*)&bt,sizeof(bt),0);
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    }
    free( ii );
	close( sock );
	}
    }
    close(sockfd);
    return 0;
}
