#include <iostream>

using namespace std;

long int F(int n){
    if(n == 0 || n == 1)
        return 1;
    return n*F(n-1);
}

int main(){
    int N;
    cin>>N;
    cout<<F(N);
    return 0;
}