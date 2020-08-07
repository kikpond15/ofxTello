#pragma once

#include "ofMain.h"
#include "ofxTello.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
        
    
    ofxTello tello;
    int distance, angle, speed;
};
