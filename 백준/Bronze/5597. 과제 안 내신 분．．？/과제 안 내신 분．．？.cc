
#include <iostream>

using namespace std;

int main()
{
    int student[31];
    for(int i=1;i<=30;i++)
    {
        student[i]=0;
    }
    for(int i=1;i<=28;i++)
    {
        int index;
        cin>>index;
        student[index]=1;
    }
    for(int i=1;i<=30;i++)
    {
        if(student[i]==0)
            cout<<i<<endl;
    }
    return 0;
}
