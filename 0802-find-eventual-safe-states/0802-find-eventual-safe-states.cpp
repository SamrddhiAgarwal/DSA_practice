class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // anode can not be safe node if there is acycle ie for that node one of it edge is revisting it back
        int V=graph.size();
        vector<vector<int>> rgraph(V);
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto v:graph[i])
            {
                rgraph[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) // this will insert all terminal node
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int b=q.front();
            q.pop();
            ans.push_back(b);
            for(auto &a:rgraph[b])
            {
                indegree[a]--;

                if(indegree[a]==0)
                q.push(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};