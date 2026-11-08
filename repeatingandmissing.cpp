class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
      int n = nums.size();
      int repeating =-1 ;
      int missing =-1;
      vector<int>hash(n+1 ,0);

     for(int i = 0 ; i< n; i++){
        hash[nums[i]]++; 
     }

     for(int i = 1 ; i<= n ; i++){
        if(hash[i]== 2 ){
            repeating = i;
            
        }
        if(hash[i] == 0){
            missing = i;
        }
         if(missing != -1 and repeating != -1){
              break;
             }
     }
 
      return {repeating , missing};

    }
};