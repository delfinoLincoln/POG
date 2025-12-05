#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int i, vogal_a = 0, vogal_e = 0, vogal_i = 0,vogal_o = 0,vogal_u = 0, space = 0;

    printf("Digite uma frase/palavra(ate 100 caracteres): ");
    gets(str);
    for( i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'A')
        {
            vogal_a++;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            vogal_e++;  
        }
        else if (str[i] == 'i' || str[i] == 'I')
        {
            vogal_i++;  
        }
        else if (str[i] == 'o' || str[i] == 'O')
        {
            vogal_o++;  
        }
        else if (str[i] == 'u' || str[i] == 'U')
        {
            vogal_u++;  
        }
        else if (str[i] == ' ')
        {
            space++;
        }
    }
    printf("Quantidade de vogais A: %d\n",vogal_a);
    printf("Quantidade de vogais E: %d\n",vogal_e);
    printf("Quantidade de vogais I: %d\n",vogal_i);
    printf("Quantidade de vogais O: %d\n",vogal_o);
    printf("Quantidade de vogais U: %d\n",vogal_u);
    printf("Quantidade de espacos: %d\n",space);

    return 0;
}