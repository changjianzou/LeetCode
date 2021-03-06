#include<stdlib.h>

bool isMatch(const char *s, const char *p) {

        if(s == NULL) return p == NULL;

        if(p == NULL) return s == NULL;

        const char* s_p =  NULL, *s_s = NULL;

        while(*s != '\0')
        {
            if(*p == '*'){
                s_p = p; p++; s_s = s;
            }

            else if(*p == *s || *p == '?')
            {
                p++; s++;
            }

            else
            {
                if(s_p == NULL) return false;
                p = s_p + 1;
                s_s++;
                s = s_s;
            }

        }

        while(*p)
        {
            if(*p != '*') return false; p++;
        }

        return true;
    }
