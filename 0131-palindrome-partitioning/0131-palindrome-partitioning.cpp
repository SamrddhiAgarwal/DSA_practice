class Solution {
public:
    bool pallindrome(int l,int r,string s)
    {
        while(l<=r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            return false;
        }
        return true;
    }
    void helper(int ind,string& s, vector<string>& curr, vector<vector<string>>& res)
    {
        if(ind==s.size())
        {
            res.push_back(curr);
        }
        for(int i= ind;i<s.size();i++)
        {
            if(pallindrome(ind,i,s)) //cam use palindrome dp s[i]=s[j] , j-i<2 || s[i+1][j-1] are also pal so new one will be pal
            {
                curr.push_back(s.substr(ind,i-ind+1));
                helper(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr; vector<vector<string>> res;
        helper(0,s,curr,res);
        return res;
    }
};