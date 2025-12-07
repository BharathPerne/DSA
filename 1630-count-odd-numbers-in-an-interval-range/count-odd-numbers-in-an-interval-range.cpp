class Solution {
public:
    int countOdds(int low, int high) {
        int count=high-low+1;
        // for(int i=low;i<=high;i++)
        // {
        //     count+=i%2;
        // }
        if(count%2==0)
        {
            return count/2;
        }
        else
        {
            return (count/2+low%2);
        }
    }
};