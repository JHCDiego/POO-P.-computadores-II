#include <iostream>
#include <cmath>
using namespace std;

class Rectangulo{

public:
    double* V_x, *V_y;
    double base, altura;
    Rectangulo(double* a, double* b){
        V_x = a;
        V_y = b;
        cout<<"\n";
        for(int i=0;i<4;i++){
        cout<<"V_"<<i+1<<"("<<V_x[i]<<", "<<V_y[i]<<")"<<endl;
         }
    }
    Rectangulo(double b, double h){
        V_x = new double[4]; V_y = new double[4];
        V_x[0] = 0; V_y[0] = 0;
        V_x[1] = b; V_y[1] = 0;
        V_x[2] = 0; V_y[2] = h;
        V_x[3] = b; V_y[3] = h;
       cout<<"Coordenadas: "<<endl;
            for(int i=0;i<4;i++){
                cout<<"V_"<<i+1<<"("<<V_x[i]<<", "<<V_y[i]<<")"<<endl;
                 }
    }
    void Area(){
        base = abs(V_x[1]-V_x[0]);
        altura = abs(V_y[2]-V_y[0]);
        cout<<"\n";
        cout<<"El area de su rectangulo es: "<<base*altura<<endl;
    }
    void desplazamiento(double x, double y){
        V_x[0]+=x; V_y[0]+=y;
        V_x[1]+=x; V_y[1]+=y;
        V_x[2]+=x; V_y[2]+=y;
        V_x[3]+=x; V_y[3]+=y;
        cout<<"\n";
        cout<<"El rectangulo desplazado, tiene por coordenadas: "<<endl;
        for(int i=0;i<4;i++){
            cout<<"V_"<<i+1<<"("<<V_x[i]<<", "<<V_y[i]<<")"<<endl;
        }
    }
};
int main(){
double x,y;
double c_x[4], c_y[4];
int eleccion;
string e;
cout<<"1. Ingresar las coordenadas de los vertices de su rectangulo."<<endl;
cout<<"2. Ingresar la base y la altura de su rectangulo."<<endl;
cout<<"3. Salir."<<endl;
cout<<"Eliga: "; cin>>eleccion;
    switch(eleccion){
        case 1:
            {for(int i = 0;i<4;i++){
            cout<<"V_"<<i+1<<": "; cin>>c_x[i]>>c_y[i];
            }
            Rectangulo r1(c_x,c_y);
            r1.Area();
            cout<<"Desea desplazar su rectangulo? Escriba 'Si' para continuar: "; cin>>e;
                if(e=="Si"){
                    cout<<"Cuantas unidades desea desplazar el rectangulo?"<<endl;
                    cout<<"Horizontalmente: ";cin>>x;
                    cout<<"Verticalemente: ";cin>>y;
                    r1.desplazamiento(x,y);
                }
                else{
                    cout<<"Gracias por usar el programa.";
                    exit(0);
                }
            }
            break;
        case 2:
            {
            cout<<"Base: "; cin>>x;
            cout<<"Altura: "; cin>>y;
            Rectangulo r2(x,y);
            r2.Area();
            cout<<"Desea desplazar su rectangulo? Escriba 'Si' para continuar: "; cin>>e;
                if(e=="Si"){
                    cout<<"Cuantas unidades desea desplazar el rectangulo?"<<endl;
                    cout<<"Horizontalmente: ";cin>>x;
                    cout<<"Verticalemente: ";cin>>y;
                    r2.desplazamiento(x,y);
                }
                else{
                    cout<<"Gracias por usar el programa.";
                    exit(0);
                }
            }
            break;
        case 3:
            cout<<"Gracias por usar el programa.";
            exit(0);
    }
return 0;
}

