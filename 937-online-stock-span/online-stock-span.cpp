class StockSpanner {
stack<pair<int,int>>s;
int index =-1;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int ans =0;
        index = index +1;
        while(!s.empty() and s.top().first <= price ){
            s.pop();
        }
         ans = index - (s.empty() ? -1 :s.top().second);
        s.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */