class Solution {
public:
    int minimumPushes(string word) {        
        return 8 * ((word.size() / 8) * ((word.size() / 8) + 1) / 2) +(word.size() % 8)* ((word.size() / 8) + 1);
    }
};