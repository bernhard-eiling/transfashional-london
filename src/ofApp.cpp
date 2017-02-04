#include "ofApp.h"
#include "ofxGPIO.h"
#include <stdio.h>

GPIO gpio4;
string state_sensor;

void ofApp::setup() {
    gpio4.setup("4");
    gpio4.export_gpio();
    gpio4.setdir_gpio("in");
    image1.load("image1.jpg");
    imageBlender = ImageBlender();
    imageBlender.backgroundImage = image1;
    
//    camera = Camera();
//    camera.delegate = &imageBlender;
}

void ofApp::update() {
    imageBlender.update();
    gpio4.getval_gpio(state_sensor);
    if (state_sensor == "1") {
        
    }
//    ofLog() << "motion: " << state_sensor;
}

void ofApp::draw() {
    imageBlender.draw();
}


void ofApp::keyPressed(int key) {
    //  image1.grabScreen(0 ,0 ,ofGetWidth() ,ofGetHeight());
    //  image1.save("rendered.png");
    cameraThread.delegate = &imageBlender;
    cameraThread.startThread();
}

void ofApp::windowResized(int w, int h) {
    
}
