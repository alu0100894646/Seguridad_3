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
    
    mult_snow_t prueba;
    
    int p_byte, s_byte;
    
    cout << "Introduce el primer byte" << endl;
    cin >> hex >> p_byte;
    cout << "Introduce el segundo byte" << endl;
    cin >> hex >> s_byte;
    
    // cout << "p" << p_byte << "s" << s_byte << endl;
    
    prueba.mult_algorithm(p_byte,s_byte);
    
}