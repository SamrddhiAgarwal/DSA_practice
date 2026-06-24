class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            auto [word,steps] =q.front();
            q.pop();
            if(word==endWord) return steps;
            int n=word.length();
            for(int i=0;i<n;i++)
            {
                char org=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};