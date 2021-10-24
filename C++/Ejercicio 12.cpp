#include <iostream>
#include <cmath>
using namespace std;

class Complejo{
private:
    double parte_real, parte_imaginaria;
public:
    double t_1, t_2, t_3, t_4, t_r, t_i;
    //Constructor por defecto
    Complejo(){
    parte_real = 0;
    parte_imaginaria = 0;
    }
    //Constructor parametrizado
    Complejo(double r, double i){
    parte_real = r;
    parte_imaginaria = i;
    }
    //metodos accesores
    //get
    double getparte_real(){return parte_real;}
    double getparte_imaginaria(){return parte_imaginaria;}
    //set
    void setparte_real(double a){
    parte_real = a;
    }
    void setparte_imaginaria(double b){
    parte_imaginaria = b;
    }
    void suma(Complejo c){
        double suma_real = parte_real+c.getparte_real();
        double suma_imaginaria = parte_imaginaria+c.getparte_imaginaria();
        cout<<"suma: "<<"("<<suma_real<<", "<<suma_imaginaria<<")"<<endl;
    }
    void resta(Complejo c){
        double resta_real = parte_real-c.getparte_real();
        double resta_imaginaria = parte_imaginaria-c.getparte_imaginaria();
        cout<<"resta: "<<"("<<resta_real<<", "<<resta_imaginaria<<")"<<endl;
    }
    void multiplicacion(Complejo c){
            t_1 = parte_real*c.getparte_real();
            t_2 = -parte_imaginaria*c.getparte_imaginaria();
            t_3 = parte_real*c.getparte_imaginaria();
            t_4 = parte_imaginaria*c.getparte_real();
            t_r = t_1+t_2;
            t_i = t_3+t_4;
        cout<<"multiplicacion: ("<<t_r<<", "<<t_i<<")"<<endl;
    }
    void division(Complejo c){
        double t = (-1)*t_2;
        double reales = t+t_1;
        double m = (-1)*t_3;
        double imaginarios = m+t_4;
        double denominador = pow(c.getparte_real(),2)+pow(c.getparte_imaginaria(),2);
        double t1_nuevo_complejo = reales/denominador;
        double t2_nuevo_complejo = imaginarios/denominador;
        cout<<"Division: "<<"("<<t1_nuevo_complejo<<", "<<t2_nuevo_complejo<<")";
    }
};
int main(){
double r1, r2, i1, i2;
cout<<"El numero complejo resultante se expresara como una pareja ordenada."<<endl;
cout<<"Ingrese la parte real de su complejo1: "; cin>>r1;
cout<<"Ingrese la parte imaginaria de su complejo1: "; cin>>i1;
cout<<"Ingrese la parte real de su complejo2: "; cin>>r2;
cout<<"Ingrese la parte imaginaria de su complejo2: "; cin>>i2;
Complejo C1(r1,i1);
Complejo C2(r2,i2);
C1.suma(C2);
C1.resta(C2);
C1.multiplicacion(C2);
C1.division(C2);
return 0;
}
