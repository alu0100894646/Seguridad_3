#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

class rc4_t
{
    private:
    
        vector<int> S_; //Contiene el vector del 0..255
        vector<int> K_; //Contiene la semilla para el cifrado
        vector<int> Cifrado_;
        //vector<int> Mensaje_;
        
    public:
    
    rc4_t(/*vector<int> mensaje*/)
    //Mensaje_(mensaje)
    {
        //Inicialización de los vectores S y K. 
        S_.resize(256);
        K_.resize(256);
        Cifrado_.resize(256);
        
    }
    
    void KSA_(vector<int> semilla)
    {
        int j = 0;
        
        for(int i = 0; i < 256; i++)
        {
            S_[i] = i;
            K_[i] = semilla[j];
            
            j++;
            if(!(j < semilla.size()))
                j = 0;
        }
        
        intercambiar_KSA();
    }
    
    void PRGA_(vector<int> mensaje)
    {
        int i = 0;
        int j = 0;
        int t = 0;
        
        for(int k = 0 ; k < mensaje.size();k++)
        {
            i = (i+1)%256;
            j = (j+S_[i])%256;
            swap(S_[i],S_[j]);
            
            t = (S_[i]+S_[j])%256;
            //cout << "S_[t]: " << S_[t] << endl;
            Cifrado_[k] = S_[t];
            //Cifrado_.push_back(S_[t]);
        }
        
        //for(int k = 0; )
    }
    
    void intercambiar_KSA(void)
    {
        int j = 0;
        
        for(int i = 0; i < 256; i++)
        {
            j = (j+S_[i] + K_[i]) % 256;
            swap(S_[i],S_[j]);
        }
    }
    
    ~rc4_t(){}
    
    string codificar_mensaje(vector<int> mensaje,vector<int> semilla)
    {
        //aplicamos los 2 algoritmos a S y nos quedamos con Cifrado el resultado
        KSA_(semilla);
        PRGA_(mensaje);
        
        for(int i = 0; i <mensaje.size();i++)
            cout << Cifrado_[i] << endl;
        //Ahora hacemos el xor entre Cifrado_ y el mensaje 
        string aux_mensaje;
        string aux_semilla;
        string resultado;
        
        for(int i = 0; i < mensaje.size();i++)
        {
            aux_mensaje = to_binary(mensaje[i]);
            aux_semilla = to_binary(Cifrado_[i]);
            
            // cout <<"mensaje"<< mensaje[i] << " __ "<<aux_mensaje << endl;
            // cout <<"semilla"<< Cifrado_[i] << "__ " <<aux_semilla << endl;
            
            
            resultado=resultado + xor_(aux_mensaje,aux_semilla);
        }
        
        
        return resultado;
    }   
    
    vector<int> descifrar_mensaje(string mensaje)
    {
        vector<int> codigo_ascii(mensaje.size()/8);
        int contador_ocho = 0;
        int contador_ascii = 0;
        int aux;
        
        for(int i = mensaje.size()-1; i >=0 ; i--)
        {
            
        //cout << "Estoy dentro del bucle con " << mensaje[i]<< endl;
            if(contador_ocho == 8)
            {
                contador_ocho = 0;
                contador_ascii++;
            }
            
        if(mensaje[i] == '0')
            aux = 0;
        else 
            aux = 1;
        //cout << "El contador ocho  es " << contador_ocho << endl;
        //cout << "2^a algo es= " << pow(2,contador_ocho)*aux << endl;
        codigo_ascii[contador_ascii]+=(pow(2,contador_ocho)*aux);
        //cout << "el contenido del codigo ascii es: " << codigo_ascii[contador_ascii] << endl;
        contador_ocho++;
        }
        
        for(int i = 0; i < codigo_ascii.size();i++)
            cout << codigo_ascii[i] << endl;
        return codigo_ascii;
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