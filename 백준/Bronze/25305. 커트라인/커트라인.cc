#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,k;
    int arr[1000];
    cin>>N>>k;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    reverse(arr,arr+N); //내림차순이라서
    cout<<arr[k-1];
    return 0;
}