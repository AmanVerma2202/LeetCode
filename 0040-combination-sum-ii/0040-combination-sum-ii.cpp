class Solution {
    void comb(int ind,int target,vector<int>& candidates,  vector<vector<int>>& ans, vector<int>& combination) {
        if(target==0){
            ans.push_back(combination);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            combination.push_back(candidates[i]);
            comb(i+1,target-candidates[i],candidates,ans,combination);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        comb(0,target, candidates,ans, combination);

        
        return ans;
    }
};