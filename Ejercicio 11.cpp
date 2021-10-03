#include <iostream>
#include <stdlib.h>
using namespace std;
class cifras{
private:
    int numero; int* digitos;
    int contador = 0;
public:
    cifras(int n){
    numero = n;
    }

    void contarcifras(){
        int tmp = numero;
            while(tmp!=0){
                    contador++;
                    tmp/=10;
                }
    }

   void guardar_digitos(){
            digitos = new int[contador];
            for(int i=0;i<contador;i++){
                digitos[i] = numero%10;
                numero/=10;
            }
    }
    int suma_digitos(){
        int suma = 0;
        for(int i=0;i<contador;i++){
            suma+=digitos[i];
        }
        return suma;
    }
    void multiplo(){
        int x = suma_digitos();
        for(int i=0;i<contador;i++){
        if(digitos[i]==0){
                cout<<x<<" es multiplo de "<<digitos[i]<<endl;
           }
        else{
            if(x%digitos[i]==0){
                cout<<x<<" es multiplo de "<<digitos[i]<<endl;
            }
            else{
                cout<<x<<" no es multiplo de "<<digitos[i]<<endl;
            }
        }

    }
}
};

int main(){
   int z;
    cout<<"Ingrese un numero: "; cin>>z;
    if(z>=10000 || z<=-10000){
        cout<<"Debe digitar un numero de 4 digitos o menos";
        exit(0);
    }
    else{
        cifras n(z);
        n.contarcifras();
        n.guardar_digitos();
        cout<<"La suma de los digitos de "<<z<<" es: "<<n.suma_digitos()<<endl;
        n.multiplo();
    }
    return 0;
}
