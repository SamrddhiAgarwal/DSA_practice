class Solution {
public:
typedef pair<int,pair<int,int>> p;
    int minCostConnectPoints(vector<vector<int>>& points) {

    //     long long ans=0;int n=points.size();
    //     for(int i=0;i<n-1;i++)
    //     {
    //         int mn=INT_MAX;
    //         for(int j=0;j<n;j++)
    //         {
    //             if(i==j) continue;
                
    //             int val= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
    //             if(mn<val)
    //             {
    //                 mn=val;
                    
    //             }
    //             ans+=mn;
    //         }
    //     }
    //     return ans;
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        vector<int>dist(n,INT_MAX);
        pq.push({0,0});
        dist[0]=0;
        int ans=0;
        while(!pq.empty())
        {
            auto [val,i]=pq.top();
            pq.pop();
            if(!vis[i])
            {
                vis[i]=1;
                ans+=val;   
                int mn=INT_MAX;int x2;
                for(int j=0;j<n;j++)
                {
                    if(vis[j]==1) continue;
                    
                    int val2= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    if(dist[j]>val2)
                    {
                        pq.push({val2,j});
                        dist[j]=val2;
                    }
                    
                }                
            }
        }
        return ans;
    }
};