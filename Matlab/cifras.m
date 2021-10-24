classdef cifras < handle
    properties
        suma = 0;
        numero = 0;
        contador = 0;
        digitos = [];
    end
    methods
        function nr = cifras(n)
                nr.numero = n;
                nr.contador = 0;
                nr.digitos = [];
                nr.suma = 0;             
            end 
        function contarcifras(nr)
            tmp = nr.numero;
            while(tmp~=0)
                tmp = fix(tmp/10);
                nr.contador = nr.contador+1;
            end
        end
        function guardar_digitos(nr)
            tmp_2 = nr.numero;
            nr.digitos = zeros(1,nr.contador);
            for i=1:nr.contador
                nr.digitos(i) = mod(tmp_2,10);
                tmp_2 = fix(tmp_2/10);
            end
        end
        function suma_digitos(nr)
            nr.contarcifras()
            nr.guardar_digitos()
            nr.suma = 0;
            for i=1:nr.contador
                nr.suma = nr.suma+nr.digitos(i);
            end
            fprintf('La suma de los digitos de %d es %d\n',nr.numero,nr.suma);
        end
        function multiplo(nr)
            for i=1:nr.contador
                if(nr.digitos(i)==0)
                    fprintf('%d es multiplo de %d\n',nr.suma,nr.digitos(i));
                elseif(mod(nr.suma,nr.digitos(i))==0)
                    fprintf('%d es multiplo de %d\n',nr.suma,nr.digitos(i));
                else
                    fprintf('%d no es multiplo de %d\n',nr.suma,nr.digitos(i));
                end    
            end
        end
    end
end 
