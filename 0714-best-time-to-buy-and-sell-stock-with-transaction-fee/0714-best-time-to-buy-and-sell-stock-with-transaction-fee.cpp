class Solution {
public:
    int maxProfit(vector<int>& Arr, int fee) {
        int n=Arr.size();
        
        vector<long> ahead(2, 0);
        vector<long> cur(2, 0);

        // Base condition: When there are no stocks left, the profit is 0.
        ahead[0] = ahead[1] = 0;

        long profit;

        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) { // We can buy the stock
                    profit = max(0 + ahead[0], -Arr[ind] + ahead[1]-fee);
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
                }
                cur[buy] = profit;
            }

            ahead = cur; // Update the "ahead" array with the current values
        }

        // The maximum profit is stored in cur[0] after all calculations
        return ahead[0];
    

    }
};