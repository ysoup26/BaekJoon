#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int Arr[5];
    int n=0;
    for(int i=0;i<5;i++){
        int tmp;
        cin>>tmp;
        Arr[i] = tmp;
    }
    sort(Arr,Arr+5);
    for(int i=0;i<5;i++){
        n+=Arr[i];
    }
    n = n/5;
    cout<<n<<"\n"<<Arr[5/2];
    return 0;
}