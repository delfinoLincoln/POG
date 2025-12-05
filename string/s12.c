#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int vogal = 0, i;

    printf("Digite uma frase: ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' ||str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' ||str[i] == 'O' || str[i] == 'u' || str[i] == 'U' )
        {
            vogal++;
        }  
    }
    printf("Essa string possui %d vogais!\n",vogal);

    return 0;
}