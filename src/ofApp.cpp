#include "ofApp.h"
#include "ofxGPIO.h"

GPIO gpio4;
string state_sensor;

//--------------------------------------------------------------
void ofApp::setup(){
    gpio4.setup("4");
    gpio4.export_gpio();
    gpio4.setdir_gpio("in");
    image1.load("image1.jpg");
    image2.load("image2.jpg");
    image3.load("image3.jpg");
    imageBlender = ImageBlender();
    imageBlender.backgroundImage = image2;
}

//--------------------------------------------------------------
void ofApp::update(){
   // gpio4.getval_gpio(state_sensor);
   // ofLog() << "motion: " << state_sensor;
   // sleep(1);
}

void ofApp::draw(){
    imageBlender.draw();
}

void ofApp::keyPressed(int key){
    imageBlender.blendImage(image1);
    //  image1.grabScreen(0 ,0 ,ofGetWidth() ,ofGetHeight());
    //  image1.save("rendered.png");
    //  ofSystem("raspistill -n -o images/image.jpg");
}

void ofApp::windowResized(int w, int h){
    
}
