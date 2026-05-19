#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_image> [width_chars] [height_chars]\n";
        std::cerr << "Example: " << argv[0] << " photo.jpg 100 40\n";
        return 1;
    }

    std::string filename = argv[1];
    int w, h, channels;
    
    // Load image using stb_image (automatically handles PNG, JPEG, BMP, etc.)
    unsigned char* img_data = stbi_load(filename.c_str(), &w, &h, &channels, 0);
    if (!img_data) {
        std::cerr << "Error: Failed to load image '" << filename << "'\n";
        std::cerr << "Reason: " << stbi_failure_reason() << "\n";
        return 1;
    }

    int out_w = argc >= 3 ? std::stoi(argv[2]) : 80;
    int out_h = argc >= 4 ? std::stoi(argv[3]) : 40;
    
    // Standard ASCII palette ranging from densest/darkest to sparsest/lightest
    const std::string palette = "@%#*+=-:. ";

    for (int y = 0; y < out_h; ++y) {
        for (int x = 0; x < out_w; ++x) {
            int sy1 = y * h / out_h;
            int sy2 = std::max((y + 1) * h / out_h, sy1 + 1);
            int sx1 = x * w / out_w;
            int sx2 = std::max((x + 1) * w / out_w, sx1 + 1);

            float sum = 0;
            int count = 0;
            for (int sy = sy1; sy < sy2; ++sy) {
                for (int sx = sx1; sx < sx2; ++sx) {
                    int idx = (sy * w + sx) * channels;
                    float r = img_data[idx];
                    float g = (channels >= 2) ? img_data[idx + 1] : r;
                    float b = (channels >= 3) ? img_data[idx + 2] : r;
                    
                    // Rec. 601 grayscale conversion formula
                    sum += 0.299f * r + 0.587f * g + 0.114f * b;
                    count++;
                }
            }
            float avg = sum / count;
            int palette_idx = static_cast<int>(avg * (palette.size() - 1) / 255.0f);
            std::cout << palette[palette_idx];
        }
        std::cout << '\n';
    }

    stbi_image_free(img_data);
    return 0;
}
