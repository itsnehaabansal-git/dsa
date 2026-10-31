// basic string 
class Solution{	
	public:		
		bool palindromeCheck(string& s){
			//your code goes here

            string s1 ="";
            string s2 = "";


            for(int i = s.size()-1 ; i>=0 ; i--){
                if(isalnum(s[i])){
                    s1+= s[i];
                }
            }
              for(int i = 0; i < s.size() ; i++){
                if(isalnum(s[i])){
                    s2+= s[i];
                }
            }

           return s1 == s2;

		}
};