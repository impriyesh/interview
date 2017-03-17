#include <iostream>

using namespace std;

int numOnes(int num, int &count){


    int sequence_Of_Ones=1,mod_of_num;
    bool flag = true;
    do{
        ++count;
        mod_of_num=sequence_Of_Ones%num;
        if(mod_of_num ==0)
            flag=false;
        else
            sequence_Of_Ones=mod_of_num*10 +1;
    }while(flag);

    return count;

}

int main()
{

    int count =0;
    std::cout << numOnes(333,count) <<endl;
    cout << "count=" << count <<endl;
    char *b = new char[count+1];
    for(int i=0;i<count;i++)
        b[i]='1';
//    b[i]='\0';
    for(int i=0;i<count;i++)
        cout <<b[i];
    return 0;
}
