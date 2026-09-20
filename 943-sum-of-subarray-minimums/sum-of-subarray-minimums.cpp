class Solution {
 void pse(vector<int> arr, vector<int>&ps) {
            int n = arr.size();
            stack<int> s;
            
            for (int i = 0; i < n; i++) {
                while (!s.empty() and arr[s.top()] >= arr[i]){
                    s.pop();
            }
            if (s.empty()) {
                ps[i] = -1;
            }
             else {
                ps[i] = s.top();
            }
            s.push(i);
        }}
        void nse(vector<int> arr, vector<int>&ns) {
            int n = arr.size();
            stack<int> s;
        
            for (int i = n-1; i >= 0; i--) {
                while (!s.empty() and arr[s.top()] > arr[i]){
                    s.pop();
            }
            if (s.empty()) {
                ns[i] = n;
            } else {
                ns[i] = s.top();
            }
            s.push(i); // storing indexes thatswhy i
        }}
       
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 +7;
        int n = arr.size();
        long long t =0;
        vector<int> ps(n);
        vector<int> ns(n);
       pse(arr,ps);
       nse(arr,ns);
       for(int i =0; i< n; i++){
        int left = i - ps[i];
        int right = ns[i] - i;
       t = (t + (long long)left * right * arr[i]) % mod;
       };


    return t;
    }
};