class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size()> 0){
            int digit = num.back()-'0';
            if(digit % 2 != 0){
               return num;
            }
            num.pop_back();

        }
        return "";
    }
};