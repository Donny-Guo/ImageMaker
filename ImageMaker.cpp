#include "ImageMaker.h"
#include <fstream>
#include <iostream>
using namespace std;
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
    ImageMaker();
    LoadImage(filename);
}

void ImageMaker::LoadImage(string filename) {
    // open an existing ppm image file
    ifstream inFile;
    inFile.open(filename);
    if (inFile.fail()){
        throw "File failed to open";
    }

    // store data into class ImageMaker
    // read magic string
    string s;
    getline(inFile, s);
    if (s != "P3"){
        throw "Bad magic number";
    }

    // read width, height, and max color value
    int width, height, max_color;
    inFile >> width >> height >> max_color;
    // set width, height
    SetWidth(width);
    SetHeight(height);
    // check max_color
    if (max_color != 255){
        throw "Max color range not 255";
    }

    // read pixel data
    // For each x, y coordinate
    for (int h = 0; h != GetWidth(); h++){
        for (int w = 0; w != GetHeight(); w++){
            int newR, newG, newB;
            // read RGB data
            inFile >> newR >> newG >> newB;
            // check RGB value
            if (newR < 0 || newR >255 || newG < 0 || newG >255 || newB < 0 || newB >255 ){
                throw "Color value invalid";
            }
            // Set the pixel color
            image[w][h][0] = newR;
            image[w][h][1] = newG;
            image[w][h][2] = newB;
        }
    }

    // finish reading file
    inFile.close();
}

void ImageMaker::SaveImage(string filename) {
    ofstream outFile;
    outFile.open(filename);
    // write magic number to file
    outFile << "P3\n";
    // check width and height value
    if (GetWidth() == 0 || GetHeight() == 0){
        throw "Image must have non-zero dimensions";
    }
    // write width and height to file
    outFile << GetWidth() << " " << GetHeight() << endl;
    // write max color value
    outFile << MAX_COLOR << endl;
    // write pixel data
    // For each x, y coordinate
    for (int h = 0; h != GetWidth(); h++){
        for (int w = 0; w != GetHeight(); w++){
            // write the pixel color
            outFile << image[w][h][0] << " ";
            outFile << image[w][h][1] << " ";
            outFile << image[w][h][2] << " ";
        }
        outFile << "  " << endl;
    }

    // finish writing file
    outFile.close();
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
        throw  "Color value invalid";
    }
    this->pen_red = newR;
}

void ImageMaker::SetPenGreen(int newG) {
    if (newG < 0 || newG > MAX_COLOR){
        throw  "Color value invalid";
    }
    this->pen_green = newG;
}

void ImageMaker::SetPenBlue(int newB) {
    if (newB < 0 || newB > MAX_COLOR){
        throw  "Color value invalid";
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
