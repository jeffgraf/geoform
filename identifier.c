
#include"geoform.h"

int get_identifier_type( SCANLINE SC )
  {
  char wordbuf[40];
  int i =1;
  int j = 0;
  char c;
  while( ischar( SC-> scanbuff [ i ] ) )
     wordbuf[ j++ ] = SC->scanbuff[ i++] ;

  wordbuf[j ] = '\0';
 // printf("entity word buffer is %s\n", wordbuf );

  if ( ! strcmp( wordbuf, "ID_REF" ) )
        return( ID_REF ) ;

  if ( ! strcmp( wordbuf, "IDENTIFIER" ) )
        {
        printf("found  IDENTIFIER \n" );
        return( IDENTIFIER ) ;
        }

 /* if ( ! strcmp( wordbuf, "dataset_sample_count" ) )
        {
        printf("found  sample count \n" );
        return( DATASET_SAMPLE_COUNT ) ;
        }
 */
  
        printf("alternate  IDENTIFIER %s\n", wordbuf );
  
  return( 0 );
  }


void get_identifier(SCANLINE SC ,FILE *fp) 
   {
   int it = get_identifier_type( SC );

   if( it == IDENTIFIER )
       printf("getting IDENTIFIER \n " );
   if( it == ID_REF )
       printf("getting ID_REF \n " );

 //  printf("alternate IDENTIFIER \n " );
   }
