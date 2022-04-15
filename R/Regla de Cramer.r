#Su matriz debe ser cuadrada para que pueda ejecutarse
#correctamente este programa.
#Nota: la sentencia nrow(A) == ncol(A) es innecesaria 
#porque la función det() calcula el determinante de matrices cuadradas.
#Por lo tanto, si ingresa una matriz no cuadrada, el programa mostrará
#en pantalla un error por defecto que está incorporado en la función det().

regla_de_cramer <- function(A,b){
  if(det(A)!=0){
    n <- nrow(A)
    print("Las soluciones de su S.E.L son: ")
    for (j in  1:n){
      AuxM <- A
     AuxM[,j] <- b
      A_j <- AuxM
      x <- 1:n
      x[j] <- det(A_j)/det(A)
      print(paste("x _",j," = ",x[j]))
    }
  }
  else{
    stop("Debe cumplirse que: det(A) != 0.")
  }
}
