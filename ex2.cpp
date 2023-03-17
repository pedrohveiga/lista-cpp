#include <iostream>
#include <iomanip>
using namespace std;

int Aux1 = 0;

const int matrizY = 25;
const int matrizX = 3;

int baralhoOrg[matrizX][matrizY];
int identificadorRandom[104];
int maoJogadores[3][10];

const int maxNaipe = 4;
const int maxCartas = 13;
const int maxBaralho = 2;

int naipe = 0;
int carta = 0;
int baralho = 1;


// CRIAÇÃO DO BARALHO PRINCIPAL COM 2 BARALHOS DE 52 CARTAS
void madeDeck()
{
    for (int i = 1; i <= maxNaipe; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int k = 10; k <= maxCartas * 10; k += 10)
            {
                baralhoOrg[naipe][carta + Aux1] = ((naipe + 1) * 1000) + k + baralho;
                carta = k / 10;
            }
            if (baralho == 1)
            {
                baralho = 2;
                Aux1 = 13;
                
            }
        }
        naipe += 1;
        baralho = 1;
        Aux1 = 0;
        
    }
}

// EXIBIÇÃO DO BARALHO PRINCIPAL
void exibirBaralhoOrg()
{
    for (int i = 0; i < maxNaipe; i++)
    {
        for (int j = 0; j < maxCartas * maxBaralho; j++)
        {
            cout << baralhoOrg[i][j] << " ";
        }
        cout << endl;
        cout << endl;
    }
}

//GERADOR DE NÚMEROS ALEATÓRIOS E ALOCAÇÃO NA MATRIZ DOS JOGADORES
void random()
{
    int valorRandom = 0;
    int coluna = 0;
    int linha = 0;
    srand(time(0));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            valorRandom = rand() % 105;

            if (identificadorRandom[valorRandom] == 0)
            {
                identificadorRandom[valorRandom] = 1;

                if (valorRandom >= 0 && valorRandom < 26)
                {
                    coluna = 0;
                    linha = valorRandom;
                }
                else if (valorRandom >= 26 && valorRandom < 52)
                {
                    coluna = 1;
                    linha = valorRandom - 26;
                }
                else if (valorRandom >= 52 && valorRandom < 78)
                {
                    coluna = 2;
                    linha = valorRandom - 52;
                }
                else if (valorRandom >= 78 && valorRandom < 104)
                {
                    coluna = 3;
                    linha = valorRandom - 78;
                }

                maoJogadores[i][j] = baralhoOrg[coluna][linha];
                
            
                /* 
                VERIFICAÇÃO DO VALOR ALEATÓRIO
                */

                // cout << valorRandom << "[" << coluna << "]" << "[" << linha << "]" << endl;

            } else {
                j--;
            }
        }
    }
}

// EXIBIÇÃO DAS MÃOS DOS JOGADORES
void exibirMaoJogadores()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << maoJogadores[i][j] << " ";

        }
        cout << endl;
        cout << endl;
    }
}

int main()
{
    madeDeck();
    cout << "O baralho organizado: " << endl;
    cout << endl;
    cout << endl;
    exibirBaralhoOrg();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    random();
    cout << "Winner Winner, Chicken Dinner!!!! " << endl;
    cout << endl;
    cout << endl;
    exibirMaoJogadores();
    return 0;
}