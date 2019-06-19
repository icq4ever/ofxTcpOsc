#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    sender.setup(host, port);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        sender.setup(host, port);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofxTcpOscMessage m;
    m.setAddress("/mouseDragged");
    m.addStringArg("x, y: ");
    m.addIntArg(x);
    m.addInt64Arg(y);
    m.addFloatArg(ofGetFrameRate());
    
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofxTcpOscMessage m;
    m.setAddress("/mousePressed");
    m.addStringArg("x:");
    m.addIntArg(x);
    m.addStringArg("y:");
    m.addIntArg(y);
    m.addStringArg("frameRate:");
    m.addFloatArg(ofGetFrameRate());
    
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}