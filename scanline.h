


#include<stdio.h>


void SCAN_FILE ( char * filename ) ;


#define keyIndicator    1
#define keyEntity       2
#define keyIdentifier   3


#define DATASET_TABLE_BEGIN 4
#define DATASET_TABLE_END   5
#define DATASET_SAMPLE_COUNT   6

#define ID_REF   7
#define IDENTIFIER   8
#define DataFile   9
#define End   10

#define DATASET     20
#define DATABASE    21
#define Annotation  22
#define SUBSET      23

struct scanline {
   char * scanbuff;
   int buf_len ;
   int line_len ;
   int cur_idx  ;
   };

typedef struct scanline *SCANLINE ;

int get_entity_type( SCANLINE SC ) ;
 void   show_table_row (int line, char scratch[]) ;


void get_dataset_sample_count(SCANLINE SC ,FILE *fp) ;
void   get_dataset_table(SCANLINE SC, FILE *fp ) ;
void   load_table_row (SCANLINE SC , char scratch[]) ;
void get_identifier(SCANLINE SC ,FILE *fp) ;

int  get_identifier_type( SCANLINE SC );

