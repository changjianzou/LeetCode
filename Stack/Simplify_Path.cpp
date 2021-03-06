#include<string>
#include<vector>

using namespace std;

//use stack
    string simplifyPath(string path) {

        vector<string> mystack;
        string temp, sPath;

        int i = 1;

        while(i < path.size())
        {
            temp.clear();

            while(path[i] != '/' && i < path.size())
            {
                temp.push_back(path[i]);
                i++;
            }

            i++; // ignore "/"

            if(temp == "..")
            {
                if(mystack.empty() == false) mystack.pop_back();
            }

            if(temp != ".." && temp != "." && temp.size())
            {
                 mystack.push_back(temp);
            }
        }

        for(int i = 0; i < mystack.size(); i++)
        {
            sPath.append("/");
            sPath.append(mystack[i]);
        }

        if(mystack.size() == 0) sPath.append("/");

        return sPath;
    }
