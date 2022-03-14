/*
https://leetcode.com/problems/simplify-path/
*/

class Solution {
public:
    string simplifyPath(string path) {
     
        deque<string> dirs;
        
        int n = path.length();
        
        string cur;
        for(int i = 1; i < n; i++)
        {
            if(path[i] == '/')
            {
                continue;
            }
            else if(i < n && path[i] == '.')
            {
                if(i < n - 1 && path[i + 1] == '.')
                {
                    i++;
                    string temp = "..";
                    while(i < n - 1 && path[i + 1] != '/')
                    {
                        temp.push_back(path[i + 1]);
                        i++;
                    }
                    if(temp != "..")
                    {dirs.push_front(temp);}
                    else if(!dirs.empty())
                    {dirs.pop_front();}
                }
                else
                {
                    string tmp = ".";
                    while(i < n - 1 && path[i + 1] != '/')
                    {
                        tmp.push_back(path[i + 1]);
                        i++;
                    }
                    if(tmp != ".")
                    {dirs.push_front(tmp);}
                }
            }
            else
            {
                cur = "";
                while(i < n && path[i] != '/')
                {
                    cur.push_back(path[i]);
                    i++;
                }
                if(cur != "")
                {
                    dirs.push_front(cur);
                }
            }
        }
        
        string ans = "";
        while(!dirs.empty())
        {
            ans += "/";
            string tmp = dirs.back();
            ans += tmp;
            dirs.pop_back();
        }
        
        if(ans == "")
        {ans = "/";}
        return ans;
    }
};
