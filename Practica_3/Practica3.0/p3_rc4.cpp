#include<iostream>

#include "rc4.h"

using namespace std;

int main (void){
    
    rc4_t prueba;
    int tam_mensaje = 0;
    int tam_semilla = 0;
    int aux;
    vector<int> mensaje;// = {1,34};
    vector<int> semilla;// = {2,5};
    string resultado;
    
    cout << "Introduzca el tamaño del mensaje que quiere cifrar: " << endl;
    cin >> tam_mensaje;
    cout << "Introduzca el mensaje que quiere cifrar: " << endl;
    for(int i = 0; i < tam_mensaje;i++)
    {
        cin >> aux;
        mensaje.push_back(aux);
    }
    cout << "Introduzca el tamaño de la semilla que quiere utilizar: " << endl;
    cin >> tam_semilla;
    cout << "Introduzca la semilla que quiere utilizar : " << endl;
    for(int i = 0; i < tam_semilla;i++)
    {
        cin >> aux;
        semilla.push_back(aux);
    }
    resultado =prueba.codificar_mensaje(mensaje,semilla);
    //cout << resultado << endl;
    
    prueba.descifrar_mensaje(resultado);
}