#include <iostream>

using namespace std;

//소수: 1외의 약수를 가지고 있지 않는 수

bool is_prime(int n){
    if(n == 1)
        return false;
    for(int i=2;i<=n/2;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
    int N,cnt;
    cin>>N;
    cnt = 0;
    for(int i = 0;i<N;i++){
        int n;
        cin>>n;
        if(is_prime(n))
            cnt++;
    }
    cout<<cnt;
    return 0;
}