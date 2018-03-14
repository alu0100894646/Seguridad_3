#include<iostream>
#include<string>
#include<climits>
#include "vernam.h"

using namespace std;

int main (void)
{
    srand(time(NULL));
    vernam_t prueba;
    string mensaje;//("01000001010000010100000101000001");
    string random; //0 = Random por defecto
    
    cout << "Practica 1. Seguridad - Cifrado Vernam" <<endl;
    cout << "Introduzca un mensaje para cifrar: " << endl;
    getline(cin,mensaje);
    //cin >> mensaje;
    
    cout<< "¿Quiere generar la clave aleatoriamente? s = Sí , n = No" << endl;
    getline(cin,random);
    
    string resultado;
    //cin.ignore(INT_MAX);

    if(random == "s")
    {
        resultado = prueba.conversor_clave(mensaje,random);
    }
    else if (random == "n"){
        string clave;
        cout << "Introduzca la clave que quiere utilizar: " << endl;
        //cin >> clave;
        getline(cin,clave);
        //Pongo la clave elegida en el objeto
        prueba.set_clave_(clave);
    }
    //out << "El mensaje cifrado es: " << endl;
    
    prueba.descifrar_mensaje(resultado);
    
    cout << "Volvemos a aplicar el XOR para ver si esta bien el mensaje cifrado: "<< endl;
    resultado = prueba.xor_(resultado);
    
    prueba.descifrar_mensaje(resultado);
    
    //{ //resultado = prueba.conversor_clave(mensaje);
    // prueba.set_clave_("AAAA");
    // //cout << "El mensaje cifrado es: " << endl;
    
    // // prueba.descifrar_mensaje(resultado);
    
    // // cout << "Volvemos a aplicar el XOR para ver si esta bien el mensaje cifrado: "<< endl;
    // // resultado = prueba.xor_(resultado);
    
    // // prueba.descifrar_mensaje(resultado);}
    
    //{cout << "soy un aviso" << endl;
    // prueba.generar_clave(3);
    // cout << prueba.xor_("010100110100111101001100") << endl;
    //prueba.conversor_clave("SOL");
    //prueba.conversor_clave("SOL");}
}