class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> result;
        // vector<int> sliding_window;
        // int index=0;
        // for(int i=0;i<k;i++)
        // {
        //     sliding_window.push_back(nums[i]);
        // }
        // for(int i=k;i<nums.size();i++)
        // {
        //     if(i>=k)
        //     {
        //        index=0;
        //         int max_val=INT_MIN;
        //         while(index<sliding_window.size())
        //         {
        //             max_val=max(max_val,sliding_window[index]);
        //             index++;
        //         }
        //         result.push_back(max_val);
        //         sliding_window.erase(sliding_window.begin());
        //         sliding_window.push_back(nums[i]);
        //         continue;
        //     }   
        // }
        //        index=0;
        //         int max_val=INT_MIN;
        //         while(index<sliding_window.size())
        //         {
        //             max_val=max(max_val,sliding_window[index]);
        //             index++;
        //         }
        //         result.push_back(max_val);
        // return result;
        deque<int> dq;
        vector<int> result;
        for(int i=0;i<k;i++)
        {
            while(dq.size()&&nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<nums.size();i++)
        {
            result.push_back(nums[dq.front()]);
            while(dq.size()&&dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(dq.size()&&nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        return result;
    }
};