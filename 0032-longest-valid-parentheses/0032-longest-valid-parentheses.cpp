class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0;
        int n=s.size();
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            open++;
            else
            close++;
            if(close>open)
            {
                close=0;
                open=0;
            }
            if(open==close)
            len=max(len,close*2);
        }
        open=0;
        close=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            close++;
            else
            open++;
            if(open>close)
            {
                open=0;
                close=0;
            }
            if(open==close)
            len=max(len,close*2);
        }
        return len;
    }
};

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         // int open=0,close=0;
//         int a=0,b=0;
//         int len=0;
//         for(auto &c:s)
//         {
//             if(c==')')
//             {
//                 a--;
//                 b++;
//             }
//             else
//             {
//                 a++;
//             }
//             if(a<0) 
//             {
//                 a=0;b=0;
//             }
//             if(a==0)
//             len=max(len,b*2);
//         }
//         a=0;
//         b=0;
//         int len2=0;
//         reverse(s.begin(),s.end());
//         for(auto &c:s)
//         {
//             if(c=='(')
//             {
//                 a--;
//                 b++;
//             }
//             else
//             {
//                 a++;
//             }
            
//             if(a<0) 
//             {
//                 a=0;b=0;
//             }
//             if(a==0)
//             len2=max(len2,b*2);
//         }
        
//         return max(len,len2);
//         // return min(len,len2);
//     }
// };