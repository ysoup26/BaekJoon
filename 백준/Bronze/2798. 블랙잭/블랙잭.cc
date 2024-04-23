#include <iostream>

using namespace std;

int main(){
    int N,M,result;
    cin>>N>>M;
    int card[N];
    result = 0;
    for(int i=0;i<N;i++){
        cin>>card[i];
    }
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                sum = card[i]+card[j]+card[k];
                if(i == j || j == k || i == k){
                    //cout<<"동일\n"; 
                    continue;
                }if(sum>result && sum<=M){
                    result = sum;
                    //cout<<"sum: "<<result<<">>"<<card[i]<<","<<card[j]<<","<<card[k]<<"\n";
                }
            }
        }
    }
    cout<<result;
    return 0;
}