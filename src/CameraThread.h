#include "ofThread.h"
#include "Camera.hpp"
#include "ImageBlender.hpp"

class CameraThread: public ofThread {
    
    
public:
    
    ImageBlender delegate;
    
    CameraThread() {
        
    }
    
    void threadedFunction() {
        Camera camera = Camera();
        ofImage image = camera.takePicture();
        delegate.didTakePicture(image);
    }
    
};
