include <stdio.h>
 
int main() {
    int c=1;
    switch(3){
        case 1:c+=3;
        case 2:c++;
        case 3:c=0;
        case 4:c+=3;
        case 5:c-=10;
        default : c--;
        
    }
    printf("%d",c);
}
//다음출력은: 
/*
    switch의 매개변수가 3이기 때문에 case3부터 시작
    3: c => 0
    4: c => 3
    5: c = -7
    6: c = -8

    "-8"
*/