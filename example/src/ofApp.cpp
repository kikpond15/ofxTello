#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    distance = 50;
    angle = 45;
    speed = 50;
    tello.connect();
}

//--------------------------------------------------------------
void ofApp::update(){
    tello.receiveUpdate();
    if(tello.getReceiveMessage().length() > 0){
        cout << tello.getReceiveMessage() << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 't'){
        tello.takeoff();
    } else if(key == 'l'){
        tello.land();
    } else if(key == 'w'){
        tello.foward(distance);
    } else if(key == 's'){
        tello.back(distance);
    } else if(key == 'a'){
        tello.left(distance);
    } else if(key == 'd'){
        tello.right(distance);
    } else if(key == OF_KEY_UP){
        tello.up(distance);
    } else if(key == OF_KEY_DOWN){
        tello.down(distance);
    } else if(key == OF_KEY_RIGHT){
        tello.cw(angle);
    } else if(key == OF_KEY_LEFT){
        tello.ccw(angle);
    }
}

//--------------------------------------------------------------
void ofApp::exit(){
    tello.close();
}
