// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//         vector<bool> answer(nums.size(), false);
//         long long int result = 0, index = 0;
//         for (int i = nums.size() - 1; i >= 0; i--) {
//             if (nums[i] == 1) {
//                 result += pow(2, index);
//             }
//             index++;
//         }
//         // std::cout<<result;
//         for (int i = nums.size() - 1; i >= 0; i--) {
//             if (result % 5 == 0) {
//                 answer[i] = true;
//             }
//             if (nums[i] == 1) {
//                 result -= pow(2, (nums.size() - 1 - i));
//             }
//         }
//         return answer;
//     }
// };


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
     vector<bool> answer;
     int current=0;
     for(int i=0;i<nums.size();i++)   
     {
        current=(current*2+nums[i])%5;
        answer.push_back(!current);
     }
     return answer;
    }
};