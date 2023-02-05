#include "ImageMaker.h"
#include <fstream>
#include <iostream>
using namespace std;
// Your code goes here...
ImageMaker::ImageMaker():
    ImageMaker(""){} // Using constructor delegation
//    // set private variable to 0
//    width = 0;
//    height = 0;
//    pen_red = 0;
//    pen_green = 0;
//    pen_blue = 0;
//    // Set every value in the image variable to 255
//    for (int w = 0; w != MAX_WIDTH; w++){
//        for (int h = 0; h != MAX_HEIGHT; h++){
//            for (int i = 0; i != 3; i++){
//                image[w][h][i] = 255;
//            }
//        }
//    }
//
//    // set string magic to P3 ???


ImageMaker::ImageMaker(string filename) {
    // set private variable to 0
    width = 0;
    height = 0;
    pen_red = 0;
    pen_green = 0;
    pen_blue = 0;
    magic = "P3";
    // Set every value in the image variable to 255
    for (int w = 0; w != MAX_WIDTH; w++){
        for (int h = 0; h != MAX_HEIGHT; h++){
            for (int i = 0; i != 3; i++){
                image[w][h][i] = 255;
            }
        }
    }
    if (filename != ""){
        LoadImage(filename);
    }
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
    for (int h = 0; h != GetHeight(); h++){
        for (int w = 0; w != GetWidth(); w++){
            int newR, newG, newB;
            // read RGB data
            inFile >> newR >> newG >> newB;
            // check RGB value
            if (newR < 0 || newR >255 || newG < 0 || newG >255 || newB < 0 || newB >255 ){
                throw "Color value invalid";
            }
            // Set the pixel color
            image[w][h][RED] = newR;
            image[w][h][GREEN] = newG;
            image[w][h][BLUE] = newB;
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
    for (int h = 0; h != GetHeight(); h++){
        for (int w = 0; w != GetWidth(); w++){
            // write the pixel color
            outFile << image[w][h][RED] << " ";
            outFile << image[w][h][GREEN] << " ";
            outFile << image[w][h][BLUE] << " ";
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
    // check if input x,y are valid coordinate values
    if (!PointInBounds(x,y)){ // if not valid
        throw "Point out of bounds"; // throw error message
    }
    // draw the pixel
    image[x][y][RED] = GetPenRed();
    image[x][y][GREEN] = GetPenGreen();
    image[x][y][BLUE] = GetPenBlue();

}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {
    // check for input value
    if (!PointInBounds(x1,y1) || !PointInBounds(x2,y2)){
        throw "Point out of bounds";
    }

    // Draw line from (x1,y1) to (x1,y2)
    DrawLine(x1,y1,x1,y2);

    // Draw line from (x1,y2) to (x2,y2)
    DrawLine(x1,y2,x2,y2);

    // Draw line from (x2,y2) to (x2,y1)
    DrawLine(x2,y2,x2,y1);

    // Draw line from (x2,y1) to (x1,y1)
    DrawLine(x2,y1,x1,y1);

}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {
    // check for input value
    if (!PointInBounds(x1,y1) || !PointInBounds(x2,y2)){
        throw "Point out of bounds";
    }

    if (x1 == x2){ // if x coordinates are the same
        int y_min = min(y1,y2); // get the minimum of y1 and y2
        int y_max = max(y1,y2); // get the maximum of y1 and y2
        for (int y = y_min; y <= y_max; y++) {
            DrawPixel(x1, y); // draw line
        }
        return;
    } else if (y1 == y2){ // if y coordinates are the same
        int x_min = min(x1,x2); // get the minimum of x1 and x2
        int x_max = max(x1,x2); // get the maximum of x1 and x2
        for (int x = x_min; x <= x_max; x++){
            DrawPixel(x, y1); // draw line
        }
    } else { // x1 != x2 and y1 != y2
        // calculate coefficient m and b (y = m*x + b)
        double m = 1.00 * (y2 - y1) / (x2 - x1);
        double b = y1 - m * x1;

        int x_min = min(x1, x2); // get the minimum of x1 and x2
        int x_max = max(x1, x2); // get the maximum of x1 and x2
        // drawline
        for (int x = x_min; x <= x_max; x++) {
            DrawPixel(x, round(m * x + b)); // draw line
        }
    }
}

bool ImageMaker::PointInBounds(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height){
        return false;
    }
    return true;
}
