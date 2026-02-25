class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp;
        for(int i=0;i<arr.size();i++)
        {
            int num=arr[i];
            int res=0;
            while(num)
            {
                res+=(num&1);
                num=num>>1;
            }
            auto p=make_pair(arr[i],res);
            temp.push_back(p);
        }
        std::sort(temp.begin(), temp.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;  
            }
            return a.first < b.first;  // Secondary: key ascending
        });
        vector<int> answer;
        for (const auto& [value,bits] : temp) 
        {
            answer.push_back(value);
        }
        return answer;
        }
};