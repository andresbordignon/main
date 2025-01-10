package aed;

public class tupla<A, B> {
    private A primero;
    private B segundo;

    public tupla(A primero, B segundo) {
        this.primero = primero;
        this.segundo = segundo;
    } 
    
    public A getPrimero() {
        return primero;
    }

    public B getSegundo() {
        return segundo;
    }

    }
