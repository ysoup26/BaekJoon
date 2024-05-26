#include <iostream>

using namespace std;

int d[11];

void dynamic(int n){
    for(int i=4;i<=n;i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
}

int main(){
    int t,n;
    cin>>t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int test_case=0;test_case<t;test_case++){
        cin>>n;
        dynamic(n);
        cout<<d[n]<<"\n";
    }
    
    return 0;
}