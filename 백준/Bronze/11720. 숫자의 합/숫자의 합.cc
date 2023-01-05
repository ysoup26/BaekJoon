#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int N,sum=0;
    cin>>N;
	char n_list[N];
    cin>>n_list;
    
    for(int i=0;i<N;i++)
    {
        sum+=n_list[i]-'0';
    }
    cout<<sum;
    return 0;
}