class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int value = 0;
            int value_n = 0;
            if (s[i] == 'M') {
                value = 1000;
            }
            if (s[i] == 'D') {
                value = 500;
            }

            if (s[i] == 'C') {
                value = 100;
            }

            if (s[i] == 'L') {
                value = 50;
            }
            if (s[i] == 'X') {
                value = 10;
            }

            if (s[i] == 'V') {
                value = 5;
            }
            if (s[i] == 'I') {
                value = 1;
            }

            if ((i + 1) < s.length()) {
                if (s[i+1] == 'M') {
                    value_n = 1000;
                }
                if (s[i+1] == 'D') {
                    value_n = 500;
                }

                if (s[i+1] == 'C') {
                    value_n = 100;
                }

                if (s[i+1] == 'L') {
                    value_n = 50;
                }
                if (s[i+1] == 'X') {
                    value_n = 10;
                }

                if (s[i+1] == 'V') {
                    value_n = 5;
                }
                if (s[i+1] == 'I') {
                    value_n = 1;
                }
            }
            if(value < value_n){
                ans-= value;
            }
            else{
                ans+= value;
            }

        }
        return ans;
    }
};