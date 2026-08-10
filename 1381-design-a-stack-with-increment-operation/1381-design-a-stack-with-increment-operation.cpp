class CustomStack {
public:
    vector<int>st;
    int mx;
    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(st.size()<mx)
        st.push_back(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int ans=st.back();
        st.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        int n=st.size();
        for(int i=0;i<min(n,k);i++)
        {
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */