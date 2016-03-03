package eu.elraro.asteroids;

public class AsteroidsJNILib {

    // Libreria JNI
    static {
        System.loadLibrary("Asteroids");
    }

    // Crear la pantalla con ese ancho y alto
    public static native void change(int width, int height);

    // Crear frame
    public static native void frame();

    // Iniciar el juego con la dificultad establecida
    public static native void create(int dificultad);

    // Rotar nave a la izquierda
    public static native void izquierda();

    // Rotar nave a la derecha
    public static native void derecha();

    // Acelerar nave
    public static native void acelerar();

    // Disparar
    public static native void disparar();

}
