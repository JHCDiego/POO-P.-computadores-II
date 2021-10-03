#include <iostream>
using namespace std;
class numero{
private:
    int num;
public:
    //Constructor
    numero(int n){
    num = n;
    };
    //Método para comprobar si un nunero es par o no.
    bool numero_par(){
        return (num%2==0);
    }
    unsigned int factorial(){
        long long f = 1;
            if(num<0){
                cout<<"El factorial de un entero negativo no existe.";
            }
            else if(num>=34){
                cout<<"El factorial es muy grande para mostrarse en pantalla.";
            }
            else{
                for(int i=1;i<=num;i++){
                f*=i;
            }
        }
        return f;
    }

    int digitos(){
        int contador = 0;
        while(num!=0){
            contador++;
            num/=10;
        }
        return contador;
    }

};

int main(){
    //Variables
    int n; string x;
    //Acciones
    cout<<"Ingrese un numero entero: "; cin>>n;
    numero nr(n);
    x = (nr.numero_par()==true)?"su numero es par":"su numero no es par";
    cout<<x<<endl;
    cout<<n<<"!: "<<nr.factorial()<<endl;
    cout<<n<<" tiene "<<nr.digitos()<<" digitos";


    return 0;
}


