package eu.elraro.asteroids;

public class JugadorRanking {

    private String nombre;
    private int puntuacion;

    public JugadorRanking(String nombre, int puntuacion) {
        this.nombre = nombre;
        this.puntuacion = puntuacion;
    }

    public String getNombre() {
        return this.nombre;
    }

    public int getPuntuacion() {
        return this.puntuacion;
    }

}
