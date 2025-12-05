#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

void digitarStr(char *str);
void apagarStr(int len);


#define TEMP 120

int main(){
    system("cls");
    digitarStr("Hello, world!");
    apagarStr(strlen("Hello, world!"));

    return 0;
}

void digitarStr(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        Sleep(TEMP);
    }
}

void apagarStr(int len){
    for(int i = 0; i < len; i++){
        printf("\b \b");
        Sleep(TEMP);
    }
}