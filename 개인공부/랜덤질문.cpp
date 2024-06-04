#include <iostream>
#include <random>

using namespace std;

string q[]={
    "1분 자기소개","개발자가 되고 싶은 이유","지원동기","성격의 장단점",
    "해보고 싶은 프로젝트", "왜 꼭 사피여야 하는가","10년뒤엔 어떤 모습일지",
    "리더인가 팔로워인가","실패 경험이나 희생 경험","졸업 후 어떻게 보냈는지",
    "갈등 해결 방법", "마지막 한마디",
};

int get_random_i(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0,n);

    return dis(gen);
}

int main(){
    cout<<q[get_random_i(12)];
    return 0;
}