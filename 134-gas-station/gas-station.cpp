class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int totalGas=0,totalcost=0;
       int ans=0,result=0;;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i];
            totalcost+=cost[i];
            ans+=(gas[i]-cost[i]);
            if(ans<0){
                result=i+1;
                ans=0;
            }
        }
        return totalGas<totalcost ? -1 : result;
    }
};