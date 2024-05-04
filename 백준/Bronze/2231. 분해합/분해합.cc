#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N;
    cin>>N;
    int result = 0;
    for(int i=N/2;i<N;i++){
        int sum = i;
        int num = i;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        if(sum == N){
            result = i;
            break;
        }
    }
    cout<<result;
    return 0;
}