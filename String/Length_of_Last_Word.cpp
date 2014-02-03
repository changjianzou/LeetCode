    int lengthOfLastWord(const char *s) {

        int cnt = 0;

        const char* h = s;

        while(*s != '\0')
        {
            if(*s !=' ')
            {
                if(s != h && *(s-1) == ' ')
                    cnt = 1;
                else
                    cnt++;
            }

            s++;
        }

        return cnt;

    }
