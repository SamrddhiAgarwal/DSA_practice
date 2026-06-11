class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e:times)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<p,vector<p>,greater<p>>pq; 
        pq.push({0,k});
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
                    pq.push({dist[u],u});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,dist[i]);
            if(dist[i]==INT_MAX) return -1;
        }
        return mx;
    }
};