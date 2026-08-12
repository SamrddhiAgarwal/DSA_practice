class Solution {
public:
    int helper(int i,vector<int>& height,int bricks,int ladders)
    {
        int n=height.size();
        if(i>=n) return 0;

        if(height[i-1]>=height[i])
        return 1+helper(i+1,height,bricks,ladders);

        else
        {
            int b=0,l=0;
            if(bricks>=height[i]-height[i-1])
            b=1+helper(i+1,height,bricks-(height[i]-height[i-1]),ladders);
            if(ladders>0)
            l=1+helper(i+1,height,bricks,ladders-1);
            
            return max(b,l);
        }
    }
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        // return  helper(1,heights,bricks,ladders);
        int n=height.size();
        priority_queue<int>max_bricks;
        for(int i=0;i<n-1;i++)
        {
            int diff=height[i+1]-height[i];
            if(diff>0)
            {
                bricks-=diff;
                max_bricks.push(diff);

                if(bricks<0)
                {
                    if(ladders>0)
                    {
                        bricks+=max_bricks.top();
                        max_bricks.pop();
                        ladders--;
                    }
                    else
                    return i;
                }
            }
        }
        return n-1;
    }
};