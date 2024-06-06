class Solution {
public:
    int longestPalindrome(string s) {
        int ans =0;
        unordered_map<char,int> mp;
        for( int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int count=0;
        
        for (auto it = mp.begin(); it != mp.end(); it++){
            if(it->second%2==0){
                ans+=it->second;
            }else{
                if(it->second%2!=0 && it->second>1){
                    ans+=it->second-1;
                }
            }
            if(it->second%2!=0){
                count++;
            }
        }
        if(count){
            return ans+1;
        }
        return ans;


    }
};