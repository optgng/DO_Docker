#include <stdio.h>

#include "fcgiapp.h"

int main() {
  FCGX_Init();
  int sockfd = FCGX_OpenSocket("127.0.0.1:8080", 100);
  // int sockfd = FCGX_OpenSocket("/var/run/fcgi.sock", 100);

  FCGX_Request req;
  if (FCGX_InitRequest(&req, sockfd, 0) == 0) {
    while (FCGX_Accept_r(&req) >= 0) {
      FCGX_FPrintF(req.out, "Content-Type: text/html\n\n");
      FCGX_FPrintF(req.out, "Hello world!\n");
      FCGX_Finish_r(&req);
    }
  } else {
    printf("Error");
  }
  return 0;
}