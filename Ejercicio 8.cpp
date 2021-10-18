#include <iostream>
using namespace std;
class Operacion{

	private:
		int n; double* numeros;
	public:
	    double suma = 0;
		Operacion(int m) {
            n = m;
		};
        void datos(){
        numeros = new double[n];
            for(int i=0;i<n;i++){
                cout<<"numero_"<<i+1<<" = ";
                cin>>numeros[i];
            }
        }

		void sumatoria() {
			for (int i=0;i<n;i++){
                suma += numeros[i];
			}
			cout<<"Suma = "<<suma<<endl;
		}

		void promedio(){
			cout<<"Promedio = "<<suma/n<<endl;
		}
};

int main() {
    int z;
	cout<<"Calcular la suma y el promedio de n numeros: "<<endl;
	cout<<"n = "; cin>>z;

	Operacion ob1(z);
	ob1.datos();
	ob1.sumatoria();
	ob1.promedio();

	return 0;
}
