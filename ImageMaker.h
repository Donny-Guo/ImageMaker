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

    /*
     * Function: set the width of the image
     *
     * Precondition:
     * the input width is initialized
     *
     * Postcondition:
     * set the width of the image if it is within 0 and MAX_WIDTH (inclusive)
     * else throw "Width out of bounds" message for bad values
     */
    void SetWidth(int width);

    /*
     * Function: set the height of the image
     *
     * Precondition:
     * the input height is initialized
     *
     * Postcondition:
     * set the height of the image if it is within 0 and MAX_HEIGHT (inclusive)
     * else throw "Height out of bounds" message for bad values
     */
    void SetHeight(int height);

    // Color functions
    /*
     * Function: return the red color value of the pen
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the red color value of the image
     */
    int GetPenRed();

    /*
     * Function: return the green color value of the pen
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the green color value of the image
     */
    int GetPenGreen();

    /*
     * Function: return the blue color value of the pen
     *
     * Precondition:
     * None
     *
     * Postcondition:
     * return the blue color value of the image
     */
    int GetPenBlue();

    /*
     * Function: set the red color value of the pen
     *
     * Precondition:
     * the input red color value is initialized
     *
     * Postcondition:
     * set the red color value of the pen if the input is within 0 and MAX_COLOR (inclusive)
     * else throw "Max color range not 255" message for bad values
     */
    void SetPenRed(int newR);

    /*
     * Function: set the green color value of the pen
     *
     * Precondition:
     * the input green color value is initialized
     *
     * Postcondition:
     * set the green color value of the pen if the input is within 0 and MAX_COLOR (inclusive)
     * else throw "Max color range not 255" message for bad values
     */
    void SetPenGreen(int newG);

    /*
     * Function: set the blue color value of the pen
     *
     * Precondition:
     * the input blue color value is initialized
     *
     * Postcondition:
     * set the blue color value of the pen if the input is within 0 and MAX_COLOR (inclusive)
     * else throw "Max color range not 255" message for bad values
     */
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
