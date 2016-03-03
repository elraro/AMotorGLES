package eu.elraro.asteroids;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.List;

public class ItemAdapter extends BaseAdapter {

    private Context context;
    private List<JugadorRanking> items;

    public ItemAdapter(Context context, List<JugadorRanking> items) {
        this.context = context;
        this.items = items;
    }

    @Override
    public int getCount() {
        return this.items.size();
    }

    @Override
    public Object getItem(int position) {
        return this.items.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        View rowView = convertView;

        // Si la vista es null la generamos
        if (convertView == null) {
            LayoutInflater inflater = (LayoutInflater) context
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            rowView = inflater.inflate(R.layout.list_item, parent, false);
        }
        
        TextView posicionJugador = (TextView) rowView.findViewById(R.id.textPosition);
        TextView jugador = (TextView) rowView.findViewById(R.id.textJugador);

        JugadorRanking item = this.items.get(position);
        posicionJugador.setText("Posición " + (position + 1));
        jugador.setText("" + item.getNombre() + " - Puntuación: " + item.getPuntuacion());

        return rowView;
    }

}
