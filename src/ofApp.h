#pragma once

#include "ofMain.h"
#include "ImageBlender.hpp"
#include "CameraThread.h"
#include "Camera.hpp"

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
    void blendImages();
    CameraThread cameraThread;
    Camera camera;
    
};
