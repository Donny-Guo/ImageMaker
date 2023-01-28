#include "ImageMaker.h"

// Your code goes here...
ImageMaker::ImageMaker() {
    // set private variable to 0
    width = 0;
    height = 0;
    pen_red = 0;
    pen_green = 0;
    pen_blue = 0;
    // Set every value in the image variable to 255
    for (int w = 0; w != MAX_WIDTH; w++){
        for (int h = 0; h != MAX_HEIGHT; h++){
            for (int i = 0; i != 3; i++){
                image[w][h][i] = 255;
            }
        }
    }

    // set string magic to P3 ???
}

ImageMaker::ImageMaker(string filename) {

}

void ImageMaker::LoadImage(string filename) {

}

void ImageMaker::SaveImage(string filename) {

}

int ImageMaker::GetWidth() {
    return width;
}

int ImageMaker::GetHeight() {
    return height;
}

void ImageMaker::SetWidth(int width) {
    if (width < 0 || width > MAX_WIDTH){
        throw  "Width out of bounds";
    }
    this->width = width;
}

void ImageMaker::SetHeight(int height) {
    if (height < 0 || height > MAX_HEIGHT){
        throw  "Height out of bounds";
    }
    this->height = height;
}

int ImageMaker::GetPenRed() {
    return pen_red;
}

int ImageMaker::GetPenGreen() {
    return pen_green;
}

int ImageMaker::GetPenBlue() {
    return pen_blue;
}

void ImageMaker::SetPenRed(int newR) {
    if (newR < 0 || newR > MAX_COLOR){
        throw  "Max color range not 255";
    }
    this->pen_red = newR;
}

void ImageMaker::SetPenGreen(int newG) {
    if (newG < 0 || newG > MAX_COLOR){
        throw  "Max color range not 255";
    }
    this->pen_green = newG;
}

void ImageMaker::SetPenBlue(int newB) {
    if (newB < 0 || newB > MAX_COLOR){
        throw  "Max color range not 255";
    }
    this->pen_blue = newB;
}

void ImageMaker::DrawPixel(int x, int y) {

}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {

}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {

}

bool ImageMaker::PointInBounds(int x, int y) {
    return false;
}
