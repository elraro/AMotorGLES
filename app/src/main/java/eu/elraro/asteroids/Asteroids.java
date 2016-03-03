package eu.elraro.asteroids;

import android.app.Activity;
import android.content.SharedPreferences;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.view.MotionEvent;
import android.view.Window;
import android.view.WindowManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Asteroids extends Activity {

    // La vista OpenGL
    private AsteroidsView vistaGL;

    private double time = System.currentTimeMillis();

    private final static String TARGET_BASE_PATH = Environment.getExternalStorageDirectory().getPath() + "/asteroids/";

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Fullscreen
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        // Copiamos los ficheros
        copiarFicherosSDCard();

        // Leemos la dificultad
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(this.getBaseContext());
        int dificultad = Integer.parseInt(sp.getString("dificultad", "0"));

        // Creamos una instancia de vista OpenGL
        vistaGL = new AsteroidsView(getApplication(), dificultad);

//        setContentView(R.layout.activity_asteroids);
//        vistaGL = (AsteroidsView)findViewById(R.id.graphics_glsurfaceview1);

        setContentView(vistaGL);
    }

    @Override
    protected void onResume() {
        super.onResume();
        vistaGL.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        vistaGL.onPause();
    }

    @Override
    public boolean onTouchEvent(MotionEvent e) {

        switch (e.getAction()) {
            // Movimiento de mantener pulsada la pantalla
            case MotionEvent.ACTION_MOVE:
                if (e.getY() > vistaGL.getHeight() - (vistaGL.getHeight() * 0.1)) { // Parte inferior
                    double localTime = System.currentTimeMillis();
                    if (localTime - time > 1000) { // Se puede disparar cada segundo
                        vistaGL.disparar();
                        time = System.currentTimeMillis();
                    }
                } else if (e.getY() < (vistaGL.getHeight() * 0.1)) { // Parte superior
                    vistaGL.acelerar();
                } else if (e.getX() > vistaGL.getWidth() - (vistaGL.getWidth() * 0.2)) { // Parte derecha
                    vistaGL.derecha();
                } else if (e.getX() < (vistaGL.getWidth() * 0.2)) { // Parte izquierda
                    vistaGL.izquierda();
                }
        }
        return true;
    }

    private void copiarFicherosSDCard() {
        borrarRecursivo(new File(TARGET_BASE_PATH + "/model")); // Borramos los ficheros por si hay nueva version
        copiarDirectorio(""); // Copiamos todos los assets del proyecto
    }

    void borrarRecursivo(File fileOrDirectory) {
        if (fileOrDirectory.isDirectory())
            for (File child : fileOrDirectory.listFiles())
                borrarRecursivo(child);

        fileOrDirectory.delete();
    }

    private void copiarDirectorio(String path) {
        AssetManager assetManager = this.getAssets();
        String assets[] = null;
        try {
            //Log.i("error", "copiarDirectorio() " + path);
            assets = assetManager.list(path);
            if (assets.length == 0) {
                copiarFichero(path);
            } else {
                String fullPath = TARGET_BASE_PATH + path;
                //Log.i("error", "path=" + fullPath);
                File dir = new File(fullPath);
                if (!dir.exists() && !path.startsWith("images") && !path.startsWith("sounds") && !path.startsWith("webkit")) {
                    if (!dir.mkdirs()) {
                        //Log.i("error", "no se pudo crear el directorio " + fullPath);
                    }
                }
                for (int i = 0; i < assets.length; ++i) {
                    String p;
                    if (path.equals("")) {
                        p = "";
                    } else {
                        p = path + "/";
                    }
                    if (!path.startsWith("images") && !path.startsWith("sounds") && !path.startsWith("webkit")) {
                        copiarDirectorio(p + assets[i]);
                    }
                }
            }
        } catch (IOException ex) {
            //Log.e("error", "I/O Excepcion", ex);
        }
    }

    private void copiarFichero(String filename) {
        AssetManager assetManager = this.getAssets();

        InputStream in = null;
        OutputStream out = null;
        String newFileName = null;
        try {
            //Log.i("error", "copiarFichero() " + filename);
            in = assetManager.open(filename);
            newFileName = TARGET_BASE_PATH + filename;
            out = new FileOutputStream(newFileName);

            byte[] buffer = new byte[1024];
            int read;
            while ((read = in.read(buffer)) != -1) {
                out.write(buffer, 0, read);
            }
            in.close();
            in = null;
            out.flush();
            out.close();
            out = null;
        } catch (Exception e) {
            //Log.e("error", "Excepcion en copiarFichero() of " + newFileName);
            //Log.e("error", "Excepcion en copiarFichero() " + e.toString());
        }

    }
}
