class Solution
{

public:
    int findKRotation(vector<int> &nums)
    {
        int ans = INT_MAX;

        int low = 0;
        int high = nums.size() - 1;
        int index = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[high])
            {
                if (nums[low] < ans)
                {
                    index = low;
                    ans = nums[low];
                    break;
                }
            }
            if (nums[low] <= nums[mid])
            {
                if (nums[low] < ans)
                {
                    index = low;
                    ans = nums[low];
                }

                low = mid + 1;
            }
            else
            {

                if (nums[mid] < ans)
                {
                    index = mid;
                    ans = nums[mid];
                }

                high = mid - 1;
            }
        }
        return index;
    }
};