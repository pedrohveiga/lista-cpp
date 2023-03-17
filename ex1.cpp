#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

const int numFileiras = 15;
const int numPoltronas = 40;
const char *lugares[numFileiras][numPoltronas];

string conferirPoltrona;
int fileira, poltrona, fileira1_5, fileira6_10, fileira11_15, qtdeLugaresOcupados = 0;
double faturamentoTotal;
double precoFileira1_5 = 50.00;
double precoFileira6_10 = 30.00;
double precoFileira11_15 = 15.00;

void criarLugares()
{
    for (int i = 0; i < numFileiras; i++)
    {
        for (int j = 0; j < numPoltronas; j++)
        {
            lugares[i][j] = ".";
        }
    }
}

void exibirMapaLugares()
{
    for (int i = 0; i < numFileiras; i++)
    {
        for (int j = 0; j < numPoltronas; j++)
        {
            cout << lugares[i][j];
        }
        cout << endl;
    }
}

void reservar()
{

    bool aux1, aux2, aux3 = 1;

    do
    {
        while (aux2 == 1)
        {
            cout << endl;
            cout << endl;
            cout << "Digite a fileira: ";
            cin >> fileira;
            fileira -= 1;

            if (fileira < 0 || fileira >= numFileiras)
            {
                cout << "Fileira inexistente!" << endl;
                aux2 = 1;
            }
            else
            {
                aux2 = 0;
            }
        }

        while (aux3 == 1)
        {
            cout << endl;
            cout << "Digite a poltrona: ";
            cin >> poltrona;
            poltrona -= 1;

            if (poltrona < 0 || poltrona >= numPoltronas)
            {
                cout << "Poltrona inexistente!" << endl;
                aux3 = 1;
            }
            else
            {
                aux3 = 0;
            }
        }

        cout << endl;
        cout << endl;

        if (lugares[fileira][poltrona] == "#")
        {
            cout << "Lugar ocupado!";
            cout << endl;
            cout << endl;
        }
        else
        {
            lugares[fileira][poltrona] = "#";

            cout << endl;
            cout << endl;
            cout << "POLTRONA RESERVADA!" << endl;

            if (fileira <= 5)
            {
                fileira1_5 += 1;
                cout << "Seu ingresso custa: R$ " << precoFileira1_5 << endl;
            }
            else if (fileira > 5 && fileira <= 10)
            {
                fileira6_10 += 1;
                cout << "Seu ingresso custa: R$ " << precoFileira6_10 << endl;
            }
            else
            {
                fileira11_15 += 1;
                cout << "Seu ingresso custa: R$ " << precoFileira11_15 << endl;
            }

            aux1 = 0;
            return;
        }
    } while (aux3 == 1);
}

void faturamento()
{
    faturamentoTotal = (fileira1_5 * precoFileira1_5) + (fileira6_10 * precoFileira6_10) + (fileira11_15 * precoFileira11_15);
    qtdeLugaresOcupados = fileira1_5 + fileira6_10 + fileira11_15;

    cout << endl;
    cout << endl;
    cout << "Qtde de lugares ocupados: " << qtdeLugaresOcupados << endl;
    cout << fixed << setprecision(2);
    cout << "Valor da bilheteria: R$ " << faturamentoTotal << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    criarLugares();

    while (true)
    {
        cout << endl;
        cout << endl;
        cout << "0 - Finalizar" << endl;
        cout << "1 - Reservar poltrona" << endl;
        cout << "2 - Mapa dos lugares" << endl;
        cout << "3 - Faturamento" << endl;
        cout << endl;
        cout << "Digite sua escolha: ";
        int opcao;
        cin >> opcao;
        switch (opcao)
        {
        case 0:
            return 0;
        case 1:
            reservar();
            break;
        case 2:
            exibirMapaLugares();
            break;
        case 3:
            faturamento();
            break;
        default:
            cout << "Escolha inexistente!" << endl;
            break;
        }
    }
}
