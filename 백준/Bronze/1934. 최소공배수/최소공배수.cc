#include <iostream>

using namespace std;

//최소공배수 문제를 직접 푸는 것처럼
//A와 B의 공배수를 하나씩 구함
//least common multiple
int get_lcm(int A,int B){
    int m=0;
    int A_i,B_i;
    A_i = 1;
    B_i = 1;
    while(true){
        if(A*A_i == B*B_i){
            m = A*A_i;
            break;
        }else if(A*A_i > B*B_i)
            B_i++;
        else
            A_i++;
    }
    return m;
}

int main(){
    int T;
    cin>>T;
    for(int test_case=0;test_case<T;test_case++){
        int A,B;
        cin>>A>>B;
        cout<<get_lcm(A,B)<<"\n";
    }
    return 0;
}