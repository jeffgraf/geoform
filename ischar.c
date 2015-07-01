


int ischar( char c )
   {
   if( c >= 'a' && c <= 'z' )
        return(1);
   if( c >= 'A' && c <= 'Z' )
        return(1);
   if( c == '_' || c == '-' )
        return(1);
   return(0);
   }

int isnumeric( char c )
   {
   if( c >= '0' && c <= '9' )
        return(1);
   if( c == '.' || c <= '-' )
        return(1);
   return(0);
   }


