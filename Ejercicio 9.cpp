#include <iostream>
#include <vector>
using namespace std;
class numeros{
    public:
        std::vector<double> num;
        double suma = 0;
        double promedio;
        numeros(){
        double elemento;
        char eleccion;
           do{
            cout<<"Escriba un numero: "; cin>>elemento;
            num.push_back(elemento);
            cout<<"Desea ingresar otro numero? escriba 's' para continuar. R/."; cin>>eleccion;
           }
           while(eleccion=='s');
        }
        void sumatoria(){
        for(auto i: num){
            suma+=i;
            }
            cout<<"La sumatoria total es: "<<suma<<endl;
        }
        void pmedio(){
            promedio = suma/num.size();
        cout<<"El promedio es: "<<promedio;
        }
};

int main(){
    numeros num1;
    num1.sumatoria();
    num1.pmedio();

return 0;
}
