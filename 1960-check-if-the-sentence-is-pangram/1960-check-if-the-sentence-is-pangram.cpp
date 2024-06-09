class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int>mp;
        for(int i=0;i<sentence.length();i++){
            mp[sentence[i]]++;
        }
        int s=mp.size();
        if(s==26){
            return true;
        }
        return false;
    }
};