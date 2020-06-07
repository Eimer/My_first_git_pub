#include "server.h"

void doprocessing (int sock) {
   int n;
   char buffer[256];

while (true) {
   bzero(buffer,256);
   n = read(sock,buffer,255);
   if (n <= 0) {
      printf("\n%s", "User ");
      printf("\033[0;35m");
      printf("%d", sock);
      printf("\033[0m");
      printf("\033[0;31m");
      printf("%s", " Disconnected\n");
      printf("\033[0m");
      close(sock);
      exit(0);
   }

   printf("%s", "\033[0mTaked \033[0m");
   printf("\033[0;36m");

   for (int i = 0; buffer[i] != '\n'; i++) {
      printf("%c", buffer[i]);
   }

   printf("\033[0m from ");
   printf("\033[1;35m");
   printf("%d", sock);
   printf("\033[0m");
   printf("%c", '\n');

   n = write(sock,"Got it!\n", 8);

   if (n <= 0) {
      exit(1);
   }
}
}
