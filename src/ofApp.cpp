#include "ofApp.h"
#include "ofxGPIO.h"

GPIO gpio4;
string state_sensor;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    gpio4.setup("4");
    gpio4.export_gpio();
    gpio4.setdir_gpio("in");
}

//--------------------------------------------------------------
void ofApp::update(){
    gpio4.getval_gpio(state_sensor);
    ofLog() << "motion: " << state_sensor;
    sleep(1);
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofBackground(255,0,255);
    ofSystem("raspistill -n -o images/image.jpg");
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
