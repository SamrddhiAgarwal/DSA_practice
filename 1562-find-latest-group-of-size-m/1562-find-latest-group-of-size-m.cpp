class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        // vector<int>len(n+2,0),cnt(n+1,0);
        vector<int>len(n+2,0);
        int ans=-1,cnt_m=0;
        for(int i=0;i<n;i++)
        {
            int x=arr[i];

            int right=len[x+1];
            int left=len[x-1];

            int newlen=right+1+left;

            // cnt[right]--;
            if(right==m) cnt_m--;
            // cnt[left]--;
            if(left==m) cnt_m--;
            // cnt[newlen]++;
            if(newlen==m) cnt_m++;

            len[x]=newlen;
            len[x+right]=newlen;
            len[x-left]=newlen;

            // if(cnt[m]>0)
            if(cnt_m>0)
            ans=i+1;

        }
        return ans;
    }
};