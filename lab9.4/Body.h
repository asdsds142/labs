#pragma once


#include <iostream>
#include <vector>
#include <string>


class Body
{
  protected:
    enum shape {shar, prisma, parallelepiped, cub, piramida, conus, cylinder};
    int64_t radius_;
    int64_t height_z_;
    int64_t rebro_x_;
    int64_t rebro_y_;
    int64_t square_osn_;
    int64_t square_bok_;
    int64_t square_full_;
    int64_t velocity_;
    int64_t power_;
    enum  material { metal, wood, plastic, cardboard };

};