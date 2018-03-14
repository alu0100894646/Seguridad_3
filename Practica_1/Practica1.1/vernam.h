#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <sstream>

using namespace std;

class vernam_t{
    
    private:
    
    string clave_;
    string resultado_;
    
    public:
    
    vernam_t(void):
    clave_(),
    resultado_()
    {}
    
    ~vernam_t(){}
    
    //Metodo para cifrar un mensaje 
    string conversor_clave(string mensaje,string random)
    {
        int t_mensaje = mensaje.size();
        vector<int> codigo_ascii(t_mensaje);
        
        //Genero la clave aleatoria
        if(random == "s")
            generar_clave_ascii(t_mensaje);
        
        //Pasamos el mensaje de Ascii a decimal
        for(int i = 0; i < t_mensaje;i++)
        {
            codigo_ascii[i]=mensaje[i];
        }
        //ya tengo el mensaje pasado a decimal en codigo_ascii 
        //ahora toca pasarlo a binario cada elemnto de codigo_ascii
        
        string resultado;
        
        for(int i = 0; i < t_mensaje;i++)
        {
            //cout << to_binary(codigo_ascii[i]) << endl;
            resultado = resultado+to_binary(codigo_ascii[i]);
        }
        
        cout << "El mensaje original en binario es:   " << resultado << endl;
        //resultado tiene todo el mensaje codificado
        //cout << resultado << endl;
        
        set_resultado(xor_(resultado));
        // cout << "he terminado el xor"<< endl;
        // cout << resultado_ << endl;
        cout << "El mensaje cifrado es: " << resultado_ << endl;
        //cout << "La clave utilizada es: " << clave_;
        return resultado_;
    }
    
    //Recibe un mensaje (string de tamaño 8x)
    string descifrar_mensaje(string mensaje)
    {
        //cout << "declarando variables" << endl;
        vector<int> codigo_ascii(mensaje.size()/8);
        //cout << "El tamaño del vector codigo_ascii es :" << codigo_ascii.size() <<endl;
        int contador_ocho = 0;
        int contador_ascii = 0;
        int aux;
        //cout << "empiezo a recorrer el bucle" << endl;
        
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
        
        char resultado_aux;
        string resultado;
        for(int i = codigo_ascii.size()-1; i >= 0 ;i--)
        {
            //cout << "El contenido de codigo_ascii es:"<< codigo_ascii[i] << endl;
            resultado_aux = codigo_ascii[i];
            //cout << resultado_aux << endl;
            resultado.push_back(resultado_aux);
            
        }
        
        cout << "El mensaje descifrado es: " << resultado << endl;
        
        
        return resultado;
    }
    
    //Esta pensado para pasar al codigo ascii extendido que ocupan 256 caracteres en un 
    //número binario de 8 bits para esta practica en concreto
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
    
    void generar_clave(int t)
    {
        //tamaño total de la clave para codificar
        t*=8;
        string aux_clave;
        for(int i = 0; i < t ; i++)
        {
            //genera un numero aleatorio de 0 a 1
            int random =  rand() % 2;
            aux_clave = (random == 0 ? "0" : "1")+aux_clave;
        }
        //cout << aux_clave << endl;
        set_clave_aleatoria(aux_clave);
        
        cout << "La clave generada aleatoriamente es: " << clave_ << endl;
    }
    
    void generar_clave_ascii(int t)
    {
        vector<int> clave_ascii(t);
        string clave_ascii_string;
        
        for(int i = 0 ; i < clave_ascii.size();i++)
        {
            clave_ascii[i] = (rand() % 96) + 32;
        }
        
        for(int i = 0; i < t;i++)
        {
            //cout << to_binary(codigo_ascii[i]) << endl;
            clave_ascii_string = clave_ascii_string+to_binary(clave_ascii[i]);
        }
        
        set_clave_aleatoria(clave_ascii_string);
        
        cout << "La clave generada en ascii es: " << clave_ascii_string << endl;
    }
    
    string xor_(string r) // debemos pasarle al xor todo el mesaje en binario.
    {
        string clave_convertida;
        
        for(int i = 0; i < r.size();i++)
        {
            if(clave_[i] == r[i])
                clave_convertida=clave_convertida+"0";
            else if (clave_[i] != '0' || r[i] != '0')
                clave_convertida=clave_convertida+"1";
            //cout << clave_convertida << endl;
        }
        return clave_convertida;
    }
    
    string get_clave_(void)
    {
        return clave_;
    }
    
    void set_clave_aleatoria(string clave)
    {
        clave_ = clave;
    }
    
    void set_clave_(string clave)
    {
        vector<int> codigo_ascii(clave.size());
        
        for(int i = 0; i < clave.size();i++)
        {
            codigo_ascii[i]=clave[i];
        }
        
        string resultado;
        
        for(int i = 0; i < codigo_ascii.size();i++)
        {
            //cout << to_binary(codigo_ascii[i]) << endl;
            resultado = resultado+to_binary(codigo_ascii[i]);
        }
        
        cout << "Resultado set_clave: " << resultado <<endl;
        clave_ = resultado;
    }
    
    string get_resultado(void)
    {
        return resultado_;
    }
    
    void set_resultado(string resultado)
    {
        resultado_ = resultado;
    }
};