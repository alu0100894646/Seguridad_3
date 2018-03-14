#include <vector>
#include <iostream>

static const int alfabeto_size(26);

using namespace std;

class vigenere_t
{
    private:
    
        vector<char> plaintext_;
        string clave_;
        
    public:
    
        vigenere_t(void)
        {
            //Rellenamos el vector @plaintext_ que contiene los 26 caracteres del alfabeto
            char initialazer = 'A';
            
            for(int i = 0; i < alfabeto_size; i++)
            {
                plaintext_.push_back(initialazer);
                initialazer++;
            }
            // for(int i = 0; i < plaintext_.size();i++)
            //     cout << plaintext_[i] << endl;
        }
        
        ~vigenere_t()
        {}
        
        string cifrar_mensaje(string mensaje)
        {
            string resultado;
            int iterador_clave = 0;
            
            for(int i = 0; i < mensaje.size(); i++)
            {
                //cout <<"M: " <<mensaje[i] << " C: " << clave_[iterador_clave] << endl;
                int char_value_mensaje = get_char_value(mensaje[i]);
                int char_value_clave = get_char_value(clave_[iterador_clave]);
                
                //Aqui viene la codificación Xi(value_mensaje[i]) + Ki(value_clave[i]) mod 26
                int char_operator = char_value_mensaje+char_value_clave;
                char_operator%=alfabeto_size;
                //cout << char_operator << endl;
                //cout << plaintext_[char_operator] << endl;
                resultado.push_back(plaintext_[char_operator]);
                
                iterador_clave++;
                
                if(!(iterador_clave < clave_.size()))
                    iterador_clave = 0;
                
                
                    
            }
            return resultado;
        }
        
        string descifrar_mensaje(string mensaje)
        {
            string resultado;
            int iterador_clave = 0;
            
            for(int i = 0; i < mensaje.size(); i++)
            {
                int char_value_mensaje = get_char_value(mensaje[i]);
                int char_value_clave = get_char_value(clave_[iterador_clave]);
                
                int char_operator = char_value_mensaje - char_value_clave;
                
                if(char_operator < 0)
                    char_operator+=alfabeto_size;
                    
                //Aplicamos el modulo
                char_operator%=alfabeto_size;
                
                resultado.push_back(plaintext_[char_operator]);
                
                iterador_clave++;
                if(!(iterador_clave < clave_.size()))
                    iterador_clave = 0;
            }
            
            return resultado;
        }
        
        int get_char_value(char value)
        {
            int i;
            for(i = 0; i < plaintext_.size(); i++)
                if(value==plaintext_[i])
                    return i;

            // cout << value << " == " << plaintext_[i] << "->";
            // cout << "Char not allowed" << endl;
            // return -1;
        }
        
        void set_clave_(string clave)
        {
            clave_ =  clave;
        }
        
        string get_clave_(void)
        {
            return clave_;
        }
};