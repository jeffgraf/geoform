

#include<stdio.h>

#include"geoform.h"

#define PLATFORM_GPL570_ROWS 54675

void  get_database();
void  get_dataset();
void  get_subset();
void  get_annotation();
void  get_platform();
void  get_samples();
void  get_series();

/*
int get_indicator( char * buffer );
int get_entity(char * id_buffer, char * buffer );
*/

int get_soft( char * buffer );
void get_carot_word( char * buffer );
int scan_for_key(  );


extern  char softfilename [];

main(int argc, char ** argv   )
  {
  int com_status = softcom( argc, argv );

  printf("filename is %s \n", softfilename );


 SCAN_FILE ( softfilename ) ;
/*
  get_database();
  get_dataset();
  get_subset();
  get_subset();
  get_annotation();
*/

 /*
  get_platform();
  get_samples();
  get_series();
*/
  }


void  get_database( SCANLINE SC )
   {
   char id_buffer[100];
   char buffer[1000];

    get_indicator(SC) ;
       printf( "\ndatabase: %s \n", buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 
    }

void  get_subset()
   {
   char id_buffer[100];
   char buffer[1000];

/*
    get_indicator(buffer) ;
       printf( "\nsubset: %s \n", buffer ); 
*/

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 
    }

void  get_annotation()
     {
    char id_buffer[100];
    char buffer[1000];
    get_carot_word(buffer) ;
       printf( "\nAnnotation: \n" ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 


   }

/*
#define keyIndicator    1
#define keyEntity       2
#define keyIdentifier   3
*/

int scan_for_key(  )
   {
   char c;
   while( c = getchar() )
     {
     switch(c)
       {
       case '^' :
         return( keyIndicator ) ;
       case '!' :
         return( keyEntity ) ;
       case '#' :
         return( keyIdentifier ) ;
       
       }// switch
     } //  while
   } //scan


/*
void  get_annotation()
   {
   char id_buffer[100];
   char buffer[1000];

    get_indicator(buffer) ;
       printf( "\nAnnotation: %s \n", buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_indicator(buffer) ;
       printf( "\nsubset: %s \n", buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    }

*/



void  get_dataset()
   {
   char id_buffer[100];
   char buffer[1000];

/*
    get_indicator(buffer) ;
       printf( "\nDataset: %s \n", buffer ); 
*/

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 
  
    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 

    get_entity(id_buffer, buffer) ;
       printf( " ent: %s = \"%s\" ;\n", id_buffer, buffer ); 
  
   }

void  get_platform()
   {
   char buffer[1000];
   while( get_soft(buffer) != -1 )
        {
        printf( "softitem: %s \n", buffer ); 
        }

  
   }

void  get_samples()
   {
   char buffer[1000];
   while( get_soft(buffer) != -1 )
        {
        printf( "softitem: %s \n", buffer ); 
        }

  
   }

void  get_series()
   {
   char buffer[1000];
   while( get_soft(buffer) != -1 )
        {
        printf( "softitem: %s \n", buffer ); 
        }
  
   }

int get_entity(char id_buffer[], char  buffer[] )
   {
   char ind_id[30] ;
   char c;
   int i = 0;
   int j = 0;
   
  // find the bang
    while( (c = getchar()) != '!' ) 
            ;

    //printf("got a bang  %c\n",c );

     while( (c=getchar()) != '=' )
            id_buffer[j++] = c ;
   id_buffer[j] = '\0' ;
         

 //   printf("got a %c \n ", c );

 //   if( getchar() == '\b' )
   //     ;
   // get any leading space 
     
     while( ( c = getchar() ) == '\b' )
            ;
 //    buffer[i++] = c;


     while( ( buffer[i++] = getchar() )!= '\n' )
            ;
     
   // printf("got a space \n" );

       buffer[i-1] = '\0' ;

   // printf("buffer is a %s \n ", buffer );


   return( 1 );
   }

void get_carot_word( char buffer[] )
   {
    int i = 0; 
     char c;
    while( (c = getchar()) != '^' ) 
           ;
    while( (c = getchar()) != '\n' ) 
           buffer[i] =c ;


   }


int process_indicator( int type, SCANLINE SC )
   {
   char temp[50];
   char equal[5];
   switch( type )
      {
      case  DataFile :
         {
       
         //printf("processing datAfile");
         sscanf( SC->scanbuff, "%s %s %s " , temp, equal,
            softfilename );
         printf(" scan results datafile %d\n", type );
         printf(" data  datafile %s\n", softfilename );
         }
      }
   return( type );
   }

int get_indicator( SCANLINE   SC )
   {
   char ind_id[30] ;
   char c;
   int i = 1;
   int ind_type;
   
  // find the carot
 //  if (  keyIndicator == scan_for_key(  ) )
   //          ;
    //else 
      // { printf("indicator not found \n" );
       //}

 //   while( (c = getchar()) != '^' ) 
   //        ;

 //   printf("got a carot  %c\n",c );

  //   while( (c=getchar()) != '=' )
   //      ;

      while ( ( c = SC->scanbuff[ i++ ] ) != '=' )
         ind_id[i-2] = c ;

      ind_id[i-3 ] = '\0' ;
           
    ind_type = get_indicator_type( ind_id );
    printf("Indicator  %s type is %d \n",ind_id, ind_type );
   



     
/*
     while( ( c = getchar() ) == '\b' )
            ;
     buffer[i++] = c;

     while( ( buffer[i++] = getchar() )!= '\n' )
            ;
*/
     
  //  printf("got a space \n" );

/*
       buffer[i] = '\0' ;
*/

   // printf("buffer is a %s \n ", buffer );


   return( ind_type );
   }

int   get_indicator_type( char ind_id[] )
      {
        printf("indicatgor type for |%s| \n", ind_id );

      if(! strcmp( ind_id, "DataFile" ) )
           return( DataFile );

      if(! strcmp( ind_id, "End" ) )
           return( End );

      if(! strcmp( ind_id, "DATABASE" ) )
           return( DATABASE );

      if(! strcmp( ind_id, "DATASET" ) )
           return( DATASET );

      if(! strcmp( ind_id, "SUBSET" ) )
           return( SUBSET );

      if(! strcmp( ind_id, "Annotation" ) )
           return( Annotation );

      return(0);
      }


int get_soft( char * buffer )
   {
   char c;
   while( c = getchar() != '!' )
     ;
     
   return( -1 );
   }



