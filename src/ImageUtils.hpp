//
//  ImageUtils.hpp
//  emptyExample
//
//  Created by Bernhard Eiling on 28.01.17.
//
//

#ifndef ImageUtils_hpp
#define ImageUtils_hpp

#include "ofMain.h"
#include "ofImage.h"

struct ImagePoint {
    float x;
    float y;
};

struct ImageSize {
    float width;
    float height;
};

class ImageUtils {
    
public:
    ImagePoint getImagePosition(ofImage image);
    ImageSize getImageSize(ofImage image);
    ofImage setAlphaChannel(ofImage image, int value);
    
private:
    float getScale(ofImage image);
    
};

#endif /* ImageUtils_hpp */
