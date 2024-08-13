#include <iostream>

using namespace std;

int main(){
    int N,i,last;
    cin>>N;
    i=0;
    last = 1;
    while(true){
        if(N <= last){
            break;
        }
        i++;
        last+= i*6;
    }
    cout<<i+1;
    return 0;
}