class Solution {
public:
    pair<int,int> numTorc(int num,int n)
    {
        num--;
        int dd=num/n;
        int ds=num%n;
        int r=n-1-dd;
        int c;
        if(dd%2==0)
        c=ds;
        else
        c=n-1-ds;
        return {r,c};
        /*
         num--;

        int r = n - 1 - num / n;
        int c = num % n;

        if((num / n) & 1)
            c = n - 1 - c;

        return {r,c};
        */
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n=board.size();
        if(n==1) return 0;
        queue<int> pq;
        pq.push(1);
        int sp=0;    
        vector<int> vis((n*n)+1,0) ;//imp for this que
        while(!pq.empty())
        {
            
            int sz=pq.size();
            while(sz--)
            {
                int num=pq.front();
                pq.pop();
                if(num==n*n) return sp; 
                for(int i=1;i<=6 && num+i <= n*n ;i++)  //o(6*1)
                {
                    auto [r,c]=numTorc(num+i,n);
                    if(board[r][c]==-1 )
                    {
                        if(!vis[num+i])
                        {    
                            vis[num+i]=1;
                            pq.push(num+i);
                        }
                    }
                    else
                    {
                        if(!vis[board[r][c]])
                        {
                            vis[board[r][c]]=1;
                            pq.push(board[r][c]);
                        }
                    }
                    /* int nxt = curr + dice;

                    auto [r,c] = numTorc(nxt,n);

                    if(board[r][c] != -1)
                        nxt = board[r][c];

                    if(!vis[nxt])
                    {
                        vis[nxt] = 1;
                        q.push(nxt);
                        */
                    
                }             
            }
            sp++;
        }
        return -1;
    }
};
//Time  = O(6 · n²) = O(n²) every number is visted once and 6 moves for each node 
//Space = O(n²)