package eu.elraro.asteroids;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ListView;

public class RankingActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ranking);

        ListView listView = (ListView) findViewById(R.id.listView);

        Ranking ranking = new Ranking(this);

        listView.setAdapter(new ItemAdapter(this, ranking.getRanking()));
    }
}
