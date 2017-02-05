#include "ofThread.h"
#include "ImageBlender.hpp"

class CameraThread: public ofThread {
    
    
public:
    
    ImageBlender* delegate;
    
    CameraThread() {
        
    }
    
    void threadedFunction() {
        ofSystem("raspistill -n -o data/image_camera.png -w 1920 -h 1080");
        ofImage image;
        image.load("image_camera.png");
        delegate->didTakePicture(image);
    }
    
};
