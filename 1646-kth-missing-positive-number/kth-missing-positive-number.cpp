class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int low = 0;
       int high = arr.size()-1;

       while(low<= high){
            int mid = (low +high)/2; // mid is an index
            int missing = arr[mid]-(mid+1); //3 missing numbers
            if(missing < k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
       }
       return low + k; // or high + k +1  high is pointing to 7 --- val of high is 3
    }
};