class Solution {
public:
    string reverseWords(string s) {
        int n= s.length();
        string temp="",word="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(temp!="")
                {
                    if(word!="")
                    {
                        word=temp+" "+word;
                        temp="";
                    }
                    else
                    {
                        word+=temp;
                        temp="";
                    }
                }
            }
            else
            temp=temp+s[i];
        }
        if(temp!="")
        {
            if(word!="")
                    {
                        word=temp+" "+word;
                        temp="";
                    }
                    else
                    {
                        word+=temp;
                        temp="";
                    }
        }
        return word;
    }
};