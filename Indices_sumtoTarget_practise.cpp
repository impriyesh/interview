#include <iostream>
#include <vector>
#include <map>

using namespace std;


vector<int> FindIndices(vector<int> nums, int target){

    std::map<int,int>findInd;
    vector<int> result;
    for(int i=0;i< nums.size();i++){

    }



}


int main(){

    vector<int> nums,res;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    res= FindIndices(nums,5);
    cout << res[0] << "\t" << res[1];

}
