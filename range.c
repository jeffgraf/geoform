
struct range {
   int r_start ;
   int r_end ;
   };

typedef struct range *RANGE;
  

RANGE new_range()
  {
  RANGE r = (RANGE) malloc( sizeof( struct range ) ) ;
  return(r);
  
  }

RANGE initRange ( int start, int end )
   {
   RANGE r = new_range();
   r-> r_start = start;
   r-> r_end = end;
   return(r) ;
   }
