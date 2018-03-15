#include<iostream>
#include<iomanip>
#include<string>

#include "mult_snow.h"

using namespace std;

string desplazar(string desp)
{
        desp.erase(0,1);
        desp.push_back('0');
        return desp;
}

int main (void)
{
    
    string prueba;
    prueba = "Hola";
    
    cout << desplazar(prueba) << endl;
    
}