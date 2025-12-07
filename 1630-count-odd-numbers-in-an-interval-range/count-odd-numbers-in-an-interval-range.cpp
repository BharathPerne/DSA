class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            count+=i%2;
        }
        return count;
    }
};