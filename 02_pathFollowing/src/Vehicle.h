//
//  Vehicle.h
//  02_pathFollowing
//
//  Created by Bernardo Santos Schorr on 4/5/15.
//
//

#pragma once
#include "ofMain.h"

class Vehicle {
public:
    
    void setup(ofVec2f p, float ms, float mf, bool * _debug);
    void update();
    void draw();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void seek (ofVec2f target);
    
    //code goes here
    
    ofVec2f pos, vel, acc;
    
    float maxSpeed, maxForce;
    
    float r;
    bool * debug;
    
};
