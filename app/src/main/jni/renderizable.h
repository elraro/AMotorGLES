/*
 * renderizable.h
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */

#ifndef RENDERIZABLE_H_
#define RENDERIZABLE_H_

class Renderizable {
public:
    Renderizable();

    virtual ~Renderizable();

    virtual void render() = 0;
};

#endif /* RENDERIZABLE_H_ */
