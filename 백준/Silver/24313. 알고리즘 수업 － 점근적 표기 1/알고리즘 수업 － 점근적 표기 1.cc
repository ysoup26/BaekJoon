#include <iostream>

using namespace std;

int main(){
    int a_1, a_0,c,n_0;
    cin>>a_1>>a_0>>c>>n_0;
    bool IsTrue = true;
    for(int i=n_0;i<=100;i++){
        int fn = a_1 * i + a_0;
        int gn = c*i;
        //cout<<fn<<" "<<gn<<" \n";
        if( fn > gn){
            IsTrue = false;
            break;
        }
    }
    cout<<IsTrue;
    return 0;
}