// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         string s;
//         for(int i=1;i<=n;i++)
//         {
//             s += (i + '0');
//         }
//         int j=0;
//         do
//         {
//            j++;
//         }
//         while(j!=k &&next_permutation(s.begin(),s.end()));
//         return s;
//     }

// };
class Solution {
public:
    string getPermutation(int n, int k) {

        int fact = 1;
        vector<int> numbers;
        
        // Calculate (n-1)! and populate the numbers pool
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // numbers array: [1, 2, ..., n]
        
        string ans = "";
        k = k - 1; // Convert to 0-based indexing
        
        while (true) {
            // Find the index of the current element we need
            int index = k / fact;
            ans += to_string(numbers[index]);
            
            // Remove the used number from the pool
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) {
                break;
            }
            
            // Update k and calculate the next factorial block size
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;        
    }
};