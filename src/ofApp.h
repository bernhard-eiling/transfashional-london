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
    ofImage image1;
    ImageBlender imageBlender;
    CameraThread cameraThread;
    void blendImages();
    void takePicture();
    
};
