%Ejercicio 8
classdef Operacion < handle
    properties
        n = 0;
        numeros = [];
        suma = 0;
    end
    methods
        function ob1 = Operacion(m)
            ob1.n = m;
            ob1.suma = 0;
            ob1.numeros = [];
        end
        function datos(ob1)
            ob1.numeros = zeros(1,ob1.n);
            for i=1:ob1.n
                ob1.numeros(i) = input('Ingese un numero: '); 
            end
        end
        function sumatoria(ob1)
            for i=1:ob1.n
              ob1.suma = ob1.suma+ob1.numeros(i);
            end 
            fprintf('sumatoria: %.2f\n',ob1.suma);
        end
        function promedio(ob1)
            fprintf('promedio: %.2f\n',ob1.suma/ob1.n);
        end 
       end
end