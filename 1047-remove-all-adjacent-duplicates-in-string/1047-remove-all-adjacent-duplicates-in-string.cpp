class Solution {
public:
    string removeDuplicates(string s) {
        // string ns="";
        int i=0;
        int n=s.length();
        for(int j=0;j<n;j++)
        {
            s[i]=s[j];
            if(i>0 && s[i]==s[i-1])
            i-=2;
            i++;
        }
        return s.substr(0,i);
    }
};

// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string ans;
//         vector<char> st;
//         for(auto c : s){
//           if(!st.empty() && st.back()==c) st.pop_back();
//           else st.push_back(c);
//         }
//         for(auto c : st) ans.push_back(c);
//         return ans;
//     }
// };
