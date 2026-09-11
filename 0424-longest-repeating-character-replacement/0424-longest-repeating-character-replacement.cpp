class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l=0,mxfreq=0,ans=0;
        int n=s.size();
        for(int r=0;r<n;r++)
        {
            freq[s[r]-'A']++;
            mxfreq=max(mxfreq,freq[s[r]-'A']);

            // while(r-l+1-mxfreq>k)
            if(r-l+1-mxfreq>k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            if(r-l+1-mxfreq<=k)
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int ans=0,n=s.size();
//         for(char c='A';c<='Z';c++)
//         {
//             int ch=0,l=0;
//             for(int i=0;i<n;i++)
//             {
//                 if(s[i]!=c)
//                 ch++;
//                 while(ch>k)
//                 {
//                     if(s[l]!=c)
//                     ch--;
//                     l++;
//                 }
//                 ans=max(ans,i-l+1);

//             }
//         }
//         return ans;
//     }
// };