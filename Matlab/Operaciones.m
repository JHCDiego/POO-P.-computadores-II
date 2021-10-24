%Ejercicio 9
classdef Operaciones < handle
    properties
        contador = 0; 
        numero = 0; 
        suma = 0;
        promedio = 0;
    end
    methods
        %Constructor
        function num1 = Operaciones()
            num1.contador = 0;
            num1.numero = 0;
            num1.suma = 0;
            num1.promedio = 0;
        end 
        function suma_promedio(num1)
            e = input('Escriba s para continuar: ','s');
            while(e=='s')
            num1.numero = input('Ingresa un numero: ');
            num1.suma = num1.suma+num1.numero;
            num1.contador = num1.contador+1;
            e = input('Escriba s para continuar: ','s');
            end
            num1.promedio = num1.suma/num1.contador;
            fprintf('sumatoria: %.2f\n',num1.suma);
            fprintf('promedio: %.2f\n',num1.promedio);
         end 
    end 
end 