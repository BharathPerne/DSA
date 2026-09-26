class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> pairs;
        for (int i = 0; i < knowledge.size(); i++) {
            pairs[knowledge[i][0]] = knowledge[i][1];
        }
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {      
                i++;      
                string found_s = "";
                while (s[i] != ')') {
                    found_s += s[i];
                    i++;                    
                }
                if (pairs.find(found_s) != pairs.end()) {
                    result += pairs[found_s];
                } else {
                    result += '?';
                }
            }
            else{
                result += s[i];
            }
        }
        return result;
    }
};