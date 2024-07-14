#include <iostream>

using namespace std;

int A_ = 'A'-10;

int main() {
    string N;
    int B;
    cin>>N>>B;
    
    int sum = 0;
    int len = N.length()-1;
    
    //앞자리수부터 계산
    for(int i = 0;i<=len;i++){
       //자리수에 대응하는 가중치값을 구함
        int weight = 1;
        for(int j = 0; j<len-i;j++){
            weight *= B;
        }
        //해당 자리수 값을 sum에 합산
        if(N[i]>='A' && N[i]<='Z'){ // A~Z사이 값이면 10~35로 변경해줌
            sum += weight*(N[i]-A_);
            //cout<<i<<":"<<weight<<" "<<(N[i]-A_)<<"\n";
        }else{
            sum += weight*(N[i]-'0');
            //cout<<i<<":"<<weight<<" "<<(N[i]-'0')<<"\n";
        }
    }
    cout<<sum;
    return 0;
}