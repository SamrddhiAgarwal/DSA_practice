class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last_pos(26,0);
        int l=s.size();
        for(int i=0;i<l;i++)
        {
            last_pos[s[i]-'a']=i;
        }
        string ns="";
        ns+=s[0];
        vector<bool>used(26,false);
        used[s[0]-'a']=true;
        for(int i=1;i<l;i++)
        {
            if(used[s[i]-'a']) continue;
            while(!ns.empty() && s[i]<ns.back())
            {
                if(last_pos[ns.back()-'a']>i)
                {
                    used[ns.back()-'a']=false;
                    ns.pop_back();
                    
                }
                
                else
                break;
            }
            ns+=s[i];
            used[s[i]-'a']=true;
        }
        return ns;
    }
};