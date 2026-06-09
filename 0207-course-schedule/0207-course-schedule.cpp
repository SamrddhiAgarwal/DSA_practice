class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto& p:prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int b=q.front();
            q.pop();
            cnt++;
            for(auto &a:adj[b])
            {
                indegree[a]--;

                if(indegree[a]==0)
                q.push(a);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};