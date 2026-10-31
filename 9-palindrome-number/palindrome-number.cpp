class Solution {
public:
    bool isPalindrome(int x) {
        long long  y = x;
        long long rev = 0;
        if( x< 0){
            return false;
        }
        if(x == 0){
            return true;
        }
        while (x > 0) {
            int ld = x % 10;
            rev = rev * 10 + ld;
            x = x/10;
        }
        if(rev == y){
            return true;
        }
        return false;
    }
};