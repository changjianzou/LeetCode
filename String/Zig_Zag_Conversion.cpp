#include<string>

using namespace std;

string convert(string s, int nRows) {

        if(nRows <= 1) return s;

        string ret;

        //first row
        int i = 0, mod = 2*nRows - 2;
        while(i*mod < s.size()) {ret.push_back(s[mod*i]); i++;}

        //middle rows
        for(i = 1; i < nRows - 1; i++)
        {
            int j = 0;

            while(i + j*mod < s.size() && mod - i + j*mod < s.size())
            {
                ret.push_back(s[i+j*mod]);
                ret.push_back(s[mod -i + j*mod]);
                j++;
            }

            if(i + j*mod < s.size()) ret.push_back(s[i+j*mod]);
        }

        //last row
        i = 0;
        while(nRows - 1 + i*mod < s.size()) {ret.push_back(s[nRows - 1 + i*mod]); i++;}

        return ret;
    }
