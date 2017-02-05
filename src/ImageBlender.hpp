//
//  ImageBlender.hpp
//  emptyExample
//
//  Created by Bernhard Eiling on 28.01.17.
//
//

#ifndef ImageBlender_hpp
#define ImageBlender_hpp

#include "ofMain.h"
#include "ImageUtils.hpp"

class ImageBlender {
    
public:
    ImageBlender();
    ImageUtils imageUtils;
    ofImage backgroundImage;
    ofImage foregroundImage;
    void blendImage(ofImage image);
    void update();
    void draw();
    void didTakePicture(ofImage image);
    
private:
    ofImage tempImage;
    ofImage screenCaptureImage;
    bool animating;
    float scaleForegroundImage;
    float getXPosImages();
    float getYPosImages();
    ImageSize getImagesSize();
    void screenCapture();
    
};

#endif /* ImageBlender_hpp */
