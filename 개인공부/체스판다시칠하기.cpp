#include <iostream>

using namespace std;

int map[50][50];

int check_paint(int start_x,int start_y){
    int result = 0;
    for(int x = start_x;x<8;x++){
        for(int y = start_y;y<8;y++){
            if(map[x][y] !== ""){
                result++;
            }
        }
    }
    return result;
}

int main(){
    return 0;
}