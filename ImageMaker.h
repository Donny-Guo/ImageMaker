//
// Assignment Created by Varick Erickson
//

#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

#include <string>
#include <cmath>
#include <fstream>

const int MAX_WIDTH = 800;
const int MAX_HEIGHT = 800;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };

using namespace std;

//  Please put your pre and post comments in this file. See page 139 in the textbook.

class ImageMaker
{
public:
    /*
     * Function: default constructor
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * Set width and height to 0, set initial pen color to (0,0,0)
     * Set every value in the image variable to 255
     */
    ImageMaker();
    ImageMaker(string filename);

    // Opens image with filename and stores information into
    void LoadImage(string filename);
    void SaveImage(string filename);

    // Size functions
    /*
     * Function: return the width of the image
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the width of the image
     */
    int GetWidth();

    /*
     * Function: return the height of the image
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the height of the image
     */
    int GetHeight();
    void SetWidth(int width);
    void SetHeight(int height);

    // Color functions
    /*
     * Function: return the red color value of the image
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the red color value of the image
     */
    int GetPenRed();

    /*
     * Function: return the green color value of the image
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the green color value of the image
     */
    int GetPenGreen();

    /*
     * Function: return the blue color value of the image
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the blue color value of the image
     */
    int GetPenBlue();
    void SetPenRed(int newR);
    void SetPenGreen(int newG);
    void SetPenBlue(int newB);

    // Drawing methods
    // These methods will use the current red, green, blue values of the pen
    void DrawPixel(int x, int y);
    void DrawRectangle(int x1, int y1, int x2, int y2);
    void DrawLine(int x1, int y1, int x2, int y2);

private:
    string magic;
    int width;
    int height;
    int pen_red;    // Used by draw functions
    int pen_green;  // Used by draw functions
    int pen_blue;   // Used by draw functions
    bool PointInBounds(int x, int y);  // Not a bad idea to implement

               //   x          y
    short image[MAX_WIDTH][MAX_HEIGHT][3];
};

#endif //IMAGEMAKER_H
