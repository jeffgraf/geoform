
//#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include"geoform.h"



SCANLINE newScanLine ( int bufflen )
  {  
  SCANLINE SC = (SCANLINE) malloc ( sizeof(struct scanline ) );
  SC->scanbuff = malloc( bufflen * sizeof( char  ) ) ;
  SC->buf_len =  bufflen ;
  SC->line_len =  0 ;
  SC->cur_idx =  0 ;
  return(SC);
  }

char SCANLINE_TERMINATOR = '\n' ;


int loadScanLine( SCANLINE SC, FILE * fp ) 
  {
  char c;
  int i =0;
  while( (c = getc(fp ) )  !=  SCANLINE_TERMINATOR  )
     {
     if( c == EOF )
           return(EOF ) ;

     if( i > SC->buf_len )
          {
          while( (c = getc(fp))  != SCANLINE_TERMINATOR )
                  ;
            break;
          }
       
       

     SC->scanbuff[i++] = c;

     }
   SC->scanbuff[i] = '\0' ;
   SC->line_len =  i ;
   SC->cur_idx =  0 ;

   return( 1 );
  }

int scan_type ( SCANLINE SC )
    {
    char idbuffer[50];
    switch( SC->scanbuff[0] )
       {
       case '^' :
         return(keyIndicator );
       case '!' :
        if( DATASET_TABLE_BEGIN == get_entity_type( SC ) )
           return(  DATASET_TABLE_BEGIN );

        if( DATASET_TABLE_END  == get_entity_type( SC ) )
           return(  DATASET_TABLE_END );

        if( DATASET_SAMPLE_COUNT  == get_entity_type( SC ) )
           return(  DATASET_SAMPLE_COUNT );

         return(keyEntity );
       case '#' :
         return(keyIdentifier );
       }

    SC->cur_idx = 0 ;
    //SCAN_WORD ( SC, idbuffer ) ;
    //printf("SCANLINE word is %s \n ", idbuffer );



       printf("SCANLINE not identified \n" );

    exit(1);
    }




int get_entity_type( SCANLINE SC )
  {
  char wordbuf[40];
  int i =1;
  int j = 0;
  char c;
  while( ischar( SC-> scanbuff [ i ] ) )
     wordbuf[ j++ ] = SC->scanbuff[ i++] ;

  wordbuf[j ] = '\0';
 // printf("entity word buffer is %s\n", wordbuf );

  if ( ! strcmp( wordbuf, "dataset_table_end" ) )
        return( DATASET_TABLE_END ) ;

  if ( ! strcmp( wordbuf, "dataset_table_begin" ) )
        {
        printf("found  begin \n" );
        return( DATASET_TABLE_BEGIN ) ;
        }
  if ( ! strcmp( wordbuf, "dataset_sample_count" ) )
        {
        printf("found  sample count \n" );
        return( DATASET_SAMPLE_COUNT ) ;
        }
  
  
  return( 0 );
  }

int not_white( char c )
   {
   if ( c == '\t' || c == '\b' ) 
          return(0);

      else
          return(1);
    }


int SCAN_WORD ( SCANLINE SC, char  buffer[] ) 
    {
    char c;
    int i = 0 ;
    while(  not_white(
                c = SC->scanbuff[ SC->cur_idx ++ ])  )
             
            {
            buffer[i++] = c;
            if(i > 13 ) 
                break;
            }

       buffer[i] = '\0';
    //printf( "scanword len is %d\n",i );
     return(1);
    }

void SCAN_FILE ( char * filename ) 
   {
   char lbuf[34] ;
   FILE *fp = fopen( filename, "r" );
   int id_type;
   SCANLINE SC = newScanLine ( 2000  );
   printf("scanning file %s \n", filename ) ;
   while( loadScanLine( SC, fp ) != EOF )
      {
       printf("scanline is %s\n", SC->scanbuff );
      switch( scan_type ( SC ) )
         { 
         case  keyIndicator :
                {
               id_type = get_indicator( SC ) ;
               if( id_type == End  )
                  return ;
               else
                  {
             
       printf("found keyIndicator is %d \n", id_type  );
                  process_indicator( id_type, SC );
                  }
                  

               break;
             }



         case  DATASET_TABLE_BEGIN :
               {
               printf("start getting a table " );
               get_dataset_table( SC ,fp) ;
               fclose(fp);
               return;
               }

         case  DATASET_SAMPLE_COUNT :
               {
               printf(" getting a sample count " );
               get_dataset_sample_count( SC ,fp) ;
               break;

         case  keyIdentifier :
               get_identifier( SC ,fp) ;
               break;

               }
          
         
         } // switch

  /*
      strncpy( lbuf, SC->scanbuff, 25 ) ;
      lbuf[25] = '\0' ;
      printf("%s \n", lbuf);
  */
      }
   fclose(fp);
   }


int sample_count ;
void get_dataset_sample_count(SCANLINE SC, FILE *fp ) 
    {
    char buff1[30],  buff2[30];
    //SCAN_WORD ( SC, idbuffer ) ;
    sscanf ( SC->scanbuff, "%s %s %d ",buff1, buff2, &sample_count ) ;
    printf(" sample count %s %s %d \n", buff1, buff2, sample_count );
    }

void get_dataset_table(SCANLINE SC, FILE *fp ) 
  { 
  int linemax = 10;
  int line_ct = 0;
  char scratch[60];
  printf(" in get_dataset_table " );
  while( loadScanLine( SC,fp  ) != EOF )
    {
    if( line_ct ++ > linemax )
        break;

    if( DATASET_TABLE_END  == get_entity_type( SC ) )
        return;

    
    load_table_row (SC, scratch) ;
    show_table_row ( line_ct, scratch) ;
    }
   printf("all done" );
  }

 void   load_table_row (SCANLINE SC , char scratch[]) 
    {
    int tabs =0;
    int i= 0;
    char idbuffer[40]; 
    char genebuffer[40]; 
   /*
    while( i < SC->line_len ) 
         if( SC->scanbuff  [i++ ] == '\t' ) 
             tabs ++ ;
  */

    SCAN_WORD ( SC, idbuffer ) ;
    SCAN_WORD ( SC, genebuffer ) ;
    sprintf( scratch, " affyref: %s  gene %s ", idbuffer, genebuffer);
    }


 void   show_table_row (int line, char scratch[]) 
    {
    printf("%d  %s \n",line, scratch); 
    }
