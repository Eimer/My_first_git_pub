#include "server.h"

int main() {
   int sockfd, portno, clilen;
   int newsockfd = 0;
   struct sockaddr_in serv_addr, cli_addr;
   int pid;

   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 5001;

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);

   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }

   listen(sockfd,5);
   clilen = sizeof(cli_addr);

   while (true) {
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *)&clilen);

      if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
      }
      else {
         printf("%s ", "\033[0;32mUser connected with id:\033[0;32m");
         printf("%d\n", newsockfd);
      }

      /* Create child process */
      pid = fork();

      if (pid < 0) {
         perror("ERROR on fork");
         exit(1);
      }

      if (pid == 0) {
         close(sockfd);
         doprocessing(newsockfd);
         exit(0);
      }
   }

}
