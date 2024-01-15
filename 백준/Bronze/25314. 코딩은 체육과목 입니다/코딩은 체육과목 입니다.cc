#include <iostream>

using namespace std;

int main(){
    int N,check;
    cin>>N;
    check = N/4;
    if(N%4 != 0) //4로 나누어떨어지지 않는다면 나머지를 저장할 공간도 주어야 한다. 
        check++;

    for(int i=1;i<=check;i++){
        cout<<"long ";
    }
    cout<<"int";
    return 0;
}