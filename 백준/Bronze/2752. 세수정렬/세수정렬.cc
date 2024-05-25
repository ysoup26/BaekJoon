#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int Arr[3];
    cin>>Arr[0]>>Arr[1]>>Arr[2];
    sort(Arr,Arr+3);
    cout<<Arr[0]<<" "<<Arr[1]<<" "<<Arr[2];
    return 0;
}