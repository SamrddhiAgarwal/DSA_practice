// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
//         // int cnt=0;
//         vector<int> ans;
//         while(!q.empty())
//         {
//             int b=q.front();
//             q.pop();
//             // cnt++;
//             ans.push_back(b);
//             for(auto &a:adj[b])
//             {
//                 indegree[a]--;

//                 if(indegree[a]==0)
//                 q.push(a);
//             }
//         }
//         // if (cnt==numCourses) return ans;
//         if (ans.size()==numCourses) return ans;
//         else return {};
        
//     }
// };
class Solution {
public:

    // bool dfs(int v, vector<int>& vis, vector<int> adj[], vector<int>& pvis)
    bool dfs(int v, vector<int>& vis, vector<int> adj[],stack<int>& st)
    {
        vis[v]=1;
        // pvis[v]=1;

        for(auto& u:adj[v])
        {
            if(!vis[u])
            {
                if(dfs(u,vis,adj,st)) return true;
            }
            
            // else if(pvis[u])
            else if(vis[u]==1)
            return true;
        }
        // pvis[v]=0;
        st.push(v);
        vis[v]=2;
        return false;
        //stack store for toposort but possible nly with cycle check
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto& p:prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }
        vector<int>vis(numCourses,0);
        // vector<int>pvis(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,st))
                return {};
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};