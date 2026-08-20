class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1)
        {
            string ns=s;
            int n=s.size();
            for(int i=0;i<n;i++)
            {
                string cs=s.substr(i)+s.substr(0,i);
                // if(cs<ns)
                // ns=cs;
                ns=min(ns,cs);
            }
            return ns;
        }
        else
        {
            sort(s.begin(),s.end());
            return s;
        }
        // priority_queue<char>pq;
        // for(int i=0;i<k;i++)
        // {
        //     pq.push(s[i]);
        // }
        // string ns="";
        // int n=s.size();
        // for(int i=k;i<n;i++)
        // {
        //     if(s[i]<pq.top())
        //     {
        //         ns+=pq.top();
        //         pq.pop();
        //         pq.push(s[i]);
        //     }
        //     else
        //     ns+=s[i];
        // }
        // while(!pq.empty())
        // {
        //     ns+=pq.top();
        //     pq.pop();
        // }
        // reverse(ns.begin(),ns.end());
        // return ns;
    }
};