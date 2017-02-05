//
//  ImageUtils.cpp
//  emptyExample
//
//  Created by Bernhard Eiling on 28.01.17.
//
//

#include "ImageUtils.hpp"

ImagePoint ImageUtils::getImagePosition(ofImage image) {
    ImagePoint point = {};
    ImageSize size = getImageSize(image);
    point.x = ofGetWidth() / 2.0 - size.width / 2.0;
    point.y = ofGetHeight() / 2.0 - size.height / 2.0;
    return point;
}

ImageSize ImageUtils::getImageSize(ofImage image) {
    ImageSize size = {};
    float scale = getScale(image);
    size.width = image.getWidth() * scale;
    size.height = image.getHeight() * scale;
    return size;
}

float ImageUtils::getScale(ofImage image) {
    if (image.getWidth() > image.getHeight()) {
        return ofGetWidth() / image.getWidth();
    } else {
        return ofGetHeight() / image.getHeight();
    }
}

ofImage ImageUtils::setAlphaChannel(ofImage image, int value) {
    image.setImageType(OF_IMAGE_COLOR_ALPHA);
    int w = image.getWidth();
    int h = image.getHeight();
    ofPixels & pixels = image.getPixels();
    ofPixels alphaPixels;
    alphaPixels.allocate(w, h, OF_IMAGE_GRAYSCALE);
    ofColor greyColor;
    greyColor.set(value);
    alphaPixels.setColor(greyColor);
    pixels.setChannel(3, alphaPixels);
    image.setFromPixels(pixels);
    return image;
}
