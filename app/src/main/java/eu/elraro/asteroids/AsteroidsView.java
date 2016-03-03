package eu.elraro.asteroids;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class AsteroidsView extends GLSurfaceView {

    private static int dificultad;

    public AsteroidsView(Context context, int dificultad) {
        super(context);
        this.dificultad = dificultad;
        // Creamos el render
        setRenderer(new Renderer());
    }

    private static class Renderer implements GLSurfaceView.Renderer {
        public void onDrawFrame(GL10 gl) {
            AsteroidsJNILib.frame();
        }

        public void onSurfaceChanged(GL10 gl, int width, int height) {
            AsteroidsJNILib.change(width, height);
        }

        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            AsteroidsJNILib.create(dificultad);
        }
    }

    /**
     *  Métodos para pasar de Java a JNI
     */
    public void disparar() {
        AsteroidsJNILib.disparar();
    }

    public void acelerar() {
        AsteroidsJNILib.acelerar();
    }

    public void derecha() {
        AsteroidsJNILib.derecha();
    }

    public void izquierda() {
        AsteroidsJNILib.izquierda();
    }

}
