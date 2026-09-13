class Solution {
public:
    int findIntegers(int n) {
        // f[i] will store the number of valid binary strings of length i
        // int[] f = new int[32];
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        int ans = 0;
        int prevBit = 0;
        
        // Process from the 30th bit down to the 0th bit
        for (int i = 30; i >= 0; i--) {
            // Check if the i-th bit is set to 1
            if ((n & (1 << i)) != 0) {
                // If we choose '0' for this bit, any valid combination of length i fits
                ans += f[i];
                
                // If the previous bit was also 1, we found consecutive ones in 'n'
                if (prevBit == 1) {
                    return ans;
                }
                prevBit = 1;
            } else {
                prevBit = 0;
            }
        }
        
        // Add 1 to include the number 'n' itself if it is valid
        return ans + 1;

    }
};