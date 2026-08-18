class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>st;

        for(auto& c:s)
        {
            if(!st.empty() && c==st.top().first)
            st.top().second++;

            else
            st.push({c,1});

            if(st.top().second==k)
            st.pop();
        }
        string ns="";
        while(!st.empty())
        {
            auto it=st.top();
            
            while(it.second--)
            ns+=it.first;

            st.pop();
        }
        reverse(ns.begin(),ns.end());
        return ns;
    }
};





// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
        
//         string temp="",ns="";
//         int cnt=1;
//         while(true)
//         {
//             temp+=s[0];
//             cnt=1;
//             for(int i=1;i<s.size();i++)
//             {
                
//                 if(s[i]==s[i-1])
//                 {
//                     cnt++;
//                 }
//                 else
//                 {
//                     cnt=1;
//                     ns+=temp;
//                     temp="";
//                 }
//                 temp+=s[i];
//                 if(cnt==k)
//                 {
//                     temp="";
//                     cnt=0;
//                 }
//             }
//             ns+=temp;
//             // return ns;
//             if(ns==s) return ns;
//             s=ns;
//             // return s;
//             ns="";
//             // return ns;
//         }
//         return s;
//     }
// };