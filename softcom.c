

#include<stdio.h>

// .soft format command processing
// for geo genome expression omnibus
//


char softfilename[140];

int softcom ( int argc, char ** argv )
  {
  if( argc != 2 )
    {
    printf("geoform error, argument  not found \n" );
    printf("usage: geoform  command_file.soft  \n" );
    return( 0 );
    }
  
  printf("softcom file: %s \n  \n", argv[1] );
   SCAN_FILE( argv[1] );
//  fp = fopen( argv[1], "r" );
  }

