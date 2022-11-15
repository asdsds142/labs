//Cub.h
#pragma once
#include "Body.h"

class Cub : public Body
{
  private:
    int64_t x_coordinate = NULL;
    int64_t y_coordinate = NULL;
    int64_t z_coordinate = NULL;

    shape shape_ = cub;
    material material_;

    void recalculate_();
  public: 
    enum axis {x_axis, y_axis, z_axis};
    
    Cub(int64_t, material);  

    int64_t square();
    int64_t square_bok();
    int64_t square_osn();

    void resize(axis, int64_t);
    void print(int64_t = 0, int64_t = 0, int64_t = 0);
    void move(int64_t, int64_t, int64_t);

    

};