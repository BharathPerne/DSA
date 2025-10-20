class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int answer=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i][0]=='-'||operations[i][2]=='-')
            {
                answer--;
            }
            else
            {
                answer++;
            }
        }
        return answer;
    }
};