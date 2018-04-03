#include<iostream>
#include<string>
#include<vector>
#include<cmath>


using namespace std;

class gen_e3_t{
  
  private:
    
    string lfsr1_,lfsr2_,lfsr3_,lfsr4_;
    string r1_,r2_;
  
  public:
  
  gen_e3_t()
  {
    lfsr1_ = "0111111111111111111111111";
    lfsr2_ = "1111111111111111111111111111111";
    lfsr3_ = "111111111111111111111111111111111";
    lfsr4_ = "010101010101010101010101010101010101010";
    r1_ = "01";
  }
  
  ~gen_e3_t(){}
  
  void codificacion_bt(int n_b_salida)
  {
    //Inicializamos un contador para cada lfsr que empieze de derecha a izquierda.
    
    string resultado;
    
    for(int i = 0; i < n_b_salida;i++)
    {
      int sum1 = sumar_lfsr(lfsr1_.back(),lfsr2_.back(),lfsr3_.back(),lfsr4_.back());
      
      //Tengo la salida de r1 y r2 despues de los T1 y T2 ahora queda hacer los Xor y la division
      r2_ =  r1_;
      swap(r1_[0],r1_[1]);
      resultado.insert(0,calc_resultado(lfsr1_.back(),lfsr2_.back(),lfsr3_.back(),lfsr4_.back(),r1_[1]));
      t2();
      
      int sum2 = to_decimal(r1_);
      int sum3 = sum1+sum2;
      sum3 /=2;
      string sum3_s = to_binary(sum3);
      
      string p_xor = xor_(r2_,sum3_s);
      string s_xor = xor_(r1_,p_xor);
      r1_ = s_xor;
      lfsr();
    }
    
    cout << "La secuencia de salida es: " << resultado << endl;
  }
  
  void lfsr(void)
  {
    int lfsr1 = sumar_lfsr(lfsr1_[24],lfsr1_[19],lfsr1_[11],lfsr1_[7]);
    int lfsr2 = sumar_lfsr(lfsr2_[30],lfsr2_[23],lfsr2_[15],lfsr2_[11]);
    int lfsr3 = sumar_lfsr(lfsr3_[32],lfsr3_[27],lfsr3_[23],lfsr3_[3]);
    int lfsr4 = sumar_lfsr(lfsr4_[38],lfsr4_[35],lfsr4_[28],lfsr4_[4]);
    
    lfsr1 %=2;
    lfsr2 %=2;
    lfsr3 %=2;
    lfsr4 %=2;
    
    lfsr1_.erase(23);
    lfsr2_.erase(30);
    lfsr3_.erase(32);
    lfsr4_.erase(38);
    
    if(lfsr1 == 0)
      lfsr1_.insert(0,"0");
    else
      lfsr1_.insert(0,"1");

    if(lfsr2 == 0)
      lfsr2_.insert(0,"0");
    else
      lfsr2_.insert(0,"1");
      
    if(lfsr3 == 0)
      lfsr3_.insert(0,"0");
    else
      lfsr3_.insert(0,"1");
      
    if(lfsr4 == 0)
      lfsr4_.insert(0,"0");
    else
      lfsr4_.insert(0,"1");
    
  }
  
  string calc_resultado(char l1,char l2,char l3,char l4,char l5)
  {
    int r = 0;
    if(l1=='1')
      r++;
    if(l2=='1')
      r++;
    if(l3=='1')
      r++;
    if(l4=='1')
      r++;
    if(l5=='1')
      r++;
      
    if(r%2)
      return "1";
    else 
      return "0";
  }
  
  int to_decimal(string num)
  {
    int tnum = num.size();
    int exponente = 0;
    int resultado;
    
    for(int i = tnum-1;i >= 0; i--)
    {
      if(num[i] == '1')
        resultado+= pow(2,exponente);
      
      //cout << resultado << endl;
      exponente++;
    }
    return resultado;
  }
  
  void t2(void)
  {
    int r2_1 = 0;
    
    if(r2_[0] == 1)
      r2_1 = 1;
    
    swap(r2_[0],r2_[1]);
    r2_[1] = sumar_t2(r2_[0],r2_[1]);
    
  }
  
  char sumar_t2(char l1, char l2)
  {
    int l1a = 0;
    int l2a = 0;
    char r;
    if(l1 == '1')
      l1a = 1;
    if(l2 == '1')
      l2a = 1;
    
    if((l1a+l2a)/2)
      return '1';
    else
      return '0';
  }
  
  int sumar_lfsr(char l1,char l2, char l3, char l4)
  {
    int l1a = 0;
    int l2a = 0;
    int l3a = 0;
    int l4a = 0;
    
    if(l1 == '1')
      l1a = 1;
    if(l2 == '1')
      l2a = 1;
    if(l3 == '1')
      l3a = 1;
    if(l4 == '1')
      l4a = 1;
      
    return (l1a+l2a+l3a+l4a);
      
  }
  
  string to_binary(int n)
  {
        string r;
        while(n!=0)
        {
            r=(n%2 == 0 ? "0" : "1")+r;
            n/=2;
            
        }
        // while(r.size() < 8)
        // {
        //     r= "0"+r;
        // }
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
  
  //En principio no hace falta 
  // void lfsr(int tam, vector<int> polinomio,string registro)
  // {
    
  // }
};