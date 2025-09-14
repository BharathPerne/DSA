class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch;
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelError;
        
        for (const string& word : wordlist) {
            exactMatch.insert(word);
            
            string lowerWord = toLower(word);
            if (caseInsensitive.find(lowerWord) == caseInsensitive.end()) {
                caseInsensitive[lowerWord] = word;
            }
            
            string devoweled = replaceVowels(lowerWord);
            if (vowelError.find(devoweled) == vowelError.end()) {
                vowelError[devoweled] = word;
            }
        }
        
        vector<string> result;
        for (const string& query : queries) {
            if (exactMatch.find(query) != exactMatch.end()) {
                result.push_back(query);
                continue;
            }
            
            string lowerQuery = toLower(query);
            if (caseInsensitive.find(lowerQuery) != caseInsensitive.end()) {
                result.push_back(caseInsensitive[lowerQuery]);
                continue;
            }
            
            string devoweledQuery = replaceVowels(lowerQuery);
            if (vowelError.find(devoweledQuery) != vowelError.end()) {
                result.push_back(vowelError[devoweledQuery]);
                continue;
            }
            
            result.push_back("");
        }
        
        return result;
    }
    
private:
    string toLower(const string& s) {
        string result = s;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
    
    string replaceVowels(const string& s) {
        string result = s;
        for (char& c : result) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return result;
    }
};