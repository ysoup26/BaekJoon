#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct XY{
    int x,y;
};

int cmd_XY(XY xy1,XY xy2){
    if(xy1.y == xy2.y) //x는 같을 때 -> y비교
        return xy1.x < xy2.x;
    return xy1.y < xy2.y;
}

int main(){
    int N;
    cin>>N;
    vector<XY> arr;
    for(int i=0;i<N;i++){
        XY inputXY;
        cin>>inputXY.x>>inputXY.y;
        arr.push_back(inputXY);
    }
    sort(arr.begin(),arr.end(),cmd_XY);
    for(int i=0;i<N;i++){
        cout<<arr[i].x<<" "<<arr[i].y<<"\n";
    }
    return 0;
}