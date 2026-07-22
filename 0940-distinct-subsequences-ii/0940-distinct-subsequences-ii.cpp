class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> last(26,0);
        int mod=1000000007;
        int res=1;
        for(int i=0;i<n;i++)
        {
            int cur=((2*res)%mod-(last[s[i]-'a']))%mod;
            last[s[i]-'a']=res ;
            res=cur;
        }
        return (res-1+mod)%mod;
    }
};