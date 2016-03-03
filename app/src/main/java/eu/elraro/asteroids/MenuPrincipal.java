package eu.elraro.asteroids;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class MenuPrincipal extends Activity {

    private Button jugar;
    private Button ranking;
    private Button reset;
    private Button preferencias;

    // Ruta de los ficheros
    private final static String TARGET_BASE_PATH = Environment.getExternalStorageDirectory().getPath() + "/asteroids/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu_principal);

        jugar = (Button) findViewById(R.id.buttonJugar);
        jugar.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent myIntent = new Intent(MenuPrincipal.this, Asteroids.class);
                MenuPrincipal.this.startActivity(myIntent);
            }
        });

        preferencias = (Button) findViewById(R.id.buttonPreferencias);
        preferencias.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent myIntent = new Intent(MenuPrincipal.this, Preferencias.class);
                MenuPrincipal.this.startActivity(myIntent);
            }
        });

        ranking = (Button) findViewById(R.id.buttonRanking);
        ranking.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent myIntent = new Intent(MenuPrincipal.this, RankingActivity.class);
                MenuPrincipal.this.startActivity(myIntent);
            }
        });

        reset = (Button) findViewById(R.id.buttonResetRanking);
        reset.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                new AlertDialog.Builder(MenuPrincipal.this)
                        .setTitle("Borrar ranking")
                        .setMessage("¿Estás seguro?")
                        .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                                new Ranking().reset();
                            }
                        })
                        .setNegativeButton(android.R.string.no, new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                                // no hago nada
                            }
                        })
                        .setIcon(android.R.drawable.ic_dialog_alert)
                        .show();
            }
        });

        checkPuntuacion();

    }

    @Override
    public void onResume() {
        super.onResume();

        checkPuntuacion();
    }

    private void checkPuntuacion() {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(TARGET_BASE_PATH + "score.txt"));
            String score = br.readLine();
            if (Integer.parseInt(score) != 0) {
                Toast.makeText(this, "Puntuación " + Integer.parseInt(score), Toast.LENGTH_LONG).show();
            } else {
                Toast.makeText(this, "¡¡0 puntos!! Mi abuela es mejor que tú", Toast.LENGTH_LONG).show();
            }

            // Creamos el ranking
            Ranking ranking = new Ranking(this);

            // Leemos el nombre del jugador
            SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(this.getBaseContext());
            String nombre = sp.getString("nombre", "Jugador");

            // Lo añadimos al ranking (o actualizamos, depende)
            ranking.anadir(nombre, score);

            // Guardamos el ranking
            ranking.guardar();

            // Borramos el fichero score
            File f = new File(TARGET_BASE_PATH + "score.txt");
            f.delete();

            // Mostramos el ranking
            Intent myIntent = new Intent(this, RankingActivity.class);
            this.startActivity(myIntent);

        } catch (FileNotFoundException e) {

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
