#include "Cub.h"


uint64_t Cub::return_density(material mat_)
{
    uint64_t return_value;
    switch (mat_)
    {
    case metal:
        return_value = Body::METAL_DENSITY;
        break;

    case wood:
        return_value = Body::WOOD_DENSITY;
        break;

    case plastic:
        return_value = Body::PLASTIC_DENSITY;
        break;
    
    case cardboard:
        return_value = Body::CARDBOARD_DENSITY;
        break;
    
    default:
        throw std::runtime_error("неправильное засовываение return_density");
        break;
    }

    return return_value;
}

Cub::Cub(double rebro, material mat)
{
    this->material_ = mat;
    this->shape_ = cub;

    this->length_z_ = rebro;
    this->length_x_ = rebro;
    this->length_y_ = rebro;

    this->velocity_ = rebro * rebro * rebro;
    this->power_ = velocity_ * return_density(mat) * 9.81; 
    this->square_osn_ = rebro * rebro;
    this->square_bok_ = 4 * rebro * rebro;
    this->square_full_ = 2 * this->square_osn_ + square_bok_;

}


void Cub::move(double x_move_value, double y_move_value, double z_move_value)
{
    this->x_coordinate += x_move_value;
    this->y_coordinate += y_move_value;
    this->z_coordinate += z_move_value;
}

void Cub::resize(axis axs, double resize_value)
{
    switch (axs)
    {
    case x_axis:
        this->length_x_ > resize_value ?
        this->length_x_ -= resize_value :
        this->length_x_ = abs(this->length_x_ - resize_value); //суда можно сунуть троу

        break;
    
    case y_axis:
        this->length_y_ > resize_value ?
        this->length_y_ -= resize_value :
        this->length_y_ = abs(this->length_y_ - resize_value); //суда можно сунуть троу

        break;
    
    case z_axis:
        this->length_z_ > resize_value ?
        this->length_z_ -= resize_value :
        this->length_z_ = abs(this->length_z_ - resize_value); //суда можно сунуть троу

        break;
    
    default:
        break;
    }
}

