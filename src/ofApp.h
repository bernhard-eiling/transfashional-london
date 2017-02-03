#pragma once

#include "ofMain.h"
#include "ImageBlender.hpp"
#include "CameraThread.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void windowResized(int w, int h);
    
private:
    ofImage demo;
    ofImage image1;
    ofImage image2;
    ofImage image3;
    ImageBlender imageBlender;
    void blendImages();
    CameraThread cameraThread;
    
};
