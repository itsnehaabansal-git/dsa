class Solution {
public:
    int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end()); //sort
    int n = nums.size();

    for(int i =0 ; i< n ; i++){
        if(nums[i] != i){
             return i;
        }
    }
       return n; 
       
    }
};