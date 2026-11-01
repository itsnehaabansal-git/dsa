// sorted the strings because we want to compare the smallest and largest string to find the common prefix for ex if we have 
// aaa aa aaa
// if we compare first and last string we will give ans as aaa 
//  but it is aa


// longest common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int n = strs.size();
       sort(strs.begin(), strs.end());
       string s ="";
       string first = strs[0];
       string last = strs[n-1];
       for(int i =0 ; i < min(first.size(),last.size()); i++){
        if(first[i] != last[i]){
            return s;
        }
        s+= first[i];
       }

   return s;
    }
};