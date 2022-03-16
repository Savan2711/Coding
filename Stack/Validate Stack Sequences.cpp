/*
https://leetcode.com/problems/validate-stack-sequences/
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int itr_push = 0, itr_pop = 0;
        stack<int> st;
        
        while(itr_push < pushed.size() || itr_pop < popped.size())
        {
            if(st.empty())
            {st.push(pushed[itr_push++]);}
            else if(!st.empty() && st.top() == popped[itr_pop])
            {
                st.pop();
                itr_pop++;
            }
            else if(itr_push >= pushed.size()) 
            {
                return false;
            }
            else
            {
                st.push(pushed[itr_push++]);
            }
        }
        return true;
        
    }
};
