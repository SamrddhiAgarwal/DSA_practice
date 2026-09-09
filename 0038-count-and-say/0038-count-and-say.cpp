class Solution {
public:
    string countAndSay(int n) {
        string s="1",temp="";
        for(int k=1;k<n;k++)
        {
            char a=s[0];
            int cnt=1;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==a)
                {
                    cnt++;
                }
                else
                {
                    temp+=to_string(cnt);
                    temp+=a;
                    cnt=1;
                    a=s[i];
                }
                    
                
            }
            temp+=to_string(cnt);
            temp+=a;
                
            s=temp;
            // return temp;
            temp.clear();
        }
        return s;

    }
};