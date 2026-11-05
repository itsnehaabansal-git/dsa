class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algo
        //  majority element always exists in the array
        int el;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt = 1;

            } else if (nums[i] == el) {
                cnt++;
            }

            else {
                cnt--;
            }
        }
        return el;
    }
};