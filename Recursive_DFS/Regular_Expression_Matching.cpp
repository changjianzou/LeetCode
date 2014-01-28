#include<stdlib.h>

//recursive
    bool isMatch(const char *s, const char *p) {

        if(s == NULL) return p == NULL;

        if(p == NULL) return s == NULL;

        if(*p == '\0') return *s == '\0';

        if(*s == '\0')
        {
            while( *p && *(p+1) )
            {
                if(*(p+1) != '*') return false;
                p += 2;
            }

            return *p == '\0';
        }


        if(*(p+1) != '*')   return ( *p == *s || *p == '.' ) && isMatch(s+1,p+1);

        if(*p == '.')
        {
            return isMatch(s,p+2) || isMatch(s+1,p);
        }else{
            return isMatch(s,p+2) || ( *p == *s  && isMatch(s+1,p) );
        }

    }
