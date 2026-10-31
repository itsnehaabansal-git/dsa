//Sum of Highest and Lowest Frequency


class Solution {
public:
    int sumHighestAndLowestFrequency(vector<int>& nums) {
  unordered_map<int,int>mpp; key value pair 
  for(int i = 0; i< nums.size(); i++){
    //mpp[key] = value
       mpp[nums[i]]++;  // basically value increment ho gyi 
  }
  int maxifreq  = 0;
  int minifreq  = nums.size();
// it.second is value which is storing freq
for(auto it : mpp){
    maxifreq = max(maxifreq, it.second); // isse max jo element arha h uski freq milegi 
    minifreq= min(minifreq,it.second); // 
}

return maxifreq +minifreq; 
    }
};



// Second Highest Occurring Element
// Given an array of n integers, find the second most frequent element in it.

// If there are multiple elements that appear second most frequent times, find the smallest of them.

// If second most frequent element does not exist return -1.



class Solution {
public:
    int secondMostFrequentElement(vector<int>& nums) {
    
    unordered_map<int,int>mpp;

    for(int i =0 ; i< nums.size(); i++){
        mpp[nums[i]]++; // value++
    }

  int ans = -1;
  int maximum1 = 0;
  int secondmax = 0;

    for(auto it : mpp){
      int freq = it.second;
    

      if(freq > maximum1){
        secondmax = maximum1;
        maximum1 = freq;

      }
      else if (freq < maximum1 and freq > secondmax){
        secondmax = freq;
      }
    }
    for(auto it : mpp){
        // agr do number h jinka secondmax same h toh chota number lege agr secondmax exist nhi krta toh -1 lege 
        if(secondmax == it.second and secondmax != 0){ // basically secondmax ki frq wala it dhundo 
           if(ans == -1 or it.first < ans){      // agr ans -1 h toh update kra to it.first fir agr it.first chota h ans se toh usko /update kr dia it .first pr jisse agr 2 elements aise h jinka secondmax same h toh unka min element is considered
            ans = it.first;
           }
        }


    }
    return ans;
    }
};