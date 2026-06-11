class Solution {
public:
    typedef pair<double,pair<int,int>> p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double>dist(n,0.0);
        
        priority_queue<p>pq; 
        pq.push({1.0,{start_node,-1}});
        dist[start_node]=1.0;
        bool found =false;
        while(!pq.empty())
        {
            double d=pq.top().first;
            auto [v,parent]=pq.top().second;
            pq.pop();
            if(v==end_node) found=true;
            if(dist[v]>d) continue;
            for(auto& [u,w]:adj[v])
            {
                if(u==parent) continue;
                if(dist[u]<w*d)
                {
                    dist[u]=w*d;
                    pq.push({dist[u],{u,v}});
                }
            }
        }
        return (found)?dist[end_node]:0.00;
    }
};