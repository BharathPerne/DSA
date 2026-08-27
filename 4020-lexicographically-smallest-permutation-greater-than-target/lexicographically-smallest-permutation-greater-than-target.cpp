class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        for (int pivot = n - 1; pivot >= 0; pivot--) {
            vector<int> rem = cnt;
            bool possible = true;

            for (int i = 0; i < pivot; i++) {
                int c = target[i] - 'a';
                if (rem[c] == 0) {
                    possible = false;
                    break;
                }
                rem[c]--;
            }

            if (!possible)
                continue;

            int x = target[pivot] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string ans = target.substr(0, pivot);
                ans += char('a' + c);
                rem[c]--;

                for (int j = 0; j < 26; j++)
                    ans += string(rem[j], char('a' + j));

                return ans;
            }
        }

        return "";
    }
};
