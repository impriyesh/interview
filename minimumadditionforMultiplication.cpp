#include <iostream>

using namespace std;
int minadd(int n, int m);

int minadd(int n, int m, int &count)
{
    ++count;
    int sum=n;
    if(m==0)
        return 0;
    if(m==1)
        return n;
    sum= minadd(n,m/2,count);
    if(m%2 == 0){
        return(sum+sum);
    }
    else {
        return(n + sum + sum);
    }


}

int main()
{
    int count =0;
    int mul = minadd(4,11,count);
    std::cout << mul <<"count=" << count;
   // int *cnt = new int;
    //*cnt =0;
//    printf("%d", mul);                                                                                                                 7);
//    cout << "count = " <<*cnt << endl;
    return 0;
}
