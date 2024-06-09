class Solution {
public:
    bool isVowel(char ch) {
        char lowerCh = tolower(ch);
        return lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u';
    }
    string sortVowels(string s) {
        // Step 1: Extract vowels from the string
        vector<char> vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }
        
        // Step 2: Sort the vowels
        sort(vowels.begin(), vowels.end());
        
        // Step 3: Create a new string t with consonants in place and sorted vowels
        string t = s;
        int vowelIndex = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                t[i] = vowels[vowelIndex++];
            }
        }
        return t;
    }
};