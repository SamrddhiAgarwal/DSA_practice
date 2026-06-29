class Solution {
public:
    static bool comparator(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        int cnt=0;
        vector<int> current;
        
        for(auto v:intervals)
        {
            if(current.empty()|| current[1]<=v[0] )
            {
                
                current =v;
            }
            else 
            cnt++;
        }
        return cnt;
    }
};