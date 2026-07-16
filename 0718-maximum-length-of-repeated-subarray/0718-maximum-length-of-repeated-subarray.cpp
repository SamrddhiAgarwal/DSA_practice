class Solution {
public:
    int findLength(vector<int>& str1, vector<int>& str2) {
           int n = str1.size();
        int m = str2.size();
    
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);  
        
        int ans = 0; 
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // Characters match, increment substring length
                if(str1[i-1] == str2[j-1]){
                    int val = 1 + prev[j-1]; 
                    cur[j] = val; 
                    
                    /* Update the maximum substring
                    length found so far*/
                    ans = max(ans, val); 
                }
                else{
                    /* Characters don't match,
                    substring length becomes 0*/
                    cur[j] = 0; 
                }
                
            }
            /* Update the previous row with 
            the values of the current row*/
            prev = cur; 
        }
        // Return the length of Longest Common Substring
        return ans;
    }
};