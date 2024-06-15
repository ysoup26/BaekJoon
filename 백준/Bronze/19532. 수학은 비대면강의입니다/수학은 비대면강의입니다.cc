#include <iostream>

using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int result_x, result_y;
    bool Is_break = false;
    for(int x=-999; x<=999;x++){
        if(!Is_break)
        for(int y=-999; y<=999;y++){
            int m1 = (a*x+b*y) == c; 
            int m2 = (d*x+e*y) == f; 
            if( m1 && m2 ){
                result_x = x;
                result_y = y;
                Is_break = true;
                break;
            }
        }
    }
    cout<<result_x <<" "<<result_y;
    return 0;
}