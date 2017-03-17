#include <iostream>
#include <vector>
#include <map>

using namespace std;


void swapnum(vector<int> &array, int i, int j)
{
    if(i == j)
        return;

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void permute(vector<int> &nums, int index, vector<vector<int> > &output)
{

    if(index >= nums.size() )
        output.push_back(nums);
    else
    {
        std::map<int, int> visited;
        for(int i=index; i<nums.size(); i++)
        {
           if( visited.find(nums[i]) == visited.end() )
           {
                swapnum(nums, i, index);
                permute(nums, index+1, output);
                swapnum(nums, i, index);
                visited.insert(std::pair<int, int>(nums[i], 0));
           }
        }
    }

}

vector<vector<int> > permuteUnique(vector<int> &nums)
{
    vector<vector<int> > output;
    permute(nums, 0, output);
    return output;
}

int main() {

   vector<int>input;
   vector<vector<int> > res;
   input.push_back(1);
   input.push_back(2);
   input.push_back(1);
   input.push_back(1);
   //input.push_back(1);

    res = permuteUnique(input);

    cout<<"[";
    for(int i=0; i<res.size(); i++)
    {
        vector<int> vec = res[i];
        if(i>0)
            cout<<",";

        cout<<"\n\t[";
        for(int j=0; j<vec.size(); j++)
        {
            if(j>0)
                cout<<",";
            cout<<vec[j];
        }
        cout<<"]";
    }
    cout<<"\n]";

}
