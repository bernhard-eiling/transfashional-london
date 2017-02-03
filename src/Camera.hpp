#include "ofImage.h"

#ifndef Camera_hpp
#define Camera_hpp

class Camera {
    
public:
    Camera();
    ofImage takePicture();
    
private:
    ofImage image;
    
};

#endif
