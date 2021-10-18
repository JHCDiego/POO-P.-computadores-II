#include <iostream>
using namespace std;
class operaciones{
    public:
        double numero, suma, promedio, contador;
        operaciones(){
            contador = 0;
            numero = 0;
            suma = 0;
            promedio = 0;
        }
        void suma_promedio(){
            char e;
            contador = 0;
              do{
                cout<<"Ingresa un numero: ";
                cin>>numero;
                suma += numero;
                contador++;
                cout << "Ingresa 's' para continar: "; cin>>e;
                }
            while (e=='s');
            promedio = suma/contador;
            cout<<"La suma es: "<<suma<<endl;
            cout<<"El promedio es: "<<promedio;
        }
};
int main() {
    operaciones num1;
    num1.suma_promedio();
    return 0;
}