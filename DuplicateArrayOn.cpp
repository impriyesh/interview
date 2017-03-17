#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

std::vector<int>& FindDuplicates(vector<int> nums){

    vector<int> result;
    //map<int,int>::iterator it;
    //for(it = find_duplicate.begin(); it !=find_duplicate.end())
    for(int i=0; i < nums.size(); i++)
    {
        if(nums[abs(nums[i])-1] < 0 )
            result.push_back(abs(nums[i]));
        else
            nums[abs(nums[i])-1] = -1 * nums[abs(nums[i])-1];

    }


    for(int i=0; i < nums.size(); i++)
    {
        if(nums[i] < 0 )
            nums[i] = -1 * nums[i];

    }

    return result;
}

int main()
{
    std::vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);

    input.push_back(3);
    input.push_back(4);
    input.push_back(7);

    cout<<"Find duplicates\n";
    std::vector<int> result =FindDuplicates(input);
    cout<<"Find duplicates done..\n";
    cout << "size of result " << result.size() << endl;
    for(int i=0;i<result.size();i++)
        cout << result[i] << "\t";
    //cout << result << endl;
    return 0;
}
