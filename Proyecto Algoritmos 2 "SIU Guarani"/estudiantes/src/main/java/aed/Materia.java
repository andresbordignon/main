package aed;

import java.util.*;

public class Materia {
    private ListaEnlazada<String> inscriptos;
    private int[] docentes = {0,0,0,0};
    private tupla[] equivalentes;

    public Materia() {
        this.inscriptos = null;
        this.equivalentes = null;
    }
}