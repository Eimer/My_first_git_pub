#include "server.h"

void doprocessing (int sock) {
   int n;
   char buffer[256];
while (true) {
   bzero(buffer,256);
   n = read(sock,buffer,255);
   if (n < 0) {
      perror("ERROR reading from socket");
      close(sock);
      exit(1);
   }

   printf("%s", "Taked ");
   printf("\033[0;36m");
   for (int i = 0; buffer[i] != '\n'; i++) {
      printf("%c", buffer[i]);
   }
   printf("\033[0m from ");
   printf("\033[1;35m");
   printf("%d", sock);
   printf("\033[0m");
   printf("%c", '\n');

   n = write(sock,"Got it!\n",8);

   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
}
}
