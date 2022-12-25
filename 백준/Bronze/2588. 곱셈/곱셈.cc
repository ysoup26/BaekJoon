#include <iostream>

using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    int C1,C2,C3;
    C1=B%10;
    C2=B%100/10;
    C3=B/100;
    cout<<A*C1<<endl;
    cout<<A*C2<<endl;
    cout<<A*C3<<endl;
    cout<<(A*C1)+(A*C2*10)+(A*C3*100);
    return 0;
}