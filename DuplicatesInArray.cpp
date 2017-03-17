#include <iostream>
#include <vector>
#include <map>

using namespace std;

std::vector<int>& FindDuplicates(vector<int> nums){

    vector<int> result;
    map<int, bool> find_duplicate;
    //map<int,int>::iterator it;
    //for(it = find_duplicate.begin(); it !=find_duplicate.end())
    for(int i=0; i< nums.size(); i++)
    {
        if(find_duplicate.find(nums[i]) != find_duplicate.end())
        {
            if(!find_duplicate[nums[i]])
            {
                result.push_back(nums[i]);
                find_duplicate[nums[i]] = true;
            }
        }
        else
        {
            find_duplicate.insert(pair<int,bool>(nums[i], false));
        }

    }

    return result   ;
}

int main()
{
    std::vector<int> result;
    std::vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);

    input.push_back(3);
    input.push_back(4);
    input.push_back(4);

    result=FindDuplicates(input);
    cout << "size of result " << result.size() << endl;
    for(int i=0;i<result.size();i++)
        cout << result[i] << "\t";
    //cout << result << endl;
    return 0;
}
