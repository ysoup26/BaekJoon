#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];
int data[100000];
int N;

bool binary_search(int f,int start,int end){
    int m;
    if(start>end)
        return false;
    m = (start+end)/2;
    if(A[m] == f)
        return true;
    else if(A[m] > f)
        return binary_search(f,start,m-1);
    else
        return binary_search(f,m+1,end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A,A+N);
    cin>>M;
    for(int i=0;i<M;i++){
        int f;
        cin>>f;
        cout<<binary_search(f,0,N-1)<<"\n";
    }
    return 0;
}