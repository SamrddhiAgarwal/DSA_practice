class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.size();
        vector<int>count(n,0);
        int j=0;
        for(int i=0;i<n;i++)
        {
            s[j]=s[i];
            count[j]= (j>0 && s[j]==s[j-1])? count[j-1]+1:1;
            if(count[j]==k)
            j-=k;
            // else 
            j++;
        }
        return s.substr(0,j);
    }
};



// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
        
//         vector<pair<char,int>>st;

//         for(auto& c:s)
//         {
//             if(!st.empty() && c==st.back().first)
//             st.back().second++;

//             else
//             st.push_back({c,1});

//             if(st.back().second==k)
//             st.pop_back();
//         }
//         string ns="";
//         for(auto& [c,cnt]:st)
//         {
//             ns.append(cnt,c);
//         }
//         // reverse(ns.begin(),ns.end());
//         return ns;
//     }
// };





// // class Solution {
// // public:
// //     string removeDuplicates(string s, int k) {
        
// //         string temp="",ns="";
// //         int cnt=1;
// //         while(true)
// //         {
// //             temp+=s[0];
// //             cnt=1;
// //             for(int i=1;i<s.size();i++)
// //             {
                
// //                 if(s[i]==s[i-1])
// //                 {
// //                     cnt++;
// //                 }
// //                 else
// //                 {
// //                     cnt=1;
// //                     ns+=temp;
// //                     temp="";
// //                 }
// //                 temp+=s[i];
// //                 if(cnt==k)
// //                 {
// //                     temp="";
// //                     cnt=0;
// //                 }
// //             }
// //             ns+=temp;
// //             // return ns;
// //             if(ns==s) return ns;
// //             s=ns;
// //             // return s;
// //             ns="";
// //             // return ns;
// //         }
// //         return s;
// //     }
// // };