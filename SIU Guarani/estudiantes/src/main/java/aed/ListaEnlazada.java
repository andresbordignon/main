package aed;

import java.util.*;

public class ListaEnlazada<T> {
    private Nodo primero;
    private int lenght;

    private class Nodo {
        T valor;
        Nodo siguiente;
        Nodo anterior;

        Nodo (T t) {valor = t;}
    }

    public ListaEnlazada() {
        this.primero = new Nodo(null);
        this.lenght = 0;
    }

    public int longitud() {
        return this.lenght;
    }

    public void agregarAdelante(T elem) {
        if (this.lenght == 0) {
            this.primero = new Nodo(elem);
            this.primero.anterior = null;
            this.primero.siguiente = null;
        } else {
            Nodo nuevoPrimero = new Nodo(elem);
            nuevoPrimero.anterior = null;
            nuevoPrimero.siguiente = this.primero;
            this.primero.anterior = nuevoPrimero;
            this.primero = nuevoPrimero;
            
        }
        
        this.lenght += 1;
    }

    public void agregarAtras(T elem) {
        if (this.lenght == 0) {
            this.primero = new Nodo(elem);
            this.primero.anterior = null;
            this.primero.siguiente = null;
        } else {
            Nodo nuevoUltimo = new Nodo(elem);
            Nodo actual = this.primero;
            while (actual.siguiente != null) {
                actual = actual.siguiente;

            }

            actual.siguiente = nuevoUltimo;
            nuevoUltimo.anterior = actual;
        }

        this.lenght += 1;
    }

    public T obtener(int i) {
        int j = 0;
        Nodo actual = primero;
        while (j != i) {
            j ++;

            actual = actual.siguiente;
        }
        return actual.valor;
        
    }

    public void eliminar(int i) {
        int j = 0;
        Nodo actual = this.primero;
        
        if (i == 0) { 
            this.primero = actual.siguiente;
     
        
        } else if (i == this.lenght - 1) {
            while (actual.siguiente != null) {
                actual = actual.siguiente;
            }
            actual.anterior.siguiente = null;

        } else {
            while (j != i) {
                actual = actual.siguiente;
                j ++;
        }  
        actual.anterior.siguiente = actual.siguiente;
        actual.siguiente.anterior = actual.anterior;       
        }

        this.lenght -= 1;
    }

    public void modificarPosicion(int indice, T elem) {      
        int j = 0;
        Nodo actual = this.primero;
        while (j != indice) {
            actual = actual.siguiente;
            j += 1;
        }

        actual.valor = elem;
    }

    public ListaEnlazada<T> copiar() {
        // nueva lista, nodo actuaal primero, usar agregar atras
        ListaEnlazada<T> nuevaLista = new ListaEnlazada<>();
        int j = 0;
        Nodo actual = this.primero;
        while (j < this.lenght) {
            nuevaLista.agregarAtras(actual.valor);
            actual = actual.siguiente;
            j++;
        }
        return nuevaLista;
    }

    public ListaEnlazada(ListaEnlazada<T> lista) {
        Nodo actualLista = lista.primero;
        while (actualLista != null) {
            this.agregarAtras(actualLista.valor);
            actualLista = actualLista.siguiente;
        }
    }
    
    @Override
    public String toString() {
        String res = "[";
        int j = 0;
        Nodo actual = this.primero;
        while (j < (this.lenght) - 1) {
            res = res + actual.valor.toString() + ", ";
            actual = actual.siguiente;
            j ++;
        }   
        res = res + actual.valor.toString() + "]";
        return res;
    }
}