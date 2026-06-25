class Solution {
public:
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> ans;
    //     if(numRows>0)
    //     ans.push_back({1});
    //     if(numRows>1)
    //     ans.push_back({1,1});
    //     int k=2;
    //     vector<int> temp;
    //     while(numRows>k)
    //     {
    //         // vector<int> temp;
    //         temp.push_back(1);
    //         int n=ans.back().size();
    //         for(int i=0;i<n-1;i++)
    //         {
    //             temp.push_back(ans.back()[i]+ans.back()[i+1]);
    //         }
    //         temp.push_back(1);
    //         ans.push_back(temp);
    //         temp.clear();
    //         k++;
    //     }
    //     return ans;
    //     // n^2 ,n
    // }
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> ans;
    //     vector<int>temp;
    //     for (int row = 1; row <= numRows; row++) 
    //     {
      
    //         int c = 1; 
    //         for (int i = 1; i <= row; i++) {

    //             temp.push_back(c);
    //             c = c * (row - i) / i;
    //         }
    //         ans.push_back(temp);
    //         temp.clear();
    //     }
    //     return ans;
    // }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1, 1);
            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }   
        return ans;
    }
};