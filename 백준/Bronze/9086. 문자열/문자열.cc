#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        int last = s.length()-1;
        cout<<s[0]<<s[last]<<"\n";
    }
    return 0;
}