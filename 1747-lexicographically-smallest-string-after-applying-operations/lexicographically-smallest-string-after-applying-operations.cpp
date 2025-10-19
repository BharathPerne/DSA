class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        unordered_set<string> visited;
        queue<string> q;
        string smallest = s;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // Update smallest
            if (curr < smallest) smallest = curr;
            
            // Operation 1: add a to odd indices
            string addOp = curr;
            for (int i = 1; i < n; i += 2) {
                addOp[i] = '0' + (addOp[i] - '0' + a) % 10;
            }
            if (visited.find(addOp) == visited.end()) {
                visited.insert(addOp);
                q.push(addOp);
            }
            
            // Operation 2: rotate right by b
            string rotateOp = curr.substr(n - b) + curr.substr(0, n - b);
            if (visited.find(rotateOp) == visited.end()) {
                visited.insert(rotateOp);
                q.push(rotateOp);
            }
        }
        
        return smallest;
    }
};