class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int apple_sum=0;
        int min_box=0;
        for(int i=0;i<apple.size();i++)
        {
            apple_sum+=apple[i];
        }
        for(int i=0;i<capacity.size();i++)
        {
            min_box+=capacity[i];
            if(min_box>=apple_sum)
            {
                return i+1;
            }
        }
        return -1;
    }
};