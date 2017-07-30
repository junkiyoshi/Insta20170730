#pragma once

#include "ofMain.h"

class Tear {
public:
	Tear();
	Tear(ofVec3f location);
	~Tear();

	void update();
	void draw();

private:

	int location_angle, location_radius, location_direction;
	int a, r;
	int speed;
	float body_color_value;
	ofVec3f location;
};