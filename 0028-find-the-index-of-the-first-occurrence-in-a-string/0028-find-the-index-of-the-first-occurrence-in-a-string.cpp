class Solution {
public:
    int strStr(string haystack, string needle) {
        int r=0,L=haystack.size(),l=needle.size();
        while(r<L)
        {
            if(haystack[r]==needle[0] && L-r >= l)
            {
                int i=r,j=0;
                while(i<L && j<l && (haystack[i]==needle[j]))
                {
                    i++;
                    j++;
                }
                if(j==l) return r;
            }
            r++;
        }
        return -1;
        
    }
};