class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int ans=0;int n=points.size();
        vector<int> dist(n,INT_MAX);
        vector<int> vis(n,0);
        dist[0]=0;
        vis[0]=1;
        int curr=0;  // imp since we need to to find new value as per new min not i 
        for(int i=0;i<n-1;i++)
        {
            int mn=INT_MAX;int x2=0;
            
            for(int j=0;j<n;j++)
            {
                if(vis[j]==1) continue;
                int val= abs(points[curr][0]-points[j][0])+abs(points[curr][1]-points[j][1]);
                
                if(dist[j]>val)
                {
                    dist[j]=val;
                }
                if(mn>dist[j])
                {
                    mn=dist[j];
                    x2=j;
                }
            }
            
            ans+=mn;
            vis[x2]=1;
            curr=x2;
            
            
        }
        return ans;
        // int n=points.size();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // vector<int> vis(n,0);
        // vector<int>dist(n,INT_MAX);
        // pq.push({0,0});
        // dist[0]=0;
        // int ans=0;
        // while(!pq.empty())
        // {
        //     auto [val,i]=pq.top();
        //     pq.pop();
        //     if(!vis[i])
        //     {
        //         vis[i]=1;
        //         ans+=val;   
        //         int mn=INT_MAX;int x2;
        //         for(int j=0;j<n;j++)
        //         {
        //             if(vis[j]==1) continue;
                    
        //             int val2= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
        //             if(dist[j]>val2)
        //             {
        //                 pq.push({val2,j});
        //                 dist[j]=val2;
        //             }
                    
        //         }                
        //     }
        // }
        // return ans;
    }
};