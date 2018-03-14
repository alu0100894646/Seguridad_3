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