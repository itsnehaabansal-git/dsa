class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int>s;
        for(int i =0 ; i< n ; i++){
           while(!s.empty() and k >0 and s.top()-'0' > num[i]-'0'){
            s.pop();
            k--;
           }
          s.push(num[i]);


        }
        while(k >0){
             s.pop();
            k--;
        }
        if(s.empty()){
            return  "0";
        }
        string res ="";
        while(!s.empty()){
          res  += s.top();
          s.pop();
        }
        while(res.size() > 0 and res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        if (res.empty()){
            return "0";
        }
        return res;
    }
};