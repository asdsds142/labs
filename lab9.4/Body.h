#pragma once


#include <iostream>
#include <vector>
#include <string>


class Body
{
    
  protected:
    enum shape {shar, prisma, parallelepiped, cub, piramida, conus, cylinder};
    enum  material { metal, wood, plastic, cardboard };

    static constexpr uint64_t METAL_DENSITY = 5.5;
    static constexpr uint64_t WOOD_DENSITY = 1.1;
    static constexpr uint64_t PLASTIC_DENSITY = 0.7;
    static constexpr uint64_t CARDBOARD_DENSITY = 2.5;


    shape shape_;
    material material_;

    double length_z_;
    double length_x_;
    double length_y_;

    double square_osn_;
    double square_bok_;
    double square_full_;
    double velocity_;
    double power_;

    Body() = default;

  public:
    virtual double Square_osn() = 0;
    virtual double Square_bok() = 0;
    virtual double Velocity() = 0;

    virtual ~Body() = 0;
};

Body::~Body() {}