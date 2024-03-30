#include <cstdint>
#include <ctime>
#include <cstdlib>
#include "seq/mukhin_a_gaussian_filter/include/pixel_map.hpp"

void PixelMap::set_data(uint8_t r, uint8_t g, uint8_t b){
    std::srand(std::time(nullptr));
    data.resize(n * m);
    for (uint64_t i = 0; i < n * m; i++){
        data[i].r = 0;
        data[i].g = 0;
        data[i].b = 0;
    }
}

bool operator==(const Pixel& a, const Pixel& b){
    return (a.r == b.r && a.g == b.g && a.b == b.b);
}

PixelMap::PixelMap(uint64_t n_, uint64_t m_, uint8_t r, uint8_t g, uint8_t b){
    this->n = n_;
    this->m = m_;
    set_data(r, g, b);
}

Pixel& PixelMap::get_pixel(uint64_t i, uint64_t j){
    return this->data[i * width() + j];
}

const Pixel& PixelMap::get_pixel(uint64_t i, uint64_t j) const {
    return this->data[i * width() + j];
}

bool operator==(const PixelMap& a, const PixelMap& b){
    if (a.width() == b.width() && a.height() == b.height()){
        for (uint64_t i = 0; i < a.width() * a.height(); i++){
            if (a.data[i] != b.data[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}