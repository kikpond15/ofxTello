#pragma once

//#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxUDPManager.h"

using namespace std;

class ofxTello {
public:
    ofxTello();
    void connect();
    void takeoff();
    void land();
    void streamon();
    void streamoff();
    void emergency();
    void up(int distance);
    void down(int distance);
    void left(int distance);
    void right(int distance);
    void foward(int distance);
    void back(int distance);
    void cw(int angle);
    void ccw(int angle);
    void flip(string direction);
    void go(int x, int y, int z, int speed);
    void curve(int x1, int y1, int z1, int x2, int y2, int z2, int speed);
    void setSpeed(int speed);
    void rc(int rl, int fb, int updw, int yaw);
    
    //read function get received message by udp
    void speed();
    void battery();
    void time();
    void height();
    void temp();
    void attitude();
    void baro();
    void acceleration();
    void tof();
    void wifi();
    
    void receiveUpdate();
    void close();
    string getReceiveMessage();
    
    
//  Unimplemented　functions...
//    setWifi(string ssid, string pass);
    
    
    

private:
    ofxUDPManager udpConnection;
    int port;
    string ip, receivedMessage;
};
