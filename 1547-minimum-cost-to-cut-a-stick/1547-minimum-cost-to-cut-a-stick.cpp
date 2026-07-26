class Solution {
public:
    int findMinimumCost(int i, int j, vector<int> &cuts,vector<vector<int>> &dp) {
        // Base case: no cuts to consider
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mini = INT_MAX;

        // Try cutting at every position between i and j
        for (int ind = i; ind <= j; ind++) {
            // Cost of making the current cut plus
            // cost of cutting left and right sub-segments recursively
            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts,dp) +
                      findMinimumCost(ind + 1, j, cuts,dp);

            // Update minimum cost
            mini = min(mini, ans);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size() -1, vector<int>(cuts.size() - 1, -1));
        return findMinimumCost(1, cuts.size()-2, cuts,dp);

    }
};