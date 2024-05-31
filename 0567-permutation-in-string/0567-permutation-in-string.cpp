class Solution {
public:
    bool allZero(vector<int>& arr) {
    for (int count : arr) {
        if (count != 0) {
            return false;
        }
    }
    return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if (l1 > l2) {
            return false; // s1 can't be a permutation of a substring of s2 if it's longer
        }

        std::vector<int> arr(26, 0); // Initialize a vector to count characters

        // Count frequency of each character in s1
        for (int i = 0; i < l1; ++i) {
            arr[s1[i] - 'a']++;
        }

        // Sliding window to check each substring of s2
        for (int i = 0; i < l2; ++i) {
            arr[s2[i] - 'a']--;

            if (i >= l1) {
                arr[s2[i - l1] - 'a']++;
            }

            if (allZero(arr)) {
                return true;
            }
        }

        return false;

    }
};