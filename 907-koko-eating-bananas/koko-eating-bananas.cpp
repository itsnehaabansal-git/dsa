class Solution {
long long time(vector<int>& piles,int mid){
    long long total =0;
    for(int i = 0 ; i< piles.size(); i++){
   total += ceil((double)piles[i] / mid);
    }
    return total;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = 0;
        while(low<= high){
              long long mid = (low+ high)/2;
              if(time(piles,mid) <= h){
                ans  = mid;
                high = mid-1;
              }
              else{
                low = mid+1;
              }
        }
        return ans;
    }
};