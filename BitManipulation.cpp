#include "MyString.h"
#include <string.h>
#include <iostream>

using namespace std;


class solution {

public:
    int HammingWeight(int n){
        int count =0;
        for(int i=0;i< 32 ;i++){
            if(getBit(n,i) == true){
                count++;
            }
        }
        return count;
    }

    bool getBit(int n, int ig){
        int j = n & (1 << ig);
        return j!=0 ;
    }

};

int main(){
    solution s;
    cout << s.HammingWeight(78);

}
