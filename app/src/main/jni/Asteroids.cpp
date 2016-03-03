#include <jni.h>

#include <GLES/gl.h>
#include "triangulo.h"
#include "escena.h"

Escena *e;

void init(int dificultad) {
    // Activamos el sombreado suave
    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    e = new Escena();
    e->start(dificultad);
}

void reshape(int w, int h) {

    glViewport(0, 0, w, h);     //Reiniciamos la visión actual
    glMatrixMode(GL_PROJECTION);    //Selecionamos la matriz de proyección
    glLoadIdentity();                    //Reiniciamos

    glOrthof(-200.0f, 200.0f, -100.0f, 100.0f, 0.01f, 40.0f); // Vista ortogonal

    glMatrixMode(GL_MODELVIEW);     //Seleccionamso la matriz del modelo de visión
    glLoadIdentity();                    //Reiniciamos

}

void renderFrame() {

    // Limpiamos buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();

    // Actualizamos posiciones
    e->update(0.01f);

    // Resolvemos colisiones
    e->resuelveColisiones();

    // Dibujamos
    e->render();

    glPopMatrix();

    // Si ya no tengo vidas
    if (e->getLives() == 0) {

        // Plan A, fracaso, descartado

//        LOGE3("peta -1");
//        JNIEnv *env;
//        static JavaVM *jvm;
//        int a = env->GetJavaVM(&jvm);
//        LOGE3("%f", a);
//        jvm->AttachCurrentThread(&env, NULL);
//        if (env == NULL) {LOGE3("null");}
//
//        LOGE3("peta 0");
//        jclass dataClass = env->FindClass("eu/elraro/asteroids/VariablesGlobalesJNI");
//        LOGE3("peta 1");
//        jclass javaClassRef = (jclass) env->NewGlobalRef(dataClass);
//        LOGE3("peta 2");
//        jmethodID javaMethodRef = env->GetMethodID(javaClassRef, "setPuntuacion", "(I)V");
//        LOGE3("peta 3");
//        jobject javaObjectRef = env->NewObject(javaClassRef, javaMethodRef);
//        LOGE3("peta 4");
//        env->CallVoidMethod(javaObjectRef, javaMethodRef, score);
//        LOGE3("peta 5");

        // Plan B, un fichero plano... No es lo mejor pero...
        // Guardar la puntuacion
        ofstream myfile;
        myfile.open("/sdcard/asteroids/score.txt");
        myfile << e->getScore();
        myfile.close();

        // Salimos
        exit(0);

    }

}

/**
 * Métodos para mover la nave
 */

void disparar() {
    if (!e->isDead()) {
        e->disparar();
    }
}

void acelerar() {
    if (!e->isDead()) {
        e->getShip()->updatePosition(false, false, true);
    }
}

void izquierda() {
    if (!e->isDead()) {
        e->getShip()->updatePosition(true, false, false);
    }
}

void derecha() {
    if (!e->isDead()) {
        e->getShip()->updatePosition(false, true, false);
    }
}

extern "C" {
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_change(JNIEnv *env, jobject obj,
                                                                       jint width, jint height);
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_frame(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_create(JNIEnv *env, jobject obj,
                                                                       jint dificultad);
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_izquierda(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_derecha(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_acelerar(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_disparar(JNIEnv *env, jobject obj);
};

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_change(JNIEnv *env, jobject obj,
                                                                       jint width, jint height) {
    reshape(width, height);
}

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_frame(JNIEnv *env, jobject obj) {
    renderFrame();
}

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_create(JNIEnv *env, jobject obj,
                                                                       jint dificultad) {
    init(dificultad);
}

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_izquierda(JNIEnv *env,
                                                                          jobject obj) {
    izquierda();
}

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_derecha(JNIEnv *env, jobject obj) {
    derecha();
}

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_acelerar(JNIEnv *env, jobject obj) {
    acelerar();
}

JNIEXPORT void JNICALL Java_eu_elraro_asteroids_AsteroidsJNILib_disparar(JNIEnv *env, jobject obj) {
    disparar();
}