#include <iostream>
#include <algorithm>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

int main(){
    int N;
    cin>>N;
    int list[N];
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        list[i] = tmp;
    }
    sort(list,list+N);
    list_print(list,N);
    
    return 0;
}