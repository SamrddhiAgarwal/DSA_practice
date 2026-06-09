// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> adj[numCourses];
//         vector<int> indegree(numCourses,0);
//         for(auto& p:prerequisites)
//         {
//             adj[p[1]].push_back(p[0]);
//             indegree[p[0]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(indegree[i]==0)
//             q.push(i);
//         }
//         int cnt=0;
//         while(!q.empty())
//         {
//             int b=q.front();
//             q.pop();
//             cnt++;
//             for(auto &a:adj[b])
//             {
//                 indegree[a]--;

//                 if(indegree[a]==0)
//                 q.push(a);
//             }
//         }
//         if(cnt==numCourses) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool dfs(int v, vector<int>& vis, vector<int> adj[], vector<int>& pvis)
    {
        vis[v]=1;
        pvis[v]=1;

        for(auto& u:adj[v])
        {
            if(!vis[u])
            {
                if(dfs(u,vis,adj,pvis)) return true;
            }
            
            else if(pvis[u])
            return true;
        }
        pvis[v]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto& p:prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>pvis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,pvis))
                return false;
            }
        }
        return true;
    }
};