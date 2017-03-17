#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
     //   std::sort(nums.begin(),nums.end());
        int n= nums.size();
        bool flag = false;
       for(int i=0;i<n;i++){
           if(flag)
            break;
            for(int j=i+1;j<n;j++){
                if(flag)
                break;
                int sum =  nums[i] + nums[j];
                if(target == sum){
                    indices.push_back(i);
                    indices.push_back(j);
                    flag=true;
                }
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
