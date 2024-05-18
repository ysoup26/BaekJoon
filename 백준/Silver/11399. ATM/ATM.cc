#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N); //적은 시간을 가진 사람들이 빨리 하고 나가니까 이득
    int sum=arr[0];
    int cost = arr[0]; //cost: 이전 사람들의 시간합을 저장하는 변수, sum과는 다름
    for(int i=1;i<N;i++){
        sum+=arr[i]+cost;
        cost+=arr[i];
    }
    cout<<sum;
    return 0;
}