#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <mysql.h>
#include <time.h>


void error( char *msg ) {
  perror(  msg );
  exit(1);
}

int func( int a ) {
   return 2 * a;
}

void sendData( int sockfd, int x ) {
  int n;

  char buffer[32];
  sprintf( buffer, "%d\n", x );
  if ( (n = write( sockfd, buffer, strlen(buffer) ) ) < 0 )
    error("ERROR writing to socket");
  buffer[n] = '\0';
}

int getData( int sockfd ) {
  char buffer[32];
  int n;

  if ( (n = read(sockfd,buffer,31) ) < 0 )
    error("ERROR reading from socket");
  buffer[n] = '\0';
  return atoi( buffer );
}

typedef struct BT_retrive{
        char Time[30];
    char addr[19];
    }BT_RET;

int main(int argc, char *argv[]) {
     int sockfd, newsockfd, portno = 51716, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     int data;
     BT_RET bt;
     printf( "using port #%d\n", portno );

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
         error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));

     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons( portno );
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
       error( "ERROR on binding" );
     listen(sockfd,5);
     clilen = sizeof(cli_addr);

     //--- infinite wait on a connection ---
     while ( 1 ) {
        printf( "waiting for new client...\n" );
        if ( ( newsockfd = accept( sockfd, (struct sockaddr *) &cli_addr, (socklen_t*) &clilen) ) < 0 )
            error("ERROR on accept");
        printf( "opened new communication with client\n" );
        while ( 1 ) {

    //mysql working starts

   n = recv(newsockfd,(void*)&bt, sizeof(bt),0);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s and %s\n",bt.Time,bt.addr);

 MYSQL *conn;
   //MYSQL_ROW row;
   char *server = "localhost";
   char *user = "root";
   char *password = "1234@1234"; /* set me first */
   char *database = "Attendence";
   char statement[512];
   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }


   snprintf(statement, 512, "INSERT INTO Rpi VALUES ('%s', '%s')", bt.addr , bt.Time );

  /* send SQL query */
   if (mysql_query(conn, statement)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

// Working of several filtersss of Server****************************

  // MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *result, *res2 , *result_2, res3;
    MYSQL_ROW row, row_2, row2, row3;

    if(mysql_query(conn, "Select CURDATE()"))
       {
           fprintf(stderr, "%s\n", mysql_error(conn));
                       exit(1);
       }
    char CurDate[30];
       printf("Time Query Ran \n");
       result = mysql_store_result(conn);
       while(row = mysql_fetch_row(result))
       {
           strcpy(CurDate , row[0]);
           printf("%s \n",CurDate);
       }
       printf("%s scope check \n",CurDate);
       mysql_free_result(result);

        time_t rawtime ,t1, t2;
        struct tm * timeinfo ,tm1 ,tm2;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
    double Diffrence;
        char output[30];  //current time
    strftime(output, 30, "%Y-%m-%d %H:%M:%S", timeinfo);

    printf("%s is the current time(output) \n", output);
    char dummy[30];
    snprintf(dummy , 30, "%s 10:00:00" , CurDate);
    printf("%s is the dummy time", dummy);
    if(strptime(output, "%Y-%m-%d %H:%M:%S",&tm1) == NULL)
            printf("\nstrptime failed\n");
    if(strptime(dummy, "%Y-%m-%d %H:%M:%S",&tm2) == NULL)
            printf("\nstrptime failed\n");

    t1 = mktime(&tm1);
    t2 = mktime(&tm2);
    Diffrence = difftime(t1 ,t2);
    printf("%f time \n",Diffrence);
    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

       //MYSQL_ROW row;

   // printf("%d is difftime now\n", difftime(t2 ,t1));

      char count[512] ,Main[512];
//       char Date[12];
       //snprintf(count , 512, "insert into Attendence_Info(Slot1, Date) select id , curdate() from Faculty_Info INNER JOIN Rpi where Faculty_Info.H_Addr = Rpi.Addr && Rpi.Time BETWEEN '2013-10-19 10:00:00' AND '2013-10-23 13:00:00'");
       //printf("%s \n", count);

  //************ Case One When time is 10:00 to 13:00 ****************

       if(Diffrence>=0 && Diffrence<=10800)
       {
        printf("\n In Case 1 \n");
           char case2[512];
           snprintf(case2, 512, "select distinct id from Faculty_Info INNER JOIN Rpi where Faculty_Info.H_Addr = Rpi.Addr && Rpi.Time BETWEEN '%s 10:00:00' AND '%s 13:00:00'",CurDate ,CurDate);
           if(mysql_query(conn, case2))
           {
               fprintf(stderr, "%s\n", mysql_error(conn));
                           exit(1);
           }
        printf("\n %s \n", case2);

          printf("Select query Done \n");

            result = mysql_store_result(conn);

            while((row = mysql_fetch_row(result))!= NULL)
            {
                int i, j;
                char slot[512];

                    char Count2[512];
                    printf("%s \n", row[0]);
                    snprintf(Count2, 512,"Select count(Slot1) from Attendence_Info where Slot1 = '%s' AND Date = '%s'", row[0] , CurDate);
                    printf("%s \n",Count2);
                    if(mysql_query(conn, Count2))
                    {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                                    exit(1);
                    }

                    res2 = mysql_store_result(conn);
                    while(row2 = mysql_fetch_row(res2))
                    {
                        j = atoi(row2[0]);
                        printf("Value of row2 is :%d \n", j);

                          if(j==0)
                          {
                              printf("Ready to insert \n");
                              snprintf(slot , 512, "Insert Into Attendence_Info(Slot1, Date) values ('%s' , '%s')", row[0] , CurDate);

                            printf("\n %s \n", slot);

                            if(mysql_query(conn, slot))
                    {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                                    exit(1);
                    }
                          }

                          else
                          {
                              printf("Already there \n");
                          }
                    }
                   mysql_free_result(res2);
            }

             mysql_free_result(result);
       }

  //*********************case 2 when time is from 13:00 to 16:00***************

       if(Diffrence>=10800 && Diffrence<=21600)
       {
           char c[512];
    snprintf(c , 512, "select distinct id from Faculty_Info INNER JOIN Rpi where Faculty_Info.H_Addr = Rpi.Addr && Rpi.Time BETWEEN '%s 13:00:00' AND '%s 16:00:00'",CurDate ,CurDate);

            printf("\n %s \n", c);
           if(mysql_query(conn, c))
           {
               fprintf(stderr, "%s\n", mysql_error(conn));
                           exit(1);
           }

          printf("Select query for Case 2 Done \n");

            result = mysql_store_result(conn);

            while((row = mysql_fetch_row(result))!= NULL)
            {
                int i, j;
                char slot[512];

                    char Count2[512];
                    printf("%s \n", row[0]);
                    snprintf(Count2, 512,"Select count(Slot2) from Attendence_Info where Slot2 = '%s' AND Date = '%s'", row[0] , CurDate);
                    printf("%s \n",Count2);
                    if(mysql_query(conn, Count2))
                    {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                                    exit(1);
                    }

                    res2 = mysql_store_result(conn);
                    while(row2 = mysql_fetch_row(res2))
                    {
                        j = atoi(row2[0]);
                        printf("Value of row2 is :%d \n", j);

                          if(j==0)
                          {
                              printf("Ready to update \n");
                              snprintf(count, 512,"Select count(Slot1) from Attendence_Info where Slot1 = '%s' AND Date = '%s'", row[0] , CurDate);
                              printf("%s \n",count);
                              if(mysql_query(conn, count))
                              {
                                  fprintf(stderr, "%s\n", mysql_error(conn));
                                              exit(1);
                              }

                              int i;
                              result_2 = mysql_store_result(conn);
                              while(row_2 = mysql_fetch_row(result_2))
                              {
                                  i = atoi(row_2[0]);
                                  printf("count for case2: %d \n" ,i);
                                  if(i>0)
                                  {
                                      //update Query
                                      snprintf(slot , 512, "Update Attendence_Info set Slot2 = '%s' where Date = '%s' AND Slot1 = '%s'",row[0], CurDate ,row[0]);
                                      printf("Update Query of Case 2 = %s \n" ,slot);
                                      if(mysql_query(conn , slot))
                                      {
                                          fprintf(stderr, "%s\n", mysql_error(conn));
                                                      exit(1);
                                      }



                                  }
                                  else if(i==0)
                                  {
                                      //Insert Query
                                      snprintf(slot, 512, "insert into Attendence_Info(Slot2, Date) Values ('%s', '%s')", row[0], CurDate);

                                      printf("\n %s \n", slot);
                                      if(mysql_query(conn , slot))
                                      {
                                          fprintf(stderr, "%s\n", mysql_error(conn));
                                                      exit(1);
                                      }
                                  }

                              }
                              mysql_free_result(result_2);

                          }

                          else
                          {
                              printf("Already there in Slot2 \n");
                          }
                    }
                   mysql_free_result(res2);
            }
       mysql_free_result(result);
       }

  //***************Query For Main_Attendence***********************
       if(Diffrence == 21700)
       {
           //check for time
           snprintf(count, 512, "select Slot1 From Attendence_Info where Date ='%s' AND Slot1 = Slot2", CurDate);

			printf("\n %s \n" ,count);
           if(mysql_query(conn , count))
           {
               fprintf(stderr, "%s\n", mysql_error(conn));
                           exit(1);
           }

           result = mysql_store_result(conn);
           while(row = mysql_fetch_row(result) != NULL)
           {
               snprintf(Main ,512, "Update Attendence_Info set Main_Attendence = '%s' Where Slot1 = '%s' AND Slot2 = '%s' And Date = '%s", row[0], row[0], row[0], CurDate);
               printf("%s",Main);
               if(mysql_query(conn , count))
               {
                   fprintf(stderr, "%s\n", mysql_error(conn));
                               exit(1);
               }
           }
           mysql_free_result(result);
       }

// End of Server filters******************

   mysql_close(conn);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     }
 }

   close(newsockfd);
     return 0;
}




