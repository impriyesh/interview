#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include "LongestAbsoluteFilePath.h"
#include <string>

using namespace std;

/*
int Solution::lengthLongestPath(string input) {

    int len=0 ;
    //char ch;
    vector<int> fileLength;
    cout << endl;
    for (int i=0;i<input.size();i++){

        if((input[i] == '.') {
            while(input[i] != '\\'){
                ++len;
                ++i;
           }
           fileLength.push_back(len);
           len=0;
        }
        else if((input[i] == '\\') && ( input[++i] == 'n')){


        }
        else if((input[i] == '\\') && (input[++i] =='t') ){

        }

    }

    return len;
}



int main()
{
    Solution s;
    string input("dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext") ;
    cout << input;
    int result = s.lengthLongestPath(input);


    return 0;
}
*/

/*
int main() {
vector <int> a;
int i;

/*
for(i =0 ; i< 10 ; i++) {
    a.push_back(i);
}

for( i = 0;i<a.size() ; i++){
     cout << a[i];
}

*/

/*
map<int,int> myMap;
int j=1;
for(i=0;i<10; i++) {
    //mA.insert(2,true);
    if(i&1){
        myMap.insert(pair<int,int>(i,j++));
    }
    else{
        myMap.insert(pair<int,bool>(i,j+=2));
    }
}
map<int,int>::iterator it = myMap.begin();
for(it=myMap.begin(); it != myMap.end() ; ++it){
    cout << it->first << "==>" << it->second <<endl;
}

cout << "Another map   " <<endl;


map<int,int> anotherMap;
map<int,int>::iterator ait = anotherMap.begin();
anotherMap.insert(myMap.begin(),myMap.find(7));

for(ait =anotherMap.begin(); ait!= anotherMap.end();ait++){
    cout << ait->first << "  " << ait->second << endl;
}


return 0;
}
*/
/*
int Findsum( int start , int max){

    if(start <= max ){
        return(start+ Findsum(start+1,max));
    }

    cout << " \n\n start has crossed max \n\n";
    return 0;
}
*/

// top down dp
int memo[100000];

int getFibonacci(int n) {

    if(memo[n]!=-1){
        return memo[n];
    }

    if(n==0)
        return 0;
    if(n==1)
        return 1;
    memo[n]=getFibonacci(n-1) + getFibonacci(n-2);
    return memo[n];
}

int getNumberOfSetBits(int& n, int &m) {
    int count =0;

    /*
    while(n){
        if(n&1) count++;
        n/=2; // n= n>>1;
    }
    */

    int x = 1;

   /* for(int i=0;i<32;i++){
        if(n&(x<<i)){
            count++;
        }
    } */

    for(int i=0;i<32;i++){
        if( (n&(x<<i)) ^ (m&(x<<i)) ){
            count++;
        }
    }
    return count;
}

int main(){
    memset(memo,-1,sizeof(memo));
    int n,m;
    cout << "Enter num for fibonacci \n";
    cin >> n>>m;

    cout<<getNumberOfSetBits(n,m)<<endl;
    cout<<n<<endl;
}
