#include "image.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    // check if image file is given
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image.png> [output_width] [output_height]" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    
    // sorry sir i updated to use the supplied image.h library that you provided, i forgot to use it after my test on stb_image.h
    ColorImage col_img;
    col_img.Load(filename);
    
    if (col_img.GetWidth() == 0 || col_img.GetHeight() == 0) {
        std::cerr << "Error: Failed to load image " << filename << std::endl;
        return 1;
    }

    // convert to grayscale image
    GrayscaleImage img(col_img);

    int out_w = (argc >= 3) ? std::stoi(argv[2]) : 80;
    int out_h = (argc >= 4) ? std::stoi(argv[3]) : 40;
    
    // ascii chars from dark to light
    const std::string palette = "@%#*+=-:. ";

    for (int y = 0; y < out_h; ++y) {
        for (int x = 0; x < out_w; ++x) {
            // map output coordinates to input coordinates
            int sy1 = y * img.GetHeight() / out_h;
            int sy2 = std::max((y + 1) * img.GetHeight() / out_h, sy1 + 1);
            int sx1 = x * img.GetWidth() / out_w;
            int sx2 = std::max((x + 1) * img.GetWidth() / out_w, sx1 + 1);

            float sum = 0;
            int count = 0;
            for (int sy = sy1; sy < sy2; ++sy) {
                for (int sx = sx1; sx < sx2; ++sx) {
                    // get pixel value using () operator
                    float gray = img(sx, sy);
                    sum += gray;
                    count++;
                }
            }
            float avg = sum / count;
            int palette_idx = static_cast<int>(avg * (palette.size() - 1) / 255.0f);
            std::cout << palette[palette_idx];
        }
        std::cout << '\n';
    }

    return 0;
}





