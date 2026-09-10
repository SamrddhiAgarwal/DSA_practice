#include <vector>
#include <string>

class Solution {
public:
    void backtrack(int row, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result,
                   std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        // Base Case: If we successfully placed a queen in every row, record this board state
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            // Check if placing a queen here violates any column or diagonal paths
            if (cols[col] || diag1[row + col] || diag2[row - col + n]) {
                continue;
            }
            
            // 1. Make choice
            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n] = true;
            
            // 2. Recurse to the next row
            backtrack(row + 1, n, board, result, cols, diag1, diag2);
            
            // 3. Undo choice (Backtrack clean-up)
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n] = false;
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        // Initialize the empty board with dots '.' as expected by LeetCode
        std::vector<std::string> board(n, std::string(n, '.'));
        
        // Tracking states for safety checks
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n, false); //since one diag in left direction i+1,j-1 gives value i+j and total sum can be n-1 +n-1 = 2n-2 
        std::vector<bool> diag2(2 * n, false); // since i+1 j+1 i-j gives same value but to avoud netive we go +n 
        
        backtrack(0, n, board, result, cols, diag1, diag2);
        
        return result;
    }
};

// class Solution {
// public:
//     void helper(int i, vector<string>& curr,vector<vector<string>>& result,int q,int n)
//     {
//         if(i==n)
//         {
//             if(q==n)
//             result.push_back(curr);
            
//             return;
//         }
//         for(int j=0;j<n;j++)
//         {
//             if(curr[i][j]!='.')
//             {
//                 curr[i][j]='Q';
//                 for(int k=0;k<n;k++)
//                 {
//                     if(k==j) continue;
//                     curr[i][k]='.';
//                 }
//                 for(int k=i+1;k<n;k++)
//                 {
//                     curr[k][j]='.';
//                 }
//                 for(int k=1;i+k<n && j-k>=0 ;k++ )
//                 {
//                     curr[i+k][j-k]='.';
//                 }
//                 for(int k=1;i+k<n && j+k<n;k++)
//                 {
//                     curr[i+k][j+k]='.';
//                 }

//                 helper(i+1,curr,result,q+1,n);

//                 curr[i][j]='#';
//                 for(int k=0;k<n;k++)
//                 {
//                     if(k==j) continue;
//                     curr[i][k]='#';
//                 }
//                 for(int k=i+1;k<n;k++)
//                 {
//                     curr[k][j]='#';
//                 }
//                 for(int k=1;i+k<n && j-k>=0 ;k++ )
//                 {
//                     curr[i+k][j-k]='#';
//                 }
//                 for(int k=1;i+k<n && j+k<n;k++)
//                 {
//                     curr[i+k][j+k]='#';
//                 }
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
        
//         vector<vector<string>> result;
//         vector<string>curr(n,string(n,'#'));
//         helper(0,curr,result,0,n);
//         return result;
//     }
// };