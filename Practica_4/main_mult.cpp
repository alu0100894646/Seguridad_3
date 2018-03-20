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
    
    
    
    int p_byte, s_byte;
    int opcion;
    
    cout << "Introduce el primer byte" << endl;
    cin >> hex >> p_byte;
    cout << "Introduce el segundo byte" << endl;
    cin >> hex >> s_byte;
    cout << "Introduce el byte del algoritmo " << endl;
    cout << "0 = AES, 1 = Snow, 2 = AF" << endl;
    cin >>opcion;
    
    mult_snow_t prueba(opcion);
    
    // cout << "p" << p_byte << "s" << s_byte << endl;
    
    prueba.mult_algorithm(p_byte,s_byte);
    
}