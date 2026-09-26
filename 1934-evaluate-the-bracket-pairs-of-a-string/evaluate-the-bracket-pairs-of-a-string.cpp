class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> pairs;
        for (int i = 0; i < knowledge.size(); i++) {
            pairs[knowledge[i][0]] = knowledge[i][1];
        }
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            int index=i;
            if (s[i] == '(') {      
                i++;      
                string found_s = "";
                while (s[i] != ')') {
                    found_s += s[i];
                    i++;                    
                }
                if (pairs.find(found_s) != pairs.end()) {
                    s.replace(index,i-index+1,pairs[found_s]);
                    i=index+(pairs[found_s].size()-1);
                } else {
                    s.replace(index,i-index+1,"?");
                    i=index;
                }                
            }            
        }
        return s;
    }
};