#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //범위를 체크하는게 중요했던 문제
    long long S,sum;
    int N;
    cin>>S;
    sum = 0;
    if(S == 1 ){
        cout<<1;
        return 0;
    }
    for(N = 1; ;N++){
        sum+=N;
        if(S < sum){
            break;
        }
        
    }     
    cout<<N-1;
    return 0;
}