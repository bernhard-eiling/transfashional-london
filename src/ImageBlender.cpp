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

void ImageBlender::didTakePicture(ofImage image) {
    tempImage = image;
}

void ImageBlender::blendImage(ofImage image) {
    foregroundImage = image;
    scaleForegroundImage = 1.2;
}

void ImageBlender::update() {
    if (tempImage.isAllocated()) {
//        foregroundImage = tempImage;
        backgroundImage = tempImage;
        tempImage.clear();
    }
    
    if (scaleForegroundImage > 1.0) {
        scaleForegroundImage *= 0.995;
    }
    if (scaleForegroundImage < 1.0) {
        scaleForegroundImage = 1.0;
    }
}

void ImageBlender::draw() {
    ImagePoint position = imageUtils.getImagePosition(backgroundImage);
    ImageSize size = imageUtils.getImageSize(backgroundImage);
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    float width =  size.width * scaleForegroundImage;
    float height = size.height * scaleForegroundImage;
    float xPos = (position.x - width / 2) + size.width / 2.0;
    float yPos = (position.y - height / 2) + size.height / 2.0;
    backgroundImage.draw(position.x, position.y, size.width, size.height);
    if (foregroundImage.isAllocated()) {
        foregroundImage.draw(xPos, yPos, width, height);
    }
    ofDisableBlendMode();
}

