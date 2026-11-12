class Solution {
public:
    int sumOfMultiples(int n) {
        int cnt = 0;
        for(int i = 3 ; i<= n ; i++){
            if(i % 3 == 0 or i % 5 == 0 or i %7 ==0){
            cnt+= i; //sum
            }
        }
        return cnt;
    }
};