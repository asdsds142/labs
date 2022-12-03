#include "header.h"


//конструктор ввода с клавиатуры
Phone::Phone()
{
    tools::try_input(cin, this->surname_, "Введите фамилию\n");
    tools::try_input(cin, this->name_, "Введите имя\n");
    tools::try_input(cin, this->father_name_, "Введите отчество\n");
    tools::try_getline(cin, this->adress_, "Введите адрес\n");
    tools::try_input(cin, this->number_, "Введите номер\n");
    tools::try_input(cin, this->incity_time_, "Введите время внутригородних разговоров\n");
    tools::try_input(cin, this->intercity_time_, "Введите время междугородних разговоров\n");
}


Phone::Phone(ifstream& file_stream)
{ 
    tools::try_getline(file_stream, this->surname_);
    tools::try_getline(file_stream, this->name_);
    tools::try_getline(file_stream, this->father_name_);
    tools::try_getline(file_stream, this->adress_);

    file_stream >> this->number_ >> this->incity_time_ >> this->intercity_time_;
}


Phone::Phone(string surname, string name, string father_name, string adress, 
                long number, long incity_t, long intercity_t): 
surname_(surname), name_(name), father_name_(father_name), adress_(adress), 
number_(number), incity_time_(incity_t), intercity_time_(intercity_t) {}


string Phone::get_adress(){return this->adress_;}

string Phone::get_surname() {return this->surname_;}

string Phone::get_name() {return this->name_;}

string Phone::get_father_name() {return this->father_name_;}

long Phone::get_number() {return this->number_;}

long Phone::get_incity_time() {return this->incity_time_;}

long Phone::get_intercity_time() {return this->intercity_time_;}

void Phone::set_adress(string a) {this->adress_ = a;}

void Phone::set_name(string a) {this->name_ = a;}

void Phone::set_surname(string a) {this->surname_ = a;}

void Phone::set_father_name(string a) {this->surname_ = a;}

void Phone::set_number(long a) {this->number_ = a;}

void Phone::set_incity_time(long a) {this->incity_time_ = a;}

void Phone::set_intercity_time(long a) {this->intercity_time_ = a;}


void Phone::show()
{
    cout << "Имя: " << this->surname_ << " " 
    << this->name_ << " " << this->father_name_ << endl;
    cout << "Адрес: " << this->adress_ << endl;
    cout << "Номер: " << this->number_ << endl;
    cout << "Время внутригородних разговоров: " << this->incity_time_ << endl;
    cout << "Время междугородних разговоров: " << this->intercity_time_ << endl;

}

void Phone::to_file(ofstream& file_stream)
{

    file_stream << surname_ << endl << name_ << endl << father_name_ << endl 
    << adress_ << endl << number_ << endl << incity_time_ << endl 
    << intercity_time_ << endl;
    
}

void Phone::add_incity_call_time(long a) {this->incity_time_ += a;}

void Phone::add_intercity_call_time(long a) {this->intercity_time_ += a;}

