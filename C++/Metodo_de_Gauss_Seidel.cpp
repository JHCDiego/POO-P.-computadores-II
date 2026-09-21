//Programa sujeto a derechos de autor. Juan Diego Herrera Castellar//

//MÉTODO ITERATIVO DE GAUSS-SEIDEL//
/*Nota: Debe ingresar los coeficientes y los términos independientes
de sus ecuaciones lineales en sentido de izquierda a derecha.
El método requiere a_[i][i] != 0 para todo i. La convergencia está
garantizada si la matriz es estrictamente diagonal dominante.*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

double **Matriz;      // matriz aumentada n x (n+1)
double *x;            // aproximación actual  x^(k+1)
double *XO;           // aproximación previa  x^(k)
double TOL;           // tolerancia
int i,j,k,n,N;        // N = número máximo de iteraciones

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

void Datositeracion(){
    x  = new double[n];
    XO = new double[n];
    cout<<"\nDIGITE LA APROXIMACION INICIAL XO = (xo_1,...,xo_"<<n<<")"<<endl;
    for(i=0;i<n;i++){
        cout<<"xo["<<i+1<<"] = ";
        cin>>XO[i];
    }
    cout<<"\nDIGITE LA TOLERANCIA TOL: "; cin>>TOL;
    cout<<"DIGITE EL NUMERO MAXIMO DE ITERACIONES N: "; cin>>N;
}

void Verificardiagonal(){
    for(i=0;i<n;i++){
        if(Matriz[i][i]==0){
            cout<<"\nEl elemento a_["<<i+1<<"]["<<i+1<<"] es cero.";
            cout<<"\nGauss-Seidel no puede aplicarse; reordene las filas del sistema.";
            exit(0);
        }
    }
}

void Algoritmo(){
    //Step 1.
    k = 1;
    //Step 2.
    while(k<=N){
        //Step 3.  x_i^(k+1) = (1/a_ii)(b_i - sum_{j<i} a_ij x_j^(k+1) - sum_{j>i} a_ij x_j^(k))
        for(i=0;i<n;i++){
            double suma1 = 0;   // términos ya actualizados en esta iteración
            double suma2 = 0;   // términos de la iteración anterior
            for(j=0;j<i;j++){
                suma1 = suma1 + Matriz[i][j]*x[j];
            }
            for(j=i+1;j<n;j++){
                suma2 = suma2 + Matriz[i][j]*XO[j];
            }
            x[i] = (Matriz[i][n]-suma1-suma2)/Matriz[i][i];
        }

        //Step 4.  criterio de parada: norma infinito de x - XO
        double norma = 0;
        for(i=0;i<n;i++){
            if(fabs(x[i]-XO[i])>norma)
                norma = fabs(x[i]-XO[i]);
        }

        cout<<"\nITERACION "<<k<<":\t";
        for(i=0;i<n;i++){
            cout<<"x["<<i+1<<"] = "<<x[i]<<"\t";
        }
        cout<<"\t||x - XO||_inf = "<<norma;

        if(norma<TOL){
            cout<<"\n\nEL PROCEDIMIENTO FUE EXITOSO. CONVERGIO EN "<<k<<" ITERACIONES.";
            cout<<"\nLAS SOLUCIONES APROXIMADAS DE SU SISTEMA LINEAL DE "<<n;
            cout<<" ECUACIONES Y "<<n<<" INCOGNITAS SON: \n";
            for(i=0;i<n;i++){
                cout<<"x["<<i+1<<"] = "<<x[i]<<endl;
            }
            cout<<"\nPROGRAMA FINALIZADO CORRECTAMENTE";
            return;
        }

        //Step 5.
        k = k+1;
        //Step 6.
        for(i=0;i<n;i++){
            XO[i] = x[i];
        }
    }
    //Step 7.
    cout<<"\n\nSE EXCEDIO EL NUMERO MAXIMO DE ITERACIONES N = "<<N;
    cout<<"\nEL PROCEDIMIENTO NO FUE EXITOSO.";
}

void Liberarmemoria(){
    for(i=0;i<n;i++){
        delete[] Matriz[i];
    }
    delete[] Matriz;
    delete[] x;
    delete[] XO;
}

int main(){
    Datosmatriz();
    Mostrarmatriz();
    Verificardiagonal();
    Datositeracion();
    Algoritmo();
    Liberarmemoria();
    return 0;
}
