#include "ofxTello.h"
#include "ofUtils.h"

using namespace std;

ofxTello::ofxTello(){
    ip = "192.168.10.1";
    port = 8889;
    receivedMessage = "";
}

//--------------------------------------------------------------
void ofxTello::connect(){
    udpConnection.Create();
    udpConnection.Connect("192.168.10.1", port);
    udpConnection.SetNonBlocking(true);
    
    string message = "command";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::takeoff(){
    string message = "takeoff";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::land(){
    string message = "land";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::emergency(){
    string message = "emergency";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::up(int distance){
    string message = "up "+ofToString(distance);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::down(int distance){
    string message = "down "+ofToString(distance);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::foward(int distance){
    string message = "forward "+ofToString(distance);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::back(int distance){
    string message = "back "+ofToString(distance);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::right(int distance){
    string message = "right "+ofToString(distance);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::left(int distance){
    string message = "left "+ofToString(distance);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::cw(int angle){
    string message = "cw "+ofToString(angle);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::ccw(int angle){
    string message = "ccw "+ofToString(angle);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::flip(string dir){
    if(dir == "l" || dir == "r" || dir == "f" || dir == "b"){
        string message = "flip "+ofToString(dir);
        udpConnection.Send(message.c_str(), message.length());
    } else {
        cout << "Invalid argument : dir == l,r,f,b" << endl;
    }
}

//--------------------------------------------------------------
void ofxTello::go(int x, int y, int z, int speed){
    string str_x = ofToString(x);
    string str_y = ofToString(y);
    string str_z = ofToString(z);
    string str_speed = ofToString(speed);
    string message = "go "+str_x+" "+str_y+" "+str_z+" "+str_speed;
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::curve(int x1, int y1, int z1, int x2, int y2, int z2, int speed){
    string message = "curve "+ofToString(x1)+" "+ofToString(y1)+" "+ofToString(z1)+" "+ofToString(x2)+" "+ofToString(y2)+" "+ofToString(z2)+" "+ofToString(speed);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::setSpeed(int speed){
    string message = "speed " +ofToString(speed);
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::rc(int rl, int fb, int updw, int yaw){
    string str_rl = ofToString(rl);
    string str_fb = ofToString(fb);
    string str_updw = ofToString(updw);
    string str_yaw = ofToString(yaw);
    string message = "rc " + str_rl +" "+ str_fb +" "+ str_updw +" "+ str_yaw;
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::speed(){
    string message = "speed?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::battery(){
    string message = "battey?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::time(){
    string message = "time?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::height(){
    string message = "height?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::temp(){
    string message = "temp?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::attitude(){
    string message = "attitude?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::baro(){
    string message = "baro?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::acceleration(){
    string message = "acceleration?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::tof(){
    string message = "tof?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::wifi(){
    string message = "wifi?";
    udpConnection.Send(message.c_str(), message.length());
}

//--------------------------------------------------------------
void ofxTello::receiveUpdate(){
    char udpMessage[1000];
    udpConnection.Receive(udpMessage,1000);
    receivedMessage = ofToString(udpMessage);
}

//--------------------------------------------------------------
string ofxTello::getReceiveMessage(){
    return receivedMessage;
    
}

void ofxTello::close(){
    udpConnection.Close();
}
