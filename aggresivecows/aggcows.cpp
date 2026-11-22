class Solution {
    bool ispos(int mid, vector<int> &nums, int k){
        int cnt = 1;
      int  placed_cow_at = nums[0];
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] - placed_cow_at >= mid ){
                cnt++;
                 placed_cow_at = nums[i];
            }  
        }
        if(cnt >= k){
            return true;
        }
     else{return false;};
    }
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;   // min d 0 if dup stalls
        int n = nums.size();
        int high = nums[n-1] - nums[0];
     long long ans = 1;
        while(low<= high){
            int mid = (low + high)/2;
            if(ispos(mid,nums,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};