#include <iostream>
#include <fstream>
#include <string>
#include "bitmap_image.hpp"

using namespace std;

class MapCard
{
public:
    void bitMatrix()
    {
        bitmap_image image("img.bmp");

        if (!image)
        {
            cout << "Error - Failed to open: input.bmp\n";
            return;
        }

        const unsigned int height = image.height();
        const unsigned int width  = image.width();

        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                rgb_t colour;

                image.get_pixel(x, y, colour);

                if(colour.red <= 128 && colour.green <= 128 && colour.blue <= 128)
                {
                    colour.red = 0;
                    colour.green = 0;
                    colour.blue = 0;
                }
                else
                {
                    colour.red = 255;
                    colour.green = 255;
                    colour.blue = 255;
                }

                image.set_pixel(x,y,colour);
            }
        }

        image.save_image("output.bmp");

    }

    void byteMatrix()
    {
        bitmap_image image("me.bmp");

        if (!image)
        {
            cout << "Error - Failed to open: input.bmp\n";
            return;
        }

        const unsigned int height = image.height();
        const unsigned int width  = image.width();

        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                rgb_t colour;

                image.get_pixel(x, y, colour);
                /*
                if(colour.red == 0 && colour.green == 0 && colour.blue == 0)
                {
                    continue;
                }
                */
                if (colour.red <= 25 && colour.green <= 25 && colour.blue <= 25)
                {
                    colour.red = 25;
                    colour.green = 25;
                    colour.blue = 25;
                }
                else if (colour.red <= 44 && colour.green <= 44 && colour.blue <= 44)
                {
                    colour.red = 44;
                    colour.green = 44;
                    colour.blue = 44;
                }
                else if (colour.red <= 63 && colour.green <= 63 && colour.blue <= 63)
                {
                    colour.red = 63;
                    colour.green = 63;
                    colour.blue = 63;
                }
                else if (colour.red <= 84 && colour.green <= 84 && colour.blue <= 84)
                {
                    colour.red = 84;
                    colour.green = 84;
                    colour.blue = 84;
                }
                else if (colour.red <= 106 && colour.green <= 106 && colour.blue <= 106)
                {
                    colour.red = 106;
                    colour.green = 106;
                    colour.blue = 106;
                }
                else if (colour.red <= 128 && colour.green <= 128 && colour.blue <= 128)
                {
                    colour.red = 128;
                    colour.green = 128;
                    colour.blue = 128;
                }
                else if (colour.red <= 148 && colour.green <= 148 && colour.blue <= 148)
                {
                    colour.red = 148;
                    colour.green = 148;
                    colour.blue = 148;
                }
                else if (colour.red <= 169 && colour.green <= 169 && colour.blue <= 169)
                {
                    colour.red = 169;
                    colour.green = 169;
                    colour.blue = 169;
                }
                else if (colour.red <= 189 && colour.green <= 190 && colour.blue <= 189)
                {
                    colour.red = 189;
                    colour.green = 190;
                    colour.blue = 189;
                }
                else if (colour.red <= 211 && colour.green <= 211 && colour.blue <= 211)
                {
                    colour.red = 211;
                    colour.green = 211;
                    colour.blue = 211;
                }
                else if (colour.red <= 233 && colour.green <= 233 && colour.blue <= 233)
                {
                    colour.red = 233;
                    colour.green = 233;
                    colour.blue = 233;
                }
                else
                {
                    colour.red = 255;
                    colour.green = 255;
                    colour.blue = 255;
                }

                image.set_pixel(x,y,colour);
            }
        }

        image.save_image("output.bmp");

    }

    void charsMatrix()
    {
        byteMatrix();

        bitmap_image image("output.bmp");

        ofstream fout;

        fout.open("result.txt");

        if (!image)
        {
            cout << "Error - Failed to open: output.bmp\n";
            return;
        }

        const unsigned int height = image.height();
        const unsigned int width  = image.width();


        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                rgb_t colour;

                image.get_pixel(x, y, colour);

                if(colour.red == 0 && colour.green == 0 && colour.blue == 0)
                {
                   fout << "@";
                }
                else if (colour.red <= 25 && colour.green <= 25 && colour.blue <= 25)
                {
                    fout << "#";
                }
                else if (colour.red <= 44 && colour.green <= 44 && colour.blue <= 44)
                {
                    fout << "$";
                }
                else if (colour.red <= 63 && colour.green <= 63 && colour.blue <= 63)
                {
                    fout << "|";
                }
                else if (colour.red <= 84 && colour.green <= 84 && colour.blue <= 84)
                {
                    fout << "&";
                }
                else if (colour.red <= 106 && colour.green <= 106 && colour.blue <= 106)
                {
                    fout << "*";
                }
                else if (colour.red <= 128 && colour.green <= 128 && colour.blue <= 128)
                {
                   fout << "w";
                }
                else if (colour.red <= 148 && colour.green <= 148 && colour.blue <= 148)
                {
                    fout << "0";
                }
                else if (colour.red <= 169 && colour.green <= 169 && colour.blue <= 169)
                {
                    fout << "+";
                }
                else if (colour.red <= 189 && colour.green <= 190 && colour.blue <= 189)
                {
                    fout << "-";
                }
                else if (colour.red <= 211 && colour.green <= 211 && colour.blue <= 211)
                {
                    fout << "x";
                }
                else if (colour.red <= 233 && colour.green <= 233 && colour.blue <= 233)
                {
                    fout << "?";
                }
                else
                {
                    fout << " ";
                }

                image.set_pixel(x,y,colour);
            }

            fout << "\n";
        }

        fout.close();
    }
};
int main()
{
    MapCard mapCard;
    mapCard.charsMatrix();

   return 0;
}
