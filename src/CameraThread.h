#include "ofThread.h"
#include "Camera.hpp"
#include "ImageBlender.hpp"

class CameraThread: public ofThread {
    
    
public:
    
    ImageBlender* delegate;
    
    CameraThread() {
        
    }
    
    void threadedFunction() {
        ofSystem("raspistill -n -o data/image_lol.jpg -w 1920 -h 1080");
        ofImage image;
        image.load("image_lol.jpg");
        delegate->didTakePicture(image);
    }
    
};
