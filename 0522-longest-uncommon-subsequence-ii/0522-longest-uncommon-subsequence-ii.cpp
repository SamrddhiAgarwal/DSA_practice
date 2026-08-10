class Solution {
public:
    static bool comparator(string a, string b)
    {
        return a.length()>b.length();
    }
    bool isSubsequence(string a, string b)
    {
        int i=0,j=0;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.length();
    
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),comparator);
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            int j;
            for( j=0;j<n;j++)
            {
                if(i==j ) continue;
                if(isSubsequence(strs[i],strs[j])) break;
            }
            if(j==n) return strs[i].length();
        }
        return -1;
    }
};