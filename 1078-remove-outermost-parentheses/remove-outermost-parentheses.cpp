class Solution {
public:
    string removeOuterParentheses(string s) {
        string p = "";
        int cnt = 0;
        for(int i = 0 ; i < s.length() ; i++){
        
           if(s[i] == '(' ){
              if(cnt >= 1){
                p = p +s[i];
              }

               cnt++;
           }
           if(s[i] == ')'){
            cnt--;
              if(cnt >=1){
                 p = p +s[i];
              }
             
           }
        }
        return p;
    }
};