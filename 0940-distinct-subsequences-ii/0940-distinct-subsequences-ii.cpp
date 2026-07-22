class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> last(26,0);
        int mod=1000000007;
        int res=1;
        for(int i=0;i<n;i++)
        {
            int cur=((2LL*res)-(last[s[i]-'a'])+mod)%mod;
            last[s[i]-'a']=res ;
            res=cur;
        }
        if(res-1==-1) return mod-1;
        return res-1;
    }
};