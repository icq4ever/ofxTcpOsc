#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    receiver.setup(port);
}

//--------------------------------------------------------------
void ofApp::update(){
    while (receiver.hasWaitingMessages()) {
        ofxTcpOscMessage m;
        receiver.getNextMessage(&m);
        
        cout << "message from " << m.getRemoteIp() << ", " << m.getRemotePort() << ", " << m.getAddress() << endl;
        
        if (m.getAddress() == "/mousePressed") {
            string strx = m.getArgAsString(0);
            int xpos = m.getArgAsInt32(1);
            string stry = m.getArgAsString(2);
            uint64_t ypos = m.getArgAsInt32(3);
            string strframerate = m.getArgAsString(4);
            float framerate = m.getArgAsFloat(5);
            
            cout << strx << " " << xpos << " " << stry << " " << ypos << " " << strframerate << " " << framerate << endl;
        } else {
            for (int i=0; i<m.getNumArgs(); i++) {
                cout << m.getArgTypeName(i) << ": ";
                ofxTcpOscArgType argType = m.getArgType(i);
                if (argType == OFXTCPOSC_TYPE_INT32) {
                    cout << m.getArgAsInt32(i);
                } else if (argType == OFXTCPOSC_TYPE_INT64) {
                    cout << m.getArgAsInt64(i);
                } else if (argType == OFXTCPOSC_TYPE_FLOAT) {
                    cout << m.getArgAsFloat(i);
                } else if (argType == OFXTCPOSC_TYPE_STRING) {
                    cout << m.getArgAsString(i);
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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