//
//  ImageBlender.cpp
//  emptyExample
//
//  Created by Bernhard Eiling on 28.01.17.
//
//

#include "ImageBlender.hpp"
#include <stdio.h>

ImageBlender::ImageBlender() {
    imageUtils = ImageUtils();
    animating = false;
    scaleForegroundImage = 1.0;
}

void ImageBlender::blendImage(ofImage image) {
    foregroundImage = image;
    scaleForegroundImage = 1.2;
}

void ImageBlender::update() {
    
}

void ImageBlender::draw() {
    ImagePoint position = imageUtils.getImagePosition(backgroundImage);
    ImageSize size = imageUtils.getImageSize(backgroundImage);
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    backgroundImage.draw(position.x, position.y, size.width, size.height);
    foregroundImage.draw(position.x, position.y, size.width, size.height);
    ofDisableBlendMode();
}
