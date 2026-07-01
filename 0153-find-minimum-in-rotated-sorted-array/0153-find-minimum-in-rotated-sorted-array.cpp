class Solution {
public:
    int findMin(vector<int>& arr) {
        int mn=arr[0],low=0,high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>=arr[high])
            {
                mn=min(mn,arr[high]);
                low=mid+1;
            }
            else if(arr[mid]<=arr[low])
            {
                mn=min(mn,arr[mid]);
                high=mid-1;
            }
            else
            {
                high=mid-1;
            }
            
        }
        return mn;
    }
};