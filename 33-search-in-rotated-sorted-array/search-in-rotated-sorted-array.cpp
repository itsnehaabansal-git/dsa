class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
             else if (nums[low] <= nums[mid]) {
                // means left is sorted
                if (target >= nums[low] and target <= nums[mid]) {
                    // target lies in left side
                    // lets eliminate right side
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            else { // right sorted

                if (target >= nums[mid] and target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};