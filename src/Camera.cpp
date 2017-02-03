#include "Camera.hpp"

Camera::Camera() {

}

ofImage Camera::takePicture() {
    ofSystem("raspistill -n -o data/image_lol.jpg -w 1920 -h 1080");
    image.load("image_lol.jpg");
    return image;
}
