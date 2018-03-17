#include <iostream>
#include <string>
#include <vector>

using namespace std;

class mult_snow_t
{
    private:
    
    string Aes_;
    string Snow_;
    bool mode_;
    
    public:
    
    mult_snow_t():
    Aes_("10101001"),
    Snow_("00011011"),
    mode_(true) // False  = AES || True Snow3g
    {}
    
    ~mult_snow_t(){}
    
    void mult_algorithm(int first_byte, int second_byte)
    {
        
        string f_byte_string = to_binary(first_byte);
        string s_byte_string = to_binary(second_byte);
        
        cout << "Pbyte en binario-> " << f_byte_string << endl << "Sbyte en binario-> " << s_byte_string << endl;
        
        if(mode_)
            cout << "Byte del algoritmo-> " << Snow_ << endl;
        else
            cout << "Byte del algoritmo-> " << Aes_ << endl;
        
        int num_of_ones = 0;
        
        for(int i = 0; i < s_byte_string.size(); i++)
            if(s_byte_string[i] == '1')
                num_of_ones++;
        
        vector<string> resultado(num_of_ones);
        int resultado_it = 0;
        
        string clave;
        
        if(mode_)
            clave = Snow_;
        else
            clave = Aes_;
        
        
        for(int i = s_byte_string.size()-1;i>=0; i--)
        {
            
            //"Simula el paso 0"
            string aux = f_byte_string;
            
            char aux_p;
            //cout << f_byte_string << endl;
            //cout << "S_byte = " << s_byte_string[i] << endl;
            
            if(s_byte_string[i]== '1')
            {
                for(int j = 0; j< 7-i;j++)
                {
                    //cout << "Iteración-> "<< j << endl;
                    
                    aux_p = aux[0];
                    aux = desplazar(aux);
                    if(aux_p=='1')
                        aux = xor_(aux,clave);
                    //cout << "Valor de J " << j << " Aux desplazado-> " << aux << endl;
                    
                }
                //cout <<"aux que va a resultado-> " << aux << endl;
                resultado[resultado_it] =  aux;
                resultado_it++;
            }
        }
        cout << "Mostrando el resultado " << endl;
        for(int i = 0; i < num_of_ones; i++)
            cout << "Vamos a sumar: "<< resultado[i] << endl;
        cout << "El resultado de la multiplicación es -> " <<sumar(resultado) << endl;
    }
    
    string sumar(vector<string> sumatorio)
    {
        string resultado;
        
        for(int j = 0; j < 8; j++)
        {
            int num_of_ones = 0;
            
            for(int i = 0; i < sumatorio.size();i++)
                if(sumatorio[i][j]=='1')
                    num_of_ones++;

            if(num_of_ones%2)
                    resultado.push_back('1');
                else 
                    resultado.push_back('0');
        }
        
        return resultado;
    }
    
    //Desplaza a la izquiera e introduce un 0 por la derecha
    
    string desplazar(string desp)
    {
        //cout << "Entra-> " << desp << endl;
        desp.erase(0,1);
        desp.push_back('0');
        //cout << "Sale-> " << desp << endl;
        return desp;
    }
    
    string rellenar(string rellena)
    {
        while(rellena.size() < 8)
            rellena = "0"+rellena;
        return rellena;
    }
    
    string to_binary(int n)
    {
        string r;
        while(n!=0)
        {
            r=(n%2 == 0 ? "0" : "1")+r;
            n/=2;
            
        }
        while(r.size() < 8)
        {
            r= "0"+r;
        }
        return r;
    }
    
    string xor_(string r,string clave) // debemos pasarle al xor todo el mesaje en binario.
    {
        //cout << r << " XOR " << clave << endl;
        string clave_convertida;
        
        for(int i = 0; i < r.size();i++)
        {
            if(clave[i] == r[i])
                clave_convertida=clave_convertida+"0";
            else if (clave[i] != '0' || r[i] != '0')
                clave_convertida=clave_convertida+"1";
            //cout << clave_convertida << endl;
        }
        return clave_convertida;
    }
};