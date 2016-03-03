package eu.elraro.asteroids;

import android.app.AlertDialog;
import android.os.Bundle;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceFragment;

public class Preferencias extends PreferenceActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getFragmentManager().beginTransaction().replace(android.R.id.content, new MyPreferenceFragment()).commit();
    }

    public static class MyPreferenceFragment extends PreferenceFragment {
        @Override
        public void onCreate(final Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            addPreferencesFromResource(R.xml.preferencias);

            findPreference("nombre").setOnPreferenceChangeListener(
                    new Preference.OnPreferenceChangeListener() {

                        @Override
                        public boolean onPreferenceChange(Preference preference, Object newValue) {
                            Boolean rtnval = true;
                            if (((String) newValue).contains(" ") | ((String) newValue).contains("\\") | ((String) newValue).length() > 10) {
                                final AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
                                builder.setTitle("Nombre no válido");
                                builder.setMessage("El nombre no puede contener espacio, el carácter \\ ni ser mayor de 10 caracteres");
                                builder.setPositiveButton(android.R.string.ok, null);
                                builder.show();
                                rtnval = false;
                            }
                            return rtnval;
                        }

                    });
        }
    }

}
