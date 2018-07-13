#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ioctl.h"

#define ERR(...) fprintf( stderr, "\7" __VA_ARGS__ ), exit( EXIT_FAILURE )

int main( int argc, char *argv[] ) {
   int dfd;                  // дескриптор устройства 

   if ( ( dfd = open( DEVPATH, O_RDWR ) ) < 0 )
       ERR( "Open device error: %m\n" );

   RETURN_STRING buff;

   if ( ioctl( dfd, IOCTL_GET_STRING, &buff ) )
       ERR( "IOCTL_GET_STRING error: %m\n" );

   printf( "Return string is - %s", (char*) buff.buf );

   close( dfd );

   return EXIT_SUCCESS;
};


