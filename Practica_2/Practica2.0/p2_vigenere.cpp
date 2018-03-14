#include <iostream>

#include "vigenere.h"

using namespace std;

int main (void)
{
    vigenere_t prueba;
    string mensaje,clave;
    
    cout << "Practica 2. Cifrado Vigenere. "<< endl;
    cout << "Introduzca la clave que quiere utilizar: " << endl;
    getline(cin,clave);
    prueba.set_clave_(clave);

    cout << "Introduzca el mensaje que quiere cifrar: " << endl;
    getline(cin,mensaje);
    string resultado = prueba.cifrar_mensaje(mensaje);
    cout << "El mensaje cifrado es: "<< resultado << endl;
    
    cout << "El mensaje descifrado es: " <<prueba.descifrar_mensaje(resultado) << endl;
    //cout << prueba.get_char_value('z') << endl;
}