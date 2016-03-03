/*
 * planoY.h
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */

#ifndef PLANOY_H_
#define PLANOY_H_
#include "plano.h"

class PlanoY: public Plano {
	float p;
	float s;
public:
	PlanoY(float p=0,float s=100):Plano(Vector3D(0,1,0),Vector3D(0,-p,0)),p(p),s(s) {
		this->setColor(Vector3D(0,1,0));
	}
	virtual ~PlanoY();
	void render();
	void resuelveColision(Solido *s){
		Vector3D &v=s->getV();
		float vy=v.getY();
		vy*=-1;
		v.setY(vy);
	}
};

#endif /* PLANOY_H_ */
