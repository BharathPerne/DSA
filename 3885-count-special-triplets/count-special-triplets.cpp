class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // int count=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]!=(nums[j]*2))
        //         {
        //             continue;
        //         }
        //         for(int k=j+1;k<nums.size();k++)
        //         {
        //             if(nums[i]==(nums[j]*2)&&nums[k]==(nums[j]*2))
        //             {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;
        
        // int count=0;
        // for(int i=1;i<nums.size();i++)
        // {
        //     int value=nums[i]*2;
        //     int it1 = std::count(nums.begin(), nums.begin()+i, value);
        //     int it2 = std::count(nums.begin()+i+1, nums.end(), value);
    
        //     if (it1&&it2) {
        //         count+=it1*it2;
        //     } 
        // }
        // return count;
        long long count=0;
        int MODULO=pow(10,9)+7;
        map<int,int> beforeValue;
        beforeValue[nums[0]]=1;
        map<int,int> afterValue;
        for(int i=1;i<nums.size();i++)
        {
            afterValue[nums[i]]++;
        }
        for(int i=1;i<nums.size();i++)
        {
             int current = nums[i];
             afterValue[current]--;
             if(afterValue[current]==0)
             {
                afterValue.erase(current);
             }
            int value=nums[i]*2;
            auto it1=beforeValue.find(value);
            auto it2=afterValue.find(value);
            if(it1!=beforeValue.end()&&it2!=afterValue.end())
            {
                long long leftCount = it1->second;
                long long rightCount = it2->second;
                
                
                long long product = (leftCount * rightCount) % MODULO;
                count = (count + product) % MODULO;
            }
           beforeValue[current]++;
        }
        return count;
    }
};