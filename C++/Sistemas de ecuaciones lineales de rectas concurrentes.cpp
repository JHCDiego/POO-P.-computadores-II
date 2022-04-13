//Programa sujeto a derechos de autor. Juan Diego Herrera Castellar//

//MÉTODO DE ELIMINACIÓN GAUSSIANA CON SUSTITUCIÓN REGRESIVA//
/*Nota: Debe ingresar los coeficientes y los términos independientes
de sus ecuaciones lineales en sentido de izquierda a derecha.*/

#include <iostream>
#include <stdlib.h>
using namespace std;
double **Matriz; double *s;
double m_mk;
int i,j,k,m,n;
void Datosmatriz(){
    cout<<"ESCRIBA EL VALOR DE n DE SU MATRIZ AUMENTADA n x (n+1)"<<endl;
    cout<<"n = "; cin>>n;
    Matriz = new double*[n];
    for(i=0;i<n;i++){
        Matriz[i] = new double[n+1];
    }
    cout<<"\nDIGITE LOS COEFICIENTES DE SU SISTEMA LINEAL "<<n<<" x "<<n+1<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            cout<<"a_"<<"["<<i+1<<"]["<<j+1<<"] = ";
            cin>>Matriz[i][j];
        }
        cout<<"\n";
    }
}
void Mostrarmatriz(){
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            cout<<Matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void Algoritmo(){
    //Step 1.
    for(i=0;i<n-1;i++){
            //Step 2.
            int p=0;
        for(p=i;p<n;p++){
            if((p>=i) && (Matriz[p][i]!=0))
               break;
        }
        //Step 3.
        if(p!=i){
            double var;
            for(int k=0;k<n+1;k++){
                var = Matriz[i][k];
                Matriz[i][k] = Matriz[p][k];
                Matriz[p][k] = var;
            }
        }
        //Step 4.
        for(int m=i+1;m<n;m++){
            //Step 5.
            m_mk = Matriz[m][i]/Matriz[i][i];
            for(int k=0;k<n+1;k++){
                //Step 6.
                Matriz[m][k] = Matriz[m][k]-m_mk*Matriz[i][k];
            }
        }
    }
    cout<<"\n";
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            cout<<Matriz[i][j]<<"\t";
        }
        cout<<"\n";
    }
    s = new double[n];
    //Step 7.
    if(Matriz[n-1][n-1]==0){
        cout<<"No existe solucion unica";
        exit(0);
    }
    //Step 8.
    s[n-1] = Matriz[n-1][n]/Matriz[n-1][n-1];
    //Step 9.
    for(i=n-2;i>=0;i--){
        double sumatoria = 0;
        for(int j=i+1;j<n;j++){
            sumatoria = sumatoria+s[j]*Matriz[i][j];
        }
        s[i] = (Matriz[i][n]-sumatoria)/Matriz[i][i];
    }
    cout<<endl;
    cout<<"LAS SOLUCIONES DE SU SISTEMA LINEAL DE "<<n<<" ECUACIONES Y "<<n<<" INCOGNITAS SON: ";
    cout<<"\n";
    for(i=0;i<n;i++){
        cout<<"x["<<i+1<<"] = "<<s[i]<<endl;
    }
    cout<<"\nPROGRAMA FINALIZADO CORRECTAMENTE";

}
void Liberarmemoria(){
for(i=0;i<n;i++){
    delete[] Matriz[i];
}
delete[] Matriz;
delete[] s;
}
int main(){
Datosmatriz();
Mostrarmatriz();
Algoritmo();
Liberarmemoria();
return 0;
}
