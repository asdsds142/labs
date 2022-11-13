#include "header.h"




//конструктор ввода с клавиатуры
Phone::Phone()
{
    try_input(cin, this->surname, "Введите фамилию\n");
    try_input(cin, this->name, "Введите имя\n");
    try_input(cin, this->father_name, "Введите отчество\n");
    try_getline(cin, this->adress, "Введите адрес\n");
    try_input(cin, this->number, "Введите номер\n");
    try_input(cin, this->incity_time, "Введите время внутригородних разговоров\n");
    try_input(cin, this->intercity_time, "Введите время междугородних разговоров\n");
}


Phone::Phone(ifstream& file_stream)
{ 
    try_getline(file_stream, this->surname);
    try_getline(file_stream, this->name);
    try_getline(file_stream, this->father_name);
    try_getline(file_stream, this->adress);

    file_stream >> this->number >> this->incity_time >> this->intercity_time;
}


Phone::Phone(string a, string b, string c, string d, long e, long f, long h) : 
surname(a), name(b), father_name(c), adress(d), number(e), incity_time(f), intercity_time(h) {}


string Phone::get_adress(){return this->adress;}


string Phone::get_surname() {return this->surname;}


string Phone::get_name() {return this->name;}


string Phone::get_father_name() {return this->father_name;}


long Phone::get_number() {return this->number;}


long Phone::get_incity_time() {return this->incity_time;}


long Phone::get_intercity_time() {return this->intercity_time;}


void Phone::set_adress(string a) {this->adress = a;}

void Phone::set_name(string a) {this->name = a;}

void Phone::set_surname(string a) {this->surname = a;}

void Phone::set_father_name(string a) {this->surname = a;}

void Phone::set_number(long a) {this->number = a;}

void Phone::set_incity_time(long a) {this->incity_time = a;}

void Phone::set_intercity_time(long a) {this->intercity_time = a;}


void Phone::show()
{
    cout << "Имя: " << this->surname << " " << this->name << " " << this->father_name << endl;
    cout << "Адрес: " << this->adress << endl;
    cout << "Номер: " << this->number << endl;
    cout << "Время внутригородних разговоров: " << this->incity_time << endl;
    cout << "Время междугородних разговоров: " << this->intercity_time << endl;

}

void Phone::to_file(ofstream& file_stream)
{

    file_stream << surname << endl << name << endl << father_name << endl << adress << endl << number << endl << incity_time << endl << intercity_time << endl;
    
}

void Phone::add_incity_call_time(long a) {this->incity_time += a;}

void Phone::add_intercity_call_time(long a) {this->intercity_time += a;}

