class Solution {
public:
int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> p(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            p[i][j] = mat[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];

    int max_len = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int len = max_len + 1;
            if(i<len) break;
            if (i >= len && j >= len) {
                int sum = p[i][j] - p[i-len][j] - p[i][j-len] + p[i-len][j-len];
                if (sum <= threshold) max_len++;
            }
        }
    }
    return max_len;
}


};