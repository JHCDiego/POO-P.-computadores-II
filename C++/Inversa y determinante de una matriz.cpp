#include <iostream>
#include <fstream>
using namespace std;

class matriz{
private:
    //Atributos de nuestra clase "matriz".
    int N; double **A, **Identidad, **Inversa, *sol;
public:
    matriz(int tamanno){
    N = tamanno;
    };
        void entradas(){
            //Lectura de datos
            int i,j;
            ifstream fichero("DATA.txt");
            if (!fichero){
                    cout<<"EL ARCHIVO NO EXISTE\n";
                    cout<<"PROGRAMA FINALIZADO\n";
                    exit(0);
                    }
                    A = new double*[N];
                    for(i=0;i<N;i++){
                            A[i] = new double[N];
                    }
                    for(i=0;i<N;i++){
                        for(j=0;j<N;j++){
                            fichero>>A[i][j];
                        }
                    }
                    //Muestra la matriz cuadrada de nuestro archivo en pantalla.
                    cout<<"A = \n";
                    for(i=0;i<N;i++){
                            for(j=0;j<N;j++)
                            {
                                cout<<"\t"<<A[i][j];
                    }
                    cout<<"\n";
                }
                cout<<"\n";
                //Creación matriz identidad auxiliar.
                Identidad = new double*[N];
                for(int i=0;i<N;i++){
                        Identidad[i] = new double[N];
                }
                for(i=0;i<N;i++){
                        for(j=0;j<N;j++){
                            if(i==j){
                                Identidad[i][j] = 1;
                                }
                            else{
                                 Identidad[i][j] = 0;
                            }
                        }
                }
        }
        /*Se forma de la matriz original 'A' una matriz triangular superior
        operándose simultáneamente con la matriz identidad auxiliar.*/
        void op(){
            int i,j,h,p,k; double tmp, tmp_2, m;
            for(i=0;i<N-1;i++){
                    for(p=i;p<N;p++)
                        if((p>=i) && (A[p][i]!=0))
                        break;
                    if(p!=i){
                            for(h=0;h<N;h++){
                                tmp = A[i][h];
                                A[i][h] = A[p][h];
                                A[p][h] = tmp;
                                tmp_2 = Identidad[i][h];
                                Identidad[i][h] = Identidad[p][h];
                                Identidad[p][h] = tmp_2;
                                }
                            }
                            for(j=i+1;j<N;j++){
                                    m = A[j][i]/A[i][i];
                                    for(k=0;k<N;k++){
                                            A[j][k] = A[j][k]-m*A[i][k];
                                            Identidad[j][k] = Identidad[j][k]-m*Identidad[i][k];
                                            }
                                    }
                    }
        }
        //Método que calcula la matriz inversa de nuestra matriz cuadrada.
        void inversa(){
            int i,j,k;
            Inversa = new double*[N];
            for(i=0;i<N;i++){
                    Inversa[i] = new double[N];
            }
            for(k=0;k<N;k++){
                    double sumatoria;
                    if(A[N-1][N-1]==0){
                            cout<<"\nNO EXISTE SOLUCION UNICA";
                            exit (0);
                            }
                    sol = new double[N];
                    sol[N-1] = Identidad[N-1][k]/A[N-1][N-1];
                    for(i=N-2;i>=0;i--){
                            sumatoria = 0;
                            for(int j=i+1;j<N;j++){
                                    sumatoria = sumatoria+A[i][j]*sol[j];
                            }
                            double numerador;
                            numerador = Identidad[i][k]-sumatoria;
                            if(numerador==0){
                                    sol[i] = 0;
                            }
                            else{
                                    sol[i] = (Identidad[i][k]-sumatoria)/A[i][i];
                            }
                }
                for(i=0;i<N;i++){
                        Inversa[i][k]  = sol[i];
                }
        }
        cout<<"\nA^-1 = \n";
        for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    cout<<"\t"<<Inversa[i][j];
        }
        cout<<"\n";
        }
        cout<<"\nPROGRAMA FINALIZADO CORRECTAMENTE";
        exit(0);
}
//Método que calcula el determinante de nuestra matriz cuadrada.
void determinante(){
    int i,j;
    double dte = A[0][0];
    for(i=1;i<N;i++){
            for(j=1;j<N;j++){
                if(i==j){
                    dte = (-1)*(dte*A[i][j]);
                }
            }
       }
       cout<<"\ndet A = "<<dte;
       cout<<"\nPROGRAMA FINALIZADO CORRECTAMENTE";
       exit(0);
}

//Destructor, libera la memoria que se reservó.
~matriz(){
    for(int i=0;i<N;i++){
        delete[] A[i];
    }
    delete[] A;
    for(int i=0;i<N;i++){
        delete[] Inversa[i];
    }
    delete[] Inversa;
    for(int i=0;i<N;i++){
        delete[] Identidad[i];
    }
    delete[] Identidad;
    delete[] sol;
}
};

int main(){
    int elegir, N;
    cout<<"INGRESE EL VALOR 'N'. 'N' REPRESENTA SU NUMERO DE FILAS Y COLUMNAS DE SU MATRIZ n x n\n";
    cout<<"N = "; cin>>N;
    matriz filas_columnas(N);
    filas_columnas.entradas();
    cout<<"\n";
    cout<<"INGRESE UN NUMERO PARA:"<<endl;
    cout<<"1. CALCULAR LA MATRIZ INVERSA DE SU MATRIZ.\n";
    cout<<"2. CALCULAR EL DETERMINANTE DE SU MATRIZ.\n";
    cin>>elegir;
    switch (elegir){
        case 1:
            cout<<"USTED HA ELEGIDO LA OPCION "<<elegir;
            filas_columnas.op();
            filas_columnas.inversa();
        case 2:
            cout<<"USTED HA ELEGIDO LA OPCION "<<elegir;
            filas_columnas.op();
            filas_columnas.determinante();
        default:
            cout<<"LA ENTRADA NO ES CORRECTA\n";
            cout<<"PROGRAMA FINALIZADO";
            exit (0);
            }
return 0;
}
