class Solution {
public:
    int maxDepth(string s) {
       int a=0;
       int mx=0;
       for(auto &c:s)
       {
        if(c=='(') a++;
        else if(c==')') a--;
        mx=max(mx,a);
       } 
       return mx;
    }
};