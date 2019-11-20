//
//  Rigatoni.cpp
//  Bouncing Rigatonis
//
//

#include "Rigatoni.hpp"

Rigatoni::Rigatoni()
{
    pos     = glm::vec3(0,0,0);
	radius  = ofRandom(5,20);
	rot = ofRandom(-90.0, 90.0);
	shader.load("shader.vert", "shader.frag");
    setup();
}

Rigatoni::Rigatoni(glm::vec3 _pos, float _radius)
{
	pos     = _pos;
	radius  = _radius;
	rot = ofRandom(-90.0, 90.0);
	shader.load("shader.vert", "shader.frag");
    setup();
}

void Rigatoni::setup()
{
    // assign color based on radius

    float hue   = ofMap(radius, 3, 20, 250, 150);
    color       = ofColor::fromHsb(hue, 255, 255);
}

void Rigatoni::update()
{
    vel += acc;
	pos += vel;
    acc *= 0;
    float t = ofGetElapsedTimef();
    float r = pos.x + pos.y + pos.z;
    rot += ofNoise(t/100.0 + r);
}

void Rigatoni::draw()
{
	ofPushStyle();
	shader.begin();
	ofSetColor(color);
	shader.setUniform1f("time", ofGetElapsedTimef());  // set float value
    shader.setUniform1f("depth", 50.f);
    ofPushMatrix();
    ofRotateDeg(rot, 1.0, 1.0, 1.0);
	ofDrawCylinder(pos, radius, radius * 3.0);
	ofPopMatrix();
	shader.end();
	ofPopStyle();
}

void Rigatoni::setVelocity(glm::vec3 _vel)
{
    vel = _vel;
}

void Rigatoni::applyForce(glm::vec3 force)
{
    acc += force;
}

void Rigatoni::bounceWalls(float left, float right, float top, float bottom, float front, float back)
{
	// check x
	if (pos.x < left + radius) {	// left
		pos.x = left + radius;
		vel.x *= -1.;
	}

	if (pos.x > right - radius) {	// right
		pos.x = right - radius;
		vel.x *= -1.;
	}

	// check y
	if (pos.y > top - radius) {	// top  (in 3D, +y is up!)
		pos.y = top - radius;
		vel.y *= -1.;
	}

	if (pos.y < bottom + radius) {	// bottom   (in 3D, -y is down!)
		pos.y = bottom + radius;
		vel.y *= -1.;
	}

	// check z
	if (pos.z < front + radius) {	// front    (in 3D, -z is near)
		pos.z = front + radius;
		vel.z *= -1.;
	}

	if (pos.z > back - radius) {	// back     (in 3D, +z is far)
		pos.z = back - radius;
		vel.z *= -1.;
	}

}
