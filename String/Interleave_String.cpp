 bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) return false;

        //using rorational array
        bool* old_DP = new bool[s1.size() + 1];
        bool *new_DP = new bool[s1.size() + 1];
        bool* temp = NULL;

        //initial case: length = 0
        old_DP[0] = true;

        for(int i = 1; i <= s3.size(); i++)
        {
            for(int j = 0; j <= i && j <= s1.size(); j++)
            {
                //corner cases
                if(j == 0)
                {
                    new_DP[0] = s2.size() < i ? false : s2.substr(0,i) == s3.substr(0,i); continue;
                }

                if(j == i)
                {
                    new_DP[j] = s1.substr(0,i) == s3.substr(0,i); continue;
                }

                if(s2.size() < i - j) { new_DP[j] = false; continue;}

                new_DP[j] == false;

                if(s3[i-1] == s1[j-1])
                {
                    new_DP[j] = old_DP[j-1];
                }

                if(s3[i-1] == s2[i-j-1])
                {
                    new_DP[j] = new_DP[j] || old_DP[j];
                }
            }

            temp = old_DP;
            old_DP = new_DP;
            new_DP = temp;
        }

        return old_DP[s1.size()];
    }