class Solution {
public:
    const long long mod=1e9+7;
    typedef pair<long long,int> p;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:roads)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>num(n,0);
        dist[0]=0;
        num[0]=1;
        priority_queue<p,vector<p>,greater<p>>pq; 
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [d,v]=pq.top();
            pq.pop();
            if(dist[v]<d) continue;
            for(auto &[u,w]:adj[v])
            {
                if(dist[u]>d+w)
                {
                    dist[u]=d+w;
                    num[u]=num[v];
                    pq.push({dist[u],u});
                }
                else if (dist[u]==d+w)
                {
                    num[u]=(num[u]+num[v])%mod;
                }
            }
        }
        return num[n-1];
    }
};