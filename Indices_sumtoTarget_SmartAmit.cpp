#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
     //   std::sort(nums.begin(),nums.end());
        int n= nums.size();
       std::map<int, int> indexMap;
       for(int i=0;i<n;i++)
        {
            std::map<int, int>::iterator itr = indexMap.find(target - nums[i]);
            if(itr == indexMap.end())
            {
                indexMap.insert(std::pair<int,int>(nums[i], i));
            }
            else
            {
                indices.push_back(indexMap[target - nums[i]]);
                indices.push_back(i);
                break;
            }

        }
    return indices;
}

int main(){

    vector<int> a;
    a.push_back(4);
    a.push_back(2);
    a.push_back(3);
    a.push_back(100);
    a.push_back(5);
    vector<int> b;
    b=twoSum(a,8);
    cout <<b[0]<<"\t" <<b[1];
    return 1;
}
