package aed;
import java.util.ArrayList;
import java.util.List;

public class NodoTrie<T> {
    private NodoTrie<T>[] hijos;
    private T valor;

    
    public NodoTrie() {
        hijos = new NodoTrie[256];  // Todos los caracteres ASCII
        valor = null;
    }

    public NodoTrie<T>[] getHijos() {
        return hijos;
    }

    public T getValor() {
        return valor;
    }

    public void setearValor(T valor) {
        this.valor = valor;
    }

    public void eliminarValor() {
        this.valor = null;
    }

    public NodoTrie<T> obtenerHijo(char c) {
        return hijos[c];
    }

    public void establecerHijo(char c, NodoTrie<T> hijo) {
        hijos[c] = hijo;
    }

    public boolean tieneHijos() {
        for (NodoTrie<T> hijo : hijos) {
            if (hijo != null) {
                return true;
            }
        }
        return false;
    }
}

