#include <iostream>
#include <vector>
#include <map>

using namespace std;


vector<int> countBits(int num) {

        vector<int> result;

        result.push_back(1);
        result.push_back(2);
        result.push_back(3);

        return result;
    }



int main()
{
   vector<int>res;
   res = countBits(10);
    cout <<"[";
    for(int i=0; i<res.size();i++)
        cout << res[i] << ",";
    cout <<"]";


}
