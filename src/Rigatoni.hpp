//
//  Rigatoni.hpp
//  Bouncing Rigatonis
//
//

#pragma once
#include "ofMain.h"

class Rigatoni
{
public:

	Rigatoni();
    Rigatoni(glm::vec3 _pos, float _radius);

    void setup();
	void update();
	void draw();

    void setVelocity(glm::vec3 _vel);
    void applyForce(glm::vec3 force);

	// bounce off walls
	void bounceWalls(float left, float right, float top, float bottom, float front, float back);

    glm::vec3 pos, vel, acc;

    ofShader shader;

	float radius;
	float rot;
	ofColor color;
};
