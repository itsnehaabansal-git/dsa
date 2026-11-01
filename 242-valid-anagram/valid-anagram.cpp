class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            freq[index]++;
        }
        for (int j = 0; j < t.length(); j++) {
            int index = t[j] - 'a';
            freq[index]--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
