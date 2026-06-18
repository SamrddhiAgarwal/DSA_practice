class Solution {
public:
    bool check(vector<int>& a) {
        int n= a.size();
        int i=1;
        for(i; i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                break;
                
            }
        }
        if(i<n && a[i]>a[0]) return false;
        for( i=i+1;i<n;i++)
        {
            if(a[i]<a[i-1] || a[i]>a[0])
            {
                return false;
                
            }
        }
        return true;
        
    }
};