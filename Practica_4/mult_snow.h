#include <iostream>
#include <string>

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
    mode_(false)
    {}
    
    ~mult_snow_t(){}
    
    void mult_algorithm(int first_byte, int second_byte)
    {
        string f_byte_string = to_binary(first_byte);
        string s_byte_string = to_binary(second_byte);
        
        int num_of_ones;
        
        for(int i = 0; i < s_byte_string.size(); i++)
            if(s_byte_string[i] == '0')
                num_of_ones++;
                
        
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