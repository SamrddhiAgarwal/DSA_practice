class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>needs;
        for(int i=0;i<recipes.size();i++)
        {
            for(auto j:ingredients[i])
            {
                adj[j].push_back(recipes[i]);
                needs[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto s:supplies)
        q.push(s);
        vector<string> ans;
        while(!q.empty())
        {
            string supply=q.front();
            q.pop();
            for(auto receipe:adj[supply])
            {
                needs[receipe]--;
                if(needs[receipe]==0)
                {
                    ans.push_back(receipe);
                    q.push(receipe);
                }
            }
        }
        return ans;
    }
};