package aed;
import java.util.ArrayList;
import java.util.List;

public class Trie<T> {
private NodoTrie<T> raiz;

    public Trie() {
        raiz = new NodoTrie<>();
    }

    // Método para insertar una palabra y su valor en el Trie
    public void insertar(String palabra, T valor) {
        NodoTrie<T> nodoActual = raiz;

        for (char c : palabra.toCharArray()) {
            if (nodoActual.obtenerHijo(c) == null) {
                nodoActual.establecerHijo(c, new NodoTrie<T>());
            }
            nodoActual = nodoActual.obtenerHijo(c);
        }

        nodoActual.setearValor(valor);
    }

    // Método para buscar una palabra en el Trie
    public T buscar(String palabra) {
        NodoTrie<T> nodoActual = raiz;

        for (char c : palabra.toCharArray()) {
            nodoActual = nodoActual.obtenerHijo(c);
            if (nodoActual == null) {
                return null;
            }
        }

        return nodoActual.getValor();
    }

    // Método para verificar si una palabra existe en el Trie
    public boolean contiene(String palabra) {
        NodoTrie<T> nodoActual = raiz;

        for (char c : palabra.toCharArray()) {
            nodoActual = nodoActual.obtenerHijo(c);
            if (nodoActual == null) {
                return false;
            }
        }

        return !(nodoActual.getValor() == null);
    }

    public void eliminar(String palabra) {
        eliminar(raiz, palabra, 0);
    }

    private void eliminar(NodoTrie<T> nodo, String palabra, int indice) {
        if (indice == palabra.length()) {
            if (nodo.getValor() != null) {
                nodo.setearValor(null);
            }
            return;
        }

        char c = palabra.charAt(indice);
        NodoTrie<T> hijo = nodo.obtenerHijo(c);
        if (hijo == null) {
            return;
        }

        else {eliminar(hijo, palabra, indice + 1);

        if (!hijo.tieneHijos() && hijo.getValor() == null) {
            nodo.establecerHijo(c, null);
        }}
    }
}