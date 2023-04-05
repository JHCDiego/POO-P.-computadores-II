#PreÃ¡mbulo#
library(foreign)
library(xtable)

Estudiantes <- c(82,96,99,102,103,103,106,107, 108,108,108,
                 108,109,110,110,111,113,113,113,113,115,115,
                 118,118,119,121,122,122,127,132,136,140,146)

A <- seq(82,146,length = nclass.Sturges(Estudiantes))

DATA <- hist(Estudiantes, breaks = A, right = FALSE, plot = FALSE)
I <- cut(Estudiantes,breaks = A, include.lowest=TRUE,right = FALSE)


#Columnas
#Frecuencia absoluta e intervalos
n_i  <- table(I)
#Frecuencia relativa
f_i <- DATA$counts/length(Estudiantes)
#Frecuencia absoluta acumulada
N_i <- cumsum(DATA$counts)
#Frecuencia relativa acumulada
F_i <- cumsum(f_i)
#Marcas de clase
m_i <- DATA$mids

Tabla <- cbind(n_i,f_i,N_i,F_i,m_i)
Tabla

print(xtable(Tabla),include.rownames = TRUE)


#Histograma
DATA <- hist(Estudiantes, main = "IQ de estudiantes", xlab = "Coeficiente intelectual", ylab = "Frecuencia", col = "white",
             breaks = A,xlim = c(80,150),ylim = c(0,15),right = FALSE, plot = TRUE)

#Media aritmética de Estudiantes
x_avge <- mean(Estudiantes)
x_avge

#Coeficiente de variación de Pearson
CV <- function(X,M){
  #X - Datos
  #M - Medida de tendencia central a analizar
  cv <- sd(X)/M*100 
  return(cv)
}
CV(Estudiantes)

#Mediana
#Frecuencias acumuladas
N_i <- cumsum(DATA$counts)
n_2 <- length(Estudiantes)/2
#Intervalo mediano
indice_imediano <- which(N_i >= n_2)[1]
#Cálculo de la mediana

L_i <- DATA$breaks[indice_imediano]
a_i <- diff(DATA$breaks)[indice_imediano]
n_i_mediana <- DATA$counts[indice_imediano]
N_i_ant_mediana <-N_i[indice_imediano - 1]
x_mdn <- L_i+((n_2- N_i_ant_mediana)*a_i/ n_i_mediana)
#Mediana
x_mdn

#Moda
#Intervalo modal
indice_imodal <- which.max(DATA$counts)
L_i <- DATA$breaks[indice_imodal]
n_i <- DATA$counts[indice_imodal]
n_i_ant <-  DATA$counts[indice_imodal-1]
n_i_sig <-  DATA$counts[indice_imodal+1]
a_i <- diff(DATA$breaks)[indice_imodal]
#Cálculo de moda
x_mda <- L_i+((n_i-n_i_ant)/((n_i-n_i_ant)+(n_i-n_i_sig)))*a_i
#Moda
x_mda


#Distribución normal

Estudiantes <- c(82,96,99,102,103,103,106,107, 108,108,108,
                 108,109,110,110,111,113,113,113,113,115,115,
                 118,118,119,121,122,122,127,132,136,140,146)

A <- seq(82,146,length = nclass.Sturges(Estudiantes))

DATA <- hist(Estudiantes, breaks = A, right = FALSE, plot = FALSE)

# Calcular los puntos de la campana de Gauss
x <- seq(min(DATA$breaks), max(DATA$breaks), length.out = 100)
y <- dnorm(x, mean(Estudiantes), sd(Estudiantes)) * diff(DATA$mids)[1] * length(Estudiantes)

# Graficar el histograma y la campana de Gauss
plot(DATA, main = "IQ de estudiantes",ylab = "Frecuencia", col = "lightblue", xlim = c(80, 150), ylim = c(0,15))
lines(x, y, col = "red", lwd = 2)



Holaaa







