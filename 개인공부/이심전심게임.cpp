/*
이심전심: 두 사람이 같은 단어를 고르는 게임

동작: 
1) 두 키워드 제시
2) 유저와 봇이 키워드를 하나씩 선택
3) 두 키워드가 동일하면 정답

이때 봇은 키워드 조합별 확률을 가지고 키워드를 선택함
*/

#include <iostream>
#include <random>

using namespace std;

string keyword[6] ={"으쓱","미소","윙크","실망","놀람","화남"};

float check[4] ={0.5,0.77,0.45,0.5 };

string get_random_keywords(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0,5);
    return keyword[dis(gen)];
}

string get_keyword_probability(string s1,string s2){
    int i = 0;
    return s1;
};

int main(){
    //1) 두 키워드 제시(랜덤)
    string keyword1,keyword2;
    keyword1 = get_random_keywords();
    keyword2 = get_random_keywords();
    cout<<"<---키워드 하나를 선택하세요: "<<keyword1<<" or "<<keyword2<<"--->\n";
    string user,bot;
    //2) 유저와 봇이 키워드를 하나씩 선택
    cin>>user;
    bot = get_keyword_probability(keyword1,keyword2);
    cout<<"유저: "<<user<<" / 봇: "<<bot<<"\n>>";
    //3) 두 키워드가 동일하면 정답
    if(user == bot)
        cout<<"정답";
    else
        cout<<"오답";
    return 0;
}