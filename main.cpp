#include <iostream>
#include <fstream>
using namespace std;

const int idprod{5};
void listado(float pesos[][idprod], int idclien, string clientes[], string tipoprod[])
{
    cout << "\nListado :" << endl;
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (pesos[i][j] > 13000) {
                cout << clientes[i] << " - " << tipoprod[j] <<" - " <<pesos[i][j]<< endl;
            }
        }
    }
    cout << endl;
}
void mayprod(float pesos[][idprod], int idclien, float dist[][idprod], string tipoprod[])
{
    int may[idclien][idprod]{};
    int mayi=0;
    int mayj=0;
    cout << "\Mayor cantidad tipos de productos :" << endl;
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (pesos[i][j] > 13000) {
                may[i][j]++;
            }
        }
    }
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (may[i][j] > may[i][j]-1) {
                mayi=i;
                mayj=j;
            }
        }
    }
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (may[i][j] >0) {
                cout << tipoprod[j] <<" - " <<dist[mayi][j]<< endl;
            }
        }
    }
    cout << endl;
}
void entregastot(float pesos[][idprod], int idclien, float dist[][idprod], int entregas[][idprod])
{
    int may[idclien][idprod]{};
    int mayi=0;
    int mayj=0;
    float distmax;
    int entregastot;
    cout << "\Cantidad de Entregas del producto con mayor cantidad de kilometros recorridos :" << endl;
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (pesos[i][j] > 13000) {
                may[i][j]++;
            }
        }
    }
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (may[i][j] > may[i][j]-1) {
                mayi=i;
                mayj=j;
            }
        }
    }
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (may[i][j] >0) {
                    if(dist[mayi][j]>distmax)
                    {
                        distmax+=dist[mayi][j];
                        mayj=j;
                    }
            }
        }

    }
    for (int i = 1; i < idclien - 1; ++i) {
        for (int j = 1; j < idprod - 1; ++j) {
            if (j ==mayj) {
                entregastot++;
            }
        }

    }
    cout << entregastot<< endl;
    cout << endl;
}

int main()
{
    const int idclien{8};
    string clientes[idclien] {"Bat", "Bi","Hiru","Lau","Bost","Sei","Zapsi","Zortsi"};
    string tipoprod[idprod] {"Alimenticios", "Electronicos","Metalicos","Textiles","Quimicos"};

    int iclie, itprod;
    float peso, dist;

    float mdist[idclien][idprod] {};
    float pesos[idclien][idprod] {};
    int entregas[idclien][idprod]{};
    float promedios[idclien];

    ifstream datos;
    datos.open("Datos.txt");
    if (!datos) {
        cout << "No se puedo abrir el archivo de datos" << endl;
        return 1;
    }
    while (datos >> iclie >> itprod >> peso >> dist) {
        mdist[iclie][itprod] += dist;
        pesos[iclie][itprod] += peso;
        entregas[iclie][itprod]++;
    }
    datos.close();
    listado(pesos, idclien, clientes, tipoprod);
    mayprod(pesos, idclien, mdist, tipoprod);
    entregastot(pesos, idclien, mdist, entregas);
    return 0;
}
