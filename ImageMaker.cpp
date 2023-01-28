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
    return 0;
}

int ImageMaker::GetHeight() {
    return 0;
}

void ImageMaker::SetWidth(int width) {

}

void ImageMaker::SetHeight(int height) {

}

int ImageMaker::GetPenRed() {
    return 0;
}

int ImageMaker::GetPenGreen() {
    return 0;
}

int ImageMaker::GetPenBlue() {
    return 0;
}

void ImageMaker::SetPenRed(int newR) {

}

void ImageMaker::SetPenGreen(int newG) {

}

void ImageMaker::SetPenBlue(int newB) {

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
