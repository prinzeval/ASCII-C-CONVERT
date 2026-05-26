#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// struct to store image data
struct Image {
    int w = 0;
    int h = 0;
    std::vector<unsigned char> pixels;
};

// read ppm file from disk
bool read_ppm(const std::string& filepath, Image& img) {
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open PPM file: " << filepath << std::endl;
        return false;
    }

    std::string format;
    file >> format;
    if (format != "P6") {
        std::cerr << "Error: Only P6 PPM format is supported" << std::endl;
        return false;
    }

    // skip comments starting with #
    char c;
    file >> c;
    while (c == '#') {
        std::string dummy;
        std::getline(file, dummy);
        file >> c;
    }
    file.putback(c);

    // read width, height and max value
    int max_val;
    file >> img.w >> img.h >> max_val;
    if (max_val != 255) {
        std::cerr << "Error: Max pixel value must be 255" << std::endl;
        return false;
    }

    // skip the newline after header
    file.get();

    // 3 bytes per pixel (rgb)
    img.pixels.resize(img.w * img.h * 3);
    file.read(reinterpret_cast<char*>(img.pixels.data()), img.w * img.h * 3);
    
    if (!file) {
        std::cerr << "Error: Failed to read raw pixel data" << std::endl;
        return false;
    }

    file.close();
    return true;
}

int main(int argc, char* argv[]) {
    // make sure filename is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image.ppm> [output_width] [output_height]" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    Image img;
    
    if (!read_ppm(filename, img)) {
        return 1;
    }

    int out_w = (argc >= 3) ? std::stoi(argv[2]) : 80;
    int out_h = (argc >= 4) ? std::stoi(argv[3]) : 40;
    
    // ascii chars from dark to light
    const std::string palette = "@%#*+=-:. ";

    for (int y = 0; y < out_h; ++y) {
        for (int x = 0; x < out_w; ++x) {
            // map output coordinates to input coordinates
            int sy1 = y * img.h / out_h;
            int sy2 = std::max((y + 1) * img.h / out_h, sy1 + 1);
            int sx1 = x * img.w / out_w;
            int sx2 = std::max((x + 1) * img.w / out_w, sx1 + 1);

            float sum = 0;
            int count = 0;
            for (int sy = sy1; sy < sy2; ++sy) {
                for (int sx = sx1; sx < sx2; ++sx) {
                    int idx = (sy * img.w + sx) * 3;
                    float r = img.pixels[idx];
                    float g = img.pixels[idx + 1];
                    float b = img.pixels[idx + 2];
                    
                    // convert to grayscale using standard formula
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

    return 0;
}




