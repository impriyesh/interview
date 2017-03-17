#include <iostream>

using namespace std;

void copymem (void * src, void *dest, int size)
{
char * source = (char *)src;
char * destination = (char *)dest;

for( int i=0;i<size;i++) {
    destination[i]=source[i];
   // cout << destination[i];
}
}
int main()
{
    int a[] = { 1,2,3,4 };
    int *b = new int[4];
    int n = sizeof(a);
    //cout <<n;
    copymem(a,b,n);
    for(int i=0;i<4;i++)
        cout <<b[i];
    return 0;
}
