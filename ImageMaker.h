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

    /*
     * Function: constructor (initialized image with input file)
     *
     * Precondition:
     * input filename is valid
     *
     * Postcondition:
     * initialized an image and set image data based on input file
     * throw error message if file not open or value invalid
     */
    ImageMaker(string filename);

    // Opens image with filename and stores information into
    /*
     * Function: open an existing ppm image file and store data into private variables
     *
     * Precondition:
     * the input filename is valid (can open)
     *
     * Postcondition:
     * store data into img
     * throw error message when input data out of bound
     */
    void LoadImage(string filename);

    /*
     * Function: constructs a ppm image
     *
     * Precondition:
     * the input filename is initialized
     * the ImageMaker object is initialized
     *
     * Postcondition:
     * Create a ppm image based on private variables and filename
     * Throw "Image must have non-zero dimensions" if width or height is 0
     */
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
     * else throw "Color value invalid" message for bad values
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
     * else throw "Color value invalid" message for bad values
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
     * else throw "Color value invalid" message for bad values
     */
    void SetPenBlue(int newB);

    // Drawing methods
    // These methods will use the current red, green, blue values of the pen
    /*
     * Function: draw a pixel at coordinate (x,y) using current pen color
     *
     * Precondition:
     * ImageMaker object is initialized
     * The input x,y should be valid (if not, throw "Point out of bounds" error message)
     *
     * Postcondition:
     * draw a pixel on the image at coordinate (x,y) with current pen color
     */
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
