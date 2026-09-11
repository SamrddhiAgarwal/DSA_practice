class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        vector<int>hash1(26,0), hash2(26,0);
        for(int i=0;i<n1;i++)
        {
            hash2[s2[i]-'a']++;
            hash1[s1[i]-'a']++;
        }
        if(hash1 ==hash2) return true;

        for(int i=n1;i<n2;i++)
        {
            hash2[s2[i]-'a']++;
            hash2[s2[i-n1]-'a']--;
            if(hash1==hash2) return true;
        }
        return false;
        
    }
};