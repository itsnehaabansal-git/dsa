class Solution {
    void subarrmini(vector<int> nums, vector<int>& subarrmin,vector<int>&pse ,vector<int>&nse) {
        int n = nums.size();
        
        stack<int> s1;
        stack<int> s2;
        // pse
        for (int i = 0; i < n; i++) {
            while (!s1.empty() and nums[s1.top()] >= nums[i]) {
                s1.pop();
            }
            if (s1.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = s1.top();
            }
            s1.push(i);
        }
        // nse
        for (int i =  n - 1; i >= 0; i--) {
            while (!s2.empty() and nums[s2.top()] > nums[i]) {
                s2.pop();
            }
            if (s2.empty()) {
                nse[i] = n;
            } else {
                nse[i] = s2.top();
            }
            s2.push(i);
        }
    }
    void subarrmaxi(vector<int> nums, vector<int>& subarrmax ,vector<int>&pge , vector<int>&nge) {
        int n = nums.size();
       
        stack<int> s1;
        stack<int> s2;
        // pge
        for (int i = 0; i < n; i++) {
            while (!s1.empty() and nums[s1.top()] <= nums[i]) {
                s1.pop();
            }
            if (s1.empty()) {
                pge[i] = -1;
            } else {
                pge[i] = s1.top();
            }
            s1.push(i);
        }
        // nge
        for (int i =  n - 1; i >= 0; i--) {
            while (!s2.empty() and nums[s2.top()] < nums[i]) {
                s2.pop();
            }
            if (s2.empty()) {
                nge[i] = n;
            } else {
                nge[i] = s2.top();
            }
            s2.push(i);
        }
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        vector<int> nse(n);
        vector<int> pge(n);
        vector<int> nge(n);
        vector<int> subarrmin(n);
        vector<int> subarrmax(n);
        subarrmini(nums, subarrmin,pse,nse);
        subarrmaxi(nums, subarrmax,pge,nge);
        long long  t1 = 0;
        for (int i = 0; i < n; i++) {
            long long  left = i - pse[i];
            long long  right = nse[i] - i;
            t1 = t1 + (left * right * nums[i]);
        }

        long long t2 = 0;
        for (int i = 0; i < n; i++) {
            long long  left = i - pge[i];
            long long  right = nge[i] - i;
            t2 = t2 + (left * right * nums[i]);
        }
         long long s = t2-t1;
        return s;
    }
};