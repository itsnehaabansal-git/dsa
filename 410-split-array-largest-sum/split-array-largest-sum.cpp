class Solution {
    bool ispos(int mid, vector<int>& nums, int k){
        int sum = 0;
        int cnt =1;
        for(int i = 0; i< nums.size(); i++){
            if(sum + nums[i] <= mid){
               sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }

        }
        return cnt <= k ;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            high += nums[i];
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ispos(mid, nums, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};