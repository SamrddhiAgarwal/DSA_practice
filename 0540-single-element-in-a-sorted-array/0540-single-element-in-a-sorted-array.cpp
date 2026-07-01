class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int low=0,high=arr.size()-1;int n=arr.size();
        while(low<high)
        {
            int mid=(low+high)/2;
            if(mid%2==0  &&(arr[mid]==arr[mid+1]))
            {
                low=mid+1;
            }
            else if(mid%2!=0 &&( arr[mid]==arr[mid-1]))
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
            
        }
        return arr[low];
    }
};