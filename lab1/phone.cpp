#include "header.h"

Phone::Phone()
{
    cout << "Введите фамилию" << endl;
    cin >> this->surname;
    cout << "Введите имя" << endl;
    cin >> this->name;
    cout << "Введите отчество" << endl;
    cin >> this->father_name;
    cout << "Введите адресс" << endl;
    cin >> this->adress;
    cout << "Введите номер" << endl;
    cin >> this->number;
    cout << "Введите время междугородних разговоров" << endl;
    cin >> this->intercity_time;
    cout << "Введите время внутригородних разговоров" << endl;
    cin >> this->incity_time;
}


Phone::Phone(string filename)
{
    ifstream fp;
    fp >> this->surname >> this->name >> father_name;
    getline(fp, this->adress);
    fp >> this->number >> this->incity_time >> this->intercity_time;
}


Phone::Phone(string a, string b, string c, string d, long e, long f, long h)
{
    this->surname = a;
    this->name = b;
    this->father_name = c;
    this->adress = d;
    this->number = e;
    this->incity_time = f;
    this->intercity_time = h;
}


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

void Phone::to_file(string filename)
{
    ofstream fp;

    fp << surname << " " << name << " " << father_name << "\n" << adress << "\n" << number << " " << incity_time << " " << intercity_time << endl;
    
}

void Phone::add_incity_call_time(long a) {this->incity_time += a;}

void Phone::add_intercity_call_time(long a) {this->intercity_time += a;}

Phone::~Phone()
{

}