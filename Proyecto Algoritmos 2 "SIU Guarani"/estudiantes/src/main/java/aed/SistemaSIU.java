package aed;

import javax.sound.midi.Sequence;

import aed.SistemaSIU.CargoDocente;


public class SistemaSIU {  

    private Trie<carrera> carreras;
    private Trie<Integer> libretas;

    enum CargoDocente{
        AY2,
        AY1,
        JTP,
        PROF
    }

    public SistemaSIU(InfoMateria[] materiasEnCarreras, String[] libretasUniversitarias){
        Trie<Integer> libretas = new Trie<Integer>();
        Trie<carrera> carreras = new Trie<carrera>();
        
        for (String libretaUniversitaria : libretasUniversitarias){
            libretas.insertar(libretaUniversitaria, 0); 
        }

        for (int i = 0; i < materiasEnCarreras.length; i++){
            Materia materia = new Materia();
            for (ParCarreraMateria tupla : materiasEnCarreras[i].getParesCarreraMateria()) {
                if (!carreras.contiene(tupla.getCarrera())) {
                    carrera carrera = new carrera();
                    carreras.insertar(tupla.getCarrera(), carrera);
                }
                (carreras.buscar(tupla.getCarrera())).trieMaterias.insertar(tupla.getNombreMateria(),materia);
                
                
                /* chequear si la carrera pertenece, lista[0]
                 * si no pertenece agregarla al trie,si pertenece agregar materia en trie materias de la carrera
                 * agregar la materia al trie de la carrera
                 * 
                 * materia.equivalentes.add(tupla(carrera,nombreMateria))
                 */
            }
        } 
    }

    public void inscribir(String estudiante, String carrera, String materia){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public void agregarDocente(CargoDocente cargo, String carrera, String materia){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public int[] plantelDocente(String materia, String carrera){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public void cerrarMateria(String materia, String carrera){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public int inscriptos(String materia, String carrera){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public boolean excedeCupo(String materia, String carrera){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public String[] carreras(){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public String[] materias(String carrera){
        throw new UnsupportedOperationException("Método no implementado aún");
    }

    public int materiasInscriptas(String estudiante){
        throw new UnsupportedOperationException("Método no implementado aún");
    }
}
