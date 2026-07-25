class Solution {
public:
    int maxProduct(int n) {
        vector<int> numbers;
        while(n!=0){
            int value=n%10;
            numbers.push_back(value);
            n=n/10;
        }
        sort(numbers.begin(),numbers.end());
        return numbers[numbers.size()-1]*numbers[numbers.size()-2];
    }
};