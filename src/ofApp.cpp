#include "ofApp.h"
#include "ofxGPIO.h"

GPIO gpio4;
string state_sensor;
int flashCounter = 0;

void ofApp::setup() {
    gpio4.setup("4");
    gpio4.export_gpio();
    gpio4.setdir_gpio("in");
    image1.load("image_lol.jpg");
    imageBlender = ImageBlender();
    imageBlender.backgroundImage = image1;
}

void ofApp::update() {
    imageBlender.update();
    gpio4.getval_gpio(state_sensor);
    if (state_sensor == "1") {
        takePicture();
    }
    ofLog() << "motion: " << state_sensor;
}

void ofApp::draw() {
    imageBlender.draw();
    if (flashCounter > 0 && flashCounter < 5) {
        ofBackground(ofColor::white);
    }
    flashCounter -= 1;
}

void ofApp::takePicture() {
    if (cameraThread.isThreadRunning()) {
        ofLog() << "is running";
        return;
    }
    flashCounter = 10;
//    glutTimerFunc(1000, setShowFlash, false);
    cameraThread.delegate = &imageBlender;
    cameraThread.startThread();
}

void ofApp::keyPressed(int key) {
    //  image1.grabScreen(0 ,0 ,ofGetWidth() ,ofGetHeight());
    //  image1.save("rendered.png");
    takePicture();
}

void ofApp::windowResized(int w, int h) {
    
}
