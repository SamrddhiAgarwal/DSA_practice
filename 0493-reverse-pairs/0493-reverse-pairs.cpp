class Solution {
public:
    void merge(vector<int>& arr,int l,int mid,int r){
            int n;
            n=r-l+1;
            int temp[n];
            int left=l;
            int right=mid+1;
            int k=0;
            while(left<=mid && right<=r){
                if(arr[left]<=arr[right]){
                    temp[k++]=arr[left++];
                }
                else{
                    temp[k++]=arr[right++];
                }
            }
            while(left<=mid){
                temp[k++]=arr[left++];
            }
            while(right<=r){
                temp[k++]=arr[right++];
            }
            for(int i=0;i<n;i++){
                arr[i+l]=temp[i];
            }
        }
    int countpairs(vector<int>&arr,int low,int mid,int high){
            int right=mid+1;
            int cnt=0;
            for(int i=low;i<=mid;i++){
                while(right<=high && arr[i]>2LL*arr[right]){
                    right++;
                }
                cnt+=(right-(mid+1));
            }
            return cnt;
        }
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt=0;
        if(l>=r){
            return cnt;
        }
        int mid=(l+r)/2;
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
        cnt+=countpairs(arr,l,mid,r);
        merge(arr,l,mid,r);
        return cnt;
    }
    int reversePairs(vector<int>& arr) {
        int n=arr.size();
        return mergeSort(arr,0,n-1);
    }
};