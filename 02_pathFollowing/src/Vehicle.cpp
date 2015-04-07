//
//  Vehicle.cpp
//  02_pathFollowing
//
//  Created by Bernardo Santos Schorr on 4/5/15.
//
//

#include "Vehicle.h"

void Vehicle::setup(ofVec2f p, float ms, float mf, bool * _debug) {
    pos = p;
    r = 4.0;
    maxSpeed = ms;
    maxForce = mf;
    acc.set(0, 0);
    vel.set(maxSpeed, 0);
    
    debug = _debug;
}

void Vehicle::update() {
    vel += acc;
    vel.limit(maxSpeed);
    pos += vel;
    
    if (pos.x < -r) pos.x = ofGetWidth()+r;
    if (pos.x > ofGetWidth()+r) pos.x = -r;
    
}

void Vehicle::resetForces() {
    acc *= 0;
}

void Vehicle::applyForce(ofVec2f force) {
    acc += force;
}

void Vehicle::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    float rot = atan2( vel.y, vel.x );
    ofRotate(ofRadToDeg(rot));
    
    ofSetColor(255, 0, 0);
    ofTriangle(-40, 10, -40, -10, 0, 0);
    ofPopMatrix();
    
}

void Vehicle::seek(ofVec2f target) {
    ofVec2f desired = target - pos;
    
    float d = desired.length();
    desired.normalize();
    
    if (d == 0) return;
    
    // Normalize desired and scale to maximum speed
    desired.normalize();
    desired *= maxSpeed;
    
    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
    applyForce(steer);
    
}

