#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

void digitarStr(char *str);
void apagarStr(int len);


#define TEMP 80

int main()
{
    system("cls");
    
    //karnival

    digitarStr("O fantasma do Smoke John me falou\n");
    digitarStr("Que o coral dos mortos cantaria: Ari, ari, oh!\n");
    digitarStr("Pobre Mary, Mary Pop, a coitada se assustou\n");
    digitarStr("Ta em coma na enfermaria que Saint James a deixou\n");

    digitarStr("Quero seis bons atiradores!\n");
    digitarStr("a moca que tiver melhor voz\n");
    digitarStr ("enterrem com todos os meus colares\n");
    digitarStr("rapazes da orquestra saberem que o mestre os deixou\n");

    digitarStr("Quem vier a minha casa sempre vai ter o que comer");
    digitarStr("cerveja, servida na mesa\n");
    digitarStr("pra todos os meus servos fieis\n");
    digitarStr("Seja no ceu ou no inferno, cantara Cab Calloway\n");

    //alec'

    digitarStr("Tao cruel igual viver nesse mundo de injurias\n");
    digitarStr("Busquei vida onde nao tinha, encontrei furia\n");
    digitarStr("Entre clubes de jazz, bares de blues\n");
    digitarStr("Magia nos pes e um som que seduz\n");

    //alec'

    digitarStr("Eu sei bem o vies de quem anda sem luz\n");
    digitarStr("Eles procuram no jazz algo que nos conduz\n");
    digitarStr("Do azul do ceu e do mar, te contando historias pra viajar\n");
    digitarStr("Eis que a morte chamou pra dançar com o diabo e o azul\n");
    digitarStr("Tao profundo do mar\n");
    digitarStr("E eu vivo lastimas, me dizem calma, mas eu sempre\n");
    digitarStr("Viro as paginas e lagrimas\n");
    digitarStr("Isso porque eu vivo em satiras, me acostumei a conviver com\n");
    digitarStr("Coisas acidas e basicas\n");

    //karnival

    digitarStr("Ari Ari Oh!\n");

    return 0;
}


void digitarStr(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        Sleep(TEMP);
    }
}