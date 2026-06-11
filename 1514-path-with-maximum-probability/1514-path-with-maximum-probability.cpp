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
        
        // priority_queue<p>pq; 
        priority_queue<pair<double,int>> pq;
        // pq.push({1.0,{start_node,-1}});
        pq.push({1.0,start_node});
        dist[start_node]=1.0;
        // bool found =false;
        while(!pq.empty())
        {
            double d=pq.top().first;
            // auto [v,parent]=pq.top().second;
            //no parent needed since pq will already give bigger one and we will go for first value of end so that it don;t form cycle and initial is higher for any if we go by cycle since multipyling again and again will only reduce probability since if we could reach at a dist in 0.5 probability next time it will be 0.5*0.5 ie 0.25 reducced 
            int v=pq.top().second;
            pq.pop();
            // if(v==end_node) found=true;
            if(v==end_node) return d;
            if(dist[v]>d) continue;
            for(auto& [u,w]:adj[v])
            {
                // if(u==parent) continue;
                if(dist[u]<w*d)
                {
                    dist[u]=w*d;
                    // pq.push({dist[u],{u,v}});
                    pq.push({dist[u],u});
                }
            }
        }
        return dist[end_node];
        // return (found)?dist[end_node]:0.00; not needed was doing for 1 but it will not come since 1 is probability is possible only 1 is there 
    }
};