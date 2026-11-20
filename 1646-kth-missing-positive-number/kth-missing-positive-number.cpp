class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p = k;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= p) {
                p++;
            }
            else{
            
              break;
            }
          
        }
        return p;
    }
};