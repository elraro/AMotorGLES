package eu.elraro.asteroids;

import android.content.Context;
import android.os.Environment;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Ranking {

    private Map<String, JugadorRanking> ranking;
    private final static String TARGET_BASE_PATH = Environment.getExternalStorageDirectory().getPath() + "/asteroids/";

    public Ranking() {
        reset();
    }

    public void reset() {
        File file = new File(TARGET_BASE_PATH + "ranking.txt");
        if (file.exists() && !file.isDirectory()) {
            file.delete();
        }
    }

    public Ranking(Context context) {
        this.ranking = new HashMap<>();
        BufferedReader brFile = null;
        try {
            brFile = new BufferedReader(new FileReader(TARGET_BASE_PATH + "ranking.txt"));
            String rankingLine = brFile.readLine();
            while (rankingLine != null) {
                String[] splited = rankingLine.split(" ");
                this.ranking.put(splited[0], new JugadorRanking(splited[0], Integer.parseInt(splited[1])));
                rankingLine = brFile.readLine();
            }
        } catch (FileNotFoundException e) {
            File f = new File(TARGET_BASE_PATH + "ranking.txt");
            try {
                f.createNewFile();
            } catch (IOException e1) {
                Toast.makeText(context, "Error al crear el ranking", Toast.LENGTH_LONG);
            }
        } catch (IOException e) {
        } finally {
            try {
                if (brFile != null) {
                    brFile.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void anadir(String nombre, String puntuacion) {
        if (this.ranking.containsKey(nombre)) {
            if (this.ranking.get(nombre).getPuntuacion() > Integer.parseInt(puntuacion)) {
                return;
            }
        }
        this.ranking.put(nombre, new JugadorRanking(nombre, Integer.parseInt(puntuacion)));
    }

    public void guardar() {
        BufferedWriter output = null;
        try {
            File file = new File(TARGET_BASE_PATH + "ranking.txt");
            output = new BufferedWriter(new FileWriter(file));

            List<JugadorRanking> list = sortList();

            if (list.size() > 10) {
                list.subList(10, list.size()).clear(); //eliminamos los que no sean los 10 primeros
            }

            for (JugadorRanking jugador : list) {
                output.write(jugador.getNombre() + " " + jugador.getPuntuacion() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (output != null) {
                    output.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public List<JugadorRanking> getRanking() {
        return sortList();
    }

    private List<JugadorRanking> sortList() {
        List<JugadorRanking> list = new ArrayList<>(this.ranking.values());
        Collections.sort(list, new Comparator<JugadorRanking>() {

            public int compare(JugadorRanking o1, JugadorRanking o2) {
                //Orden descendente
                return o2.getPuntuacion() - o1.getPuntuacion();
            }
        });
        return list;
    }
}
