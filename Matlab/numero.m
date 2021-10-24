%Ejercicio 11
classdef numero
    properties
        num = 0;
    end
    methods
        %Constructor
        function nr = numero(n)
            nr.num = n; 
        end
        function numero_par(nr)
            if(mod(nr.num,2)==0)
                fprintf('%d es par\n',nr.num);
            else
                fprintf('%d no es par\n',nr.num);
            end
        end
        function  factorial(nr)
             f = 1;
             for i=1:nr.num
                 f = f*i;
             end
             fprintf('%d!: %d\n',nr.num,f);
        end 
        function digitos(nr)
            contador = 0;
            x = nr.num;
            while(x~=0)
                x = fix(x/10);
                contador = contador+1;
            end
            fprintf('%d tiene %d digito(s)\n',nr.num,contador);
         end
    end
end 
