// 求字符串长度

#include <iostream>
using namespace std;

int str_len(char *str);

int main(){
    char *str = new char[100];
    cin>>str;
    cout<<str_len(str);
    delete str;
    return 0;
}

int str_len(char *str){
    int len = 0;
    while (str[len] != NULL){
        len++;
    }
    return len;
}