classdef Complejo < handle
    properties
        parte_real = 0;
        parte_imaginaria = 0;
        end
        methods
       
        function Complex = Complejo(r,im)
            Complex.parte_real = r;
            Complex.parte_imaginaria = im;
        end
        function re = getparte_real(obj)
             re = get(obj,'parte_real');
        end
        function img = getparte_imaginaria(obj)
            img = get(obj,'parte_imaginaria');
        end
        function setparte_real(Complex)
            rea = set(Complex,'parte_real','0');
        end 
            function setparte_imaginaria(Complex)
                    ima = set(Complex,'parte_imaginaria','0');
            end
            function suma(obj)
                suma_real = Complex.parte_real+obj.getparte_real();
                suma_imaginaria = Complex.parte_imaginaria+obj.getparte_imaginaria();
                fprintf('Suma: (%.2f,%.2f)',suma_real,suma_imaginaria);
            end
            function resta(obj)
                resta_real = Complex.parte_real-obj.getparte_real();
                resta_imaginaria = Complex.parte_imaginaria-obj.getparte_imaginaria();
                fprintf('Resta: (%.2f,%.2f)',resta_real,resta_imaginaria);
            end
            function multiplicacion(obj)
                t_1 = Complex.parte_real*obj.getparte_real();
                t_2 = (-1)*Complex.parte_imaginaria*obj.getparte_imaginaria();
                t_3 = Complex.parte_real*obj.getparte_imaginaria();
                t_4 = Complex.parte_imaginaria*obj.getparte_real();
                t_r = t_1+t_2;
                t_i = t_3+t_4;
                fprintf('Multiplicación: (%.2f,%.2f)',t_r,t_i);
            end
            function division(obj)
                t_1 = Complex.parte_real*obj.getparte_real();
                t_2 = (-1)*Complex.parte_imaginaria*obj.getparte_imaginaria();
                t_3 = Complex.parte_real*obj.getparte_imaginaria();
                t_4 = Complex.parte_imaginaria*obj.getparte_real();
                    t = (-1)*t_2;
                    reales = t+t_1;
                    m = (-1)*t_3;
                    imaginarios = m+t_4;
                    denominador = (obj.getparte_real())^2+(obj.getparte_imaginaria())^2;
                    t1_n_c = reales/denominador;
                    t2_n_c = imaginarios/denominador;
                     fprintf('División: (%.2f,%.2f)',t1_n_c,t2_n_c);
            end 
        end 
end 