#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

vector<int> CountBits(int& nums)
{
    vector<int> result;
    int pow = 1;
    int p =0;
    for(int i=1; i<= nums; i++)
    {
        if(i == pow){
            result.push_back(1);
            pow = pow << 1 ;
            p=0 ;
        }
        else {
            //int p = i - pow;
            //cout << "result p= " << result[p];
            result.push_back(result[p] + 1);
            p++;
        }
    }
    return result;
}

int main()
{
    int input;
    cout << "Enter the Num \n";
    cin >> input;

    vector<int > result;
    result = CountBits(input);

    for(int i=0; i< input; i++)
    {
        cout << i + 1 << "=  " <<result[i] << endl;
    }


    return 0;
}
