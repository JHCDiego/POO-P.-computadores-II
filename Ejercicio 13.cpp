#include <iostream>
using namespace std;
class Racional{
private:
        int numerador, denominador;
        //Constructor por defecto
public:
        Racional(){
            numerador = 0;
            denominador = 0;
        }
        //Constructor parametrizado
        Racional(int n, int d){
        numerador = n;
        denominador = d;
        }
        //Metodos accesores
        //getters
         int getNumerador(){return numerador;}
        int getDenominador(){return denominador;}
        //setters
        void setNumerador(int a){numerador = a;}
        void setDenominador(int b){denominador = b;}

        void suma(Racional r){
        double numerador_1 = numerador*r.getDenominador()+denominador*r.getNumerador();
        double denominador_1 = denominador*r.getDenominador();
        double fraccion = numerador_1/denominador_1;
        cout<<"Suma: "<<fraccion<<endl;
        }

        void resta(Racional r){
        double numerador_1 = numerador*r.getDenominador()-denominador*r.getNumerador();
        double denominador_1 = denominador*r.getDenominador();
        double fraccion = numerador_1/denominador_1;
        cout<<"Resta: "<<fraccion<<endl;
        }

        void multiplicacion(Racional r){
        double numerador_1 = numerador*r.getNumerador();
        double denominador_1 = denominador*r.getDenominador();
        double fraccion = numerador_1/denominador_1;
        cout<<"Multiplicacion: "<<fraccion<<endl;
        }

         void division(Racional r){
        double numerador_1 = numerador*r.getDenominador();
        double denominador_1 = denominador*r.getNumerador();
        double fraccion = numerador_1/denominador_1;
        cout<<"Division: "<<fraccion;
        }
};

int main(){
Racional n1(1,2);
Racional n2(1,4);
n1.suma(n2);
n1.resta(n2);
n1.multiplicacion(n2);
n1.division(n2);
return 0;
}
