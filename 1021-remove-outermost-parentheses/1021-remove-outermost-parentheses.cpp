class Solution {
public:
    string removeOuterParentheses(string s) {
        int a=0;
        string ns="";
        for(auto& c:s)
        {
            if(c=='(')
            {
                a++;
                if(a==1)
                continue;
            }
            else
            {
                a--;
                if(a==0)
                continue;
            }
            ns=ns+c;
        }
        return ns;
    }
};