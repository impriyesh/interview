#include <iostream>
using namespace std;

struct findSize {

    char c;
    int a;
    float b;

};
int main()
{
    struct findSize b;
    struct findSize *a = &b;
    //cout << a;
    cout << (char*)(a+1) - (char*)a << endl;
    cout << sizeof(struct findSize)<< "total=" << sizeof(findSize::a) + sizeof(findSize::b) + sizeof(findSize::c);
    return 0;
}
