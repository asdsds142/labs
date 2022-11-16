//Cub.h
#pragma once
#include "Body.h"

class Cub : public Body
{
  private:
    double x_coordinate = 0.0;
    double y_coordinate = 0.0;
    double z_coordinate = 0.0;

    void recalculate_();
    uint64_t return_density(material);
  public: 
    enum axis {x_axis, y_axis, z_axis};
    
    Cub(double, material);  //

    double square() {return this->square_full_;} //
    double square_bok() {return this->square_bok_;} //
    double square_osn() {return this->square_osn_;} //

    void resize(axis, double); //
    void print(double = 0, double = 0, double = 0); //потом может графику прикручу пока делать не буду, по ТЗ в 1 строчку функция
    void move(double, double, double); //

};