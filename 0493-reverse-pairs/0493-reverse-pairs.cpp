class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    // Temporary array to store merged elements
    vector<int> temp;

    // Starting index of left half
    int left = low;
    // Starting index of right half
    int right = mid + 1;

    // Merge elements in sorted order and count inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If left half still has elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return inversion count
}
int CountPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0,right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>(2LL*arr[right])) right++;// 2LL is used 
        cnt+=right-(mid+1);
    }
    return cnt;
}

// Merge sort function that counts inversions
int mergeSort(vector<int> &arr, int low, int high) {
    // Variable to store inversion count
    int cnt = 0;

    // Base case
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left half
    cnt += mergeSort(arr, low, mid);
    // Count inversions in right half
    cnt += mergeSort(arr, mid + 1, high);
    // Count inversions during merge
    cnt += CountPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}

// Function to get number of inversions


    int reversePairs(vector<int>& nums) {
        
       return mergeSort(nums,0,nums.size()-1) ;
    }
};