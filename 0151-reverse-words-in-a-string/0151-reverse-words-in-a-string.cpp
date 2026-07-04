class Solution {
public:
    string reverseWords(string s) {
        int n= s.length();int j=0,i;
        string temp="",word="";
        for( i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(i-j!=0)
                {
                    if(word!="")
                    {
                        word=s.substr(j,i-j)+" "+word;
                        
                    }
                    else
                    {
                        word+=s.substr(j,i-j);
                        
                    }
                }
                j=i+1;
            }
            else
            temp=temp+s[i];
        }
        if(i-j!=0)
        {
            if(word!="")
              {
                        word=s.substr(j,i-j)+" "+word;
                        j=i+1;
                    }
                    else
                    {
                        word+=s.substr(j,i-j);
                        j=i+1;
                    }      
        }
        return word;
    }
};