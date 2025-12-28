class Solution {
public:
int binary_search(vector<vector<int>>& grid,int &i)
{
    int left=0;
    int right=grid[i].size()-1;
    int mid=(left+right)/2;
    while(left<=right)
    {
        if(grid[i][mid]<0)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
        mid=(left+right)/2;
    }
    std::cout<<mid<<endl;
    return grid[i].size()-mid-1;
}
    int countNegatives(vector<vector<int>>& grid) {
        int size=grid.size();
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(grid[i][0]<0)
            {
                count+=grid[i].size();
                continue;
            }
            count+=binary_search(grid,i);
        }
        return count;
    }
};