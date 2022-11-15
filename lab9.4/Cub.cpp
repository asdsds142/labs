#include "Cub.h"


Cub::Cub(int64_t rebro, material mat)
{
    this->height_z_ = rebro;
    this->rebro_x_ = rebro;
    this->rebro_y_ = rebro;
    this->velocity_ = rebro * rebro * rebro;
    this->square_osn_ = rebro * rebro;
    this->square_bok_ = 4 * rebro * rebro;
    this->square_full_ = 2 * this->square_osn_ + square_bok_;
    this->material_ = mat;
}