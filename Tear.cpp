#include "Tear.h"

Tear::Tear() : Tear(ofVec3f(0, 0, 0)) {
}

Tear::Tear(ofVec3f location){
	this->location = location;

	this->location_angle = ofRandom(360);
	this->location_radius = ofRandom(50, ofGetWidth() / 2);
	this->speed = ofRandom(1, 5);
	ofRandom(100) > 50 ? this->location_direction = -1 : this->location_direction = 1;

	this->a = 8;
	this->r = 50;
	this->body_color_value = ofRandom(255);
}

Tear::~Tear() {

}

void Tear::update() {
	this->location_radius = (this->location_radius + speed) % ofGetWidth();

	float x = this->location_radius * cos(this->location_angle * DEG_TO_RAD);
	float y = this->location_radius * sin(this->location_angle * DEG_TO_RAD);

	this->location = ofVec3f(x, y, 0);
}

void Tear::draw() {
	ofPushMatrix();
	ofTranslate(this->location);
	ofRotateZ(this->location_angle + 180);

	ofColor c;
	c.setHsb(this->body_color_value, 255, 255);
	ofSetColor(c);

	ofBeginShape();
	for (int theta = 0; theta < 360; theta++) {
		float r = 1 / (this->a * sin(theta * DEG_TO_RAD / 2) + 1);
		ofVertex(ofVec3f(this->r * r * cos(theta * DEG_TO_RAD), this->r * r * sin(theta * DEG_TO_RAD), 0));
	}
	ofEndShape(true);

	ofPopMatrix();
}