class Solution {
public:
    int reinitializePermutation(int n) {
        int operations=1;
        int num_at_i_1=2;
        if(n==2) return 1;//important base case
        while(num_at_i_1!=1)
        {
            num_at_i_1=(2*num_at_i_1)%(n-1);
            operations++;
        }
        return operations;
    }
};
// class Solution {
// public:
//     int reinitializePermutation(int n) {
//         int i=n/2,operations=1;
//         while(i!=1)
//         {
//             if(i%2==0)
//             i=i/2;
//             else
//             i=n/2+(i-1)/2;
//             operations++;
//         }
//         return operations;
//     }
// };