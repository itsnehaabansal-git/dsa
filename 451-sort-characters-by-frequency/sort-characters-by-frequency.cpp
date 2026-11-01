class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        string s1 ="";

       for(int i = 0; i< s.length(); i++){
        mpp[s[i]]++;
       }
       priority_queue<pair<int,char>>pq; //max heap //on the basis of freq
       for(auto it : mpp){
        pq.push({it.second , it.first});
       }
      

      while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        for(int i = 0; i< it.first; i++){
            s1+=it.second;
        }

      }
      return s1;

    }

};