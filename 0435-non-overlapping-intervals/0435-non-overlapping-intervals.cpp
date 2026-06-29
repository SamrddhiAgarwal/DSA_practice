class Solution {
public:
    static bool comparator(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        int cnt=0;
        int current;
        current =intervals[0][1];
        
        for(auto& v:intervals)
        {
            if( current<=v[0] )
            {
                
                current =v[1];
            }
            else 
            cnt++;
        }
        return cnt-1;
    }
};