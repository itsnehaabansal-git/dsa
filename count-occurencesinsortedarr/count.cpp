class Solution {

    int first (vector<int>& arr, int target){
        int ans = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = (low + high )/2;
        
           if( arr[mid] >= target){
               ans = mid;
               high = mid-1;
           }
           else{
            low = mid +1;
           }

        }
        return ans;

    }



 int last (vector<int>& arr, int target){
        int ans = -1;
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = (low + high )/2;
        
           if( arr[mid] <= target){
               ans = mid;
              low = mid+1;
           }
           else{
           high = mid-1;
           }

        }
        return ans;

    }



public:
    int countOccurrences(vector<int>& arr, int target) {
         int f = first(arr,target);
         int l = last(arr,target);
         if( f == -1 or arr[f]!= target){
          return 0;
         }

         return l-f+1;



    }
};