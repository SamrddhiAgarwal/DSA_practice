class Solution {
public:
    typedef pair<pair<int,int>,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& e:flights)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<p,vector<p>,greater<p>>pq; 
        pq.push({{0,src},0});
        while(!pq.empty())
        {
            auto [stop,v]=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            if(stop>k) break;
            // if(v==dst) return d;  
            // if(dist[v]<d) continue; shouldn't be as it can give wrong result since we have dist of already smaller but later it's dist change 
            //nput
            // n =
            // 4
            // flights =
            // [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
            // src =
            // 0
            // dst =
            // 3
            // k =
            // 1
            // Output
            // 6
            // Expected
            // 6
            // we need to sort by stops instead of dist
            //Input
            // n =
            // 5
            // flights =
            // [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
            // src =
            // 0
            // dst =
            // 2
            // k =
            // 2
            // Output
            // 7
            // Expected
            // 7
 
            for(auto &[u,w]:adj[v])
            {
                if(dist[u]>d+w && stop<=k)
                {
                    dist[u]=d+w;
                    pq.push({{stop+1,u},dist[u]});
                }
            }
        }
        return  dist[dst]!=INT_MAX? dist[dst]:-1;
              
    }
};