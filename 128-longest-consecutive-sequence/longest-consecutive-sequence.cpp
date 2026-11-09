class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int longest = 1;
        int ls = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i]  -1 == ls) {
                cnt++;
                ls = nums[i];
            } else if (nums[i] != ls) {
                cnt = 1;
                ls = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};