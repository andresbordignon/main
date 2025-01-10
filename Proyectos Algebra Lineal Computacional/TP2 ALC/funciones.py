import numpy as np
from scipy.linalg import solve_triangular
## Este método nos devuelve el autovalor y el autovector más grande de la matriz A, calculado por método de la potencia
def metodoPotencia(A, v, cant_iteraciones = 1000):
    for i in range(cant_iteraciones):
        v = (A@v)/np.linalg.norm(A@v,2)
        r = (v.T @ A @ v) / (v.T @ v)
    return r.item(),v

## Algoritmo de deflación Hotelling, el cuál esta armado para que nos devuelva los dos autovalores más grandes con sus correspondientes autovectores.
def deflacionHotelling(C, epsilon=1e-6, cant_iteraciones=1000):
    v = np.random.rand(C.shape[0])
    v /= np.linalg.norm(v)

    autovalor1, autovector1 = metodoPotencia(C, v, cant_iteraciones)
    
    C_prime = C - autovalor1 * np.outer(autovector1, autovector1)
    
    v = np.random.rand(C.shape[0])
    v /= np.linalg.norm(v)
    
    autovalor2, autovector2 = metodoPotencia(C_prime, v, cant_iteraciones)
    
    return autovalor1, autovector1, autovalor2, autovector2
    
def calcularLU(A):
    L, U = [],[]
    P = None

    # su código
    matriz = np.array(A, dtype=float)  
    n = matriz.shape[0] 
    L = np.eye(n, dtype=float)  
    U = matriz.copy()  
    P = np.eye(n, dtype=float) 

    for j in range(n):
        
        # Encuentra el pivote máximo
        modulo_max = np.argmax(np.abs(U[j:, j])) + j
        
        # Intercambia las filas en U
        if modulo_max != j:
            U[[j, modulo_max], :] = U[[modulo_max, j], :]
            P[[j, modulo_max], :] = P[[modulo_max, j], :]
            if j > 0:
                L[[j, modulo_max], :j] = L[[modulo_max, j], :j]
        
        # Modifica L y U   
        for i in range(j+1, n):
            L[i, j] = U[i, j] / U[j, j]
            U[i, j:] -= L[i, j] * U[j, j:]
    ###########
    return L, U, P


def inversaLU(L, U, P=None):
    Inv = []
    # su código    
    n = L.shape[0]
    Inv = np.zeros((n, n), dtype=float)
    
    b = np.eye(n)
    
    for i in range(n):

        for j in range(n):
            Inv[j][i] = b[j][i] / L[j][j]
            for k in range(j + 1, n):
                Inv[k][i] -= L[k][j] * Inv[j][i]
        
        for j in range(n - 1, -1, -1):
            Inv[j][i] = Inv[j][i] / U[j][j]
            for k in range(j):
                Inv[k][i] -= U[k][j] * Inv[j][i]
    
    #En caso de que haya permutado para hayar L y U
    if P.any():
        Inv = Inv @ P.T
    ###########
    return Inv
