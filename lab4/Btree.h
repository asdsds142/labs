//Btree.h
#pragma once
#include "Btree_class_description.h"


template<class T>
Btree<T>::node* Btree<T>::try_alloc(T value)
{
    node* ptr = nullptr;
    for (size_t i = 0; i < 10; i++) //пробуем 10 раз, не получается выключаемся
    {
        try
        {
            ptr = new node(value);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " " << i << '\n'; //обработка bad alloc
        }
    }
    return ptr;
}


template<class T>
Btree<T>::node* Btree<T>::try_alloc(const node& other)
{
    node* ptr = nullptr;
    for (size_t i = 0; i < 10; i++) //пробуем 10 раз, не получается выключаемся
    {
        try
        {
            ptr = new node(other);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " " << i << '\n'; //обработка bad alloc
        }
    }
    return ptr;
}

//конструктор ноды
template<class T>
Btree<T>::node::node(T val) : value(val){}

//деструктор ноды, чистим за собой
template<class T>
Btree<T>::node::~node()
{
    if (this->left)
    {
        delete this->left;
    }
    if (this->right)
    {
        delete this->right;
    }
}

//деструктор, чистим за собой
template<class T>
Btree<T>::~Btree()
{
    if (this->root_)
    {
        delete this->root_;
    }
}

//конструктор копирования ноды
template<class T>
Btree<T>::node::node(const node& other)
{
    this->value = other.value;
    if (other.left)
    {
        this->left = try_alloc(*other.left);
    }
    if (other.right)
    {
        this->right = try_alloc(*other.right);
    }
}

//оператор присваивания ноды
template<class T>
class Btree<T>::node& Btree<T>::node::operator=(const node& other) //надо уточнить почему тут такой синтаксис и без класс/тайпнейм ругается
{
    if (this == other)
    {
        return *this;
    }
    delete this; //узнал что надо удалять сначала то что было
    this = try_alloc(other); //чутка подредачил но не проверял вотето вот
} 

//конструктор из 1 элемента, по хорошему заменить на ... конструктор из списка элементов но то TODO
template<class T>
Btree<T>::Btree(T val)
{
    this->root_ = try_alloc(val);
}

//оператор присваивания дерева
template<class T>
Btree<T>& Btree<T>::operator=(const Btree& other)
{
    if (this == other)
    {
        return *this;
    }

    delete this->root_; //тут тоже подредачил удаляя старые штуки
    this->root_ = try_alloc(other.root_);
}

//конструктор перемещения
template<class T>
Btree<T>::Btree(Btree&& other)
{
    this->root_ = other.root_;
    other.root_ = nullptr;
}

//конструктор из std::vector<T>
template<class T>
Btree<T>::Btree(vector<T> v)
{
    //берем примерно средний элемент чтобы если "случайно" засунуть в дерево отсортированный массив не возник казус
    size_t a = v.size()/2; 

    this->root_ = try_alloc(v[a]);

    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i == a) continue;
        add(v[i]);            
    }

}

//конструктор копирования
template<class T>
Btree<T>::Btree(const Btree& other)
{
    this->root_ = try_alloc(*other.root_);
}

//добавление элемента через цикл
template<class T>
void Btree<T>::cycle_add(T val)
{
    auto current_node_p = this->root_;
    while(1)
    {
        if (val > current_node_p->value)
        {
            if (current_node_p->right)
            {
                current_node_p = current_node_p->right;
            }
            else
            {
                current_node_p->right = try_alloc(val);
                break;
            }
        }
        else
        {
            if (current_node_p->left)
            {
                current_node_p = current_node_p->left;
            }
            else
            {
                current_node_p->left = try_alloc(val);
                break;
            }
        }
    }
}



//базовое добавление элемента, вызывает циклическое добавление элемента если есть рут, если нету делает рут
template<class T>
void Btree<T>::add(T val)
{

    if (this->root_)
    {
        //recursive_add(this->root_, v); //откомментировать вначале чтобы проверить
        cycle_add(val); //циклическое работает немного быстрее, но можно еще потестировать
    }

    else { this->root_ = try_alloc(val);}
}

//рекурсивное добавление элемента
template<class T>
void Btree<T>::recursive_add(node* node_p, T val)
{
    if (val > node_p->value)
    {
        if (node_p->right){ recursive_add(node_p->right, val);}

        else { node_p->right = try_alloc(val);}
    }

    else
    {
        if (node_p->left){ recursive_add(node_p->left, val);}

        else { node_p->left = try_alloc(val);}
    }
}

//поиск элемента с заданным значением, циклический
template<class T>
bool Btree<T>::find(T val) const
{
    if (!this->root_)
    {
        cout << "Значение не найдено, дерево пустое! " << endl;
        return false;
    }

    bool result = false;
    auto current_node_p = this->root_;
    while(1)
    {
        if (val == current_node_p->value)
        {
            result = true;
            cout << "Значение найдено" << endl;
            break;
        }

        if (val > current_node_p->value)
        {
            if (current_node_p->right)
            {
                current_node_p = current_node_p->right;
            }
            else
            {
                cout << "Значение не найдено" << endl;
                break;
            }
        }
        else
        {
            if (current_node_p->left)
            {
                current_node_p = current_node_p->left;
            }
            else
            {
                cout << "Значение не найдено" << endl;
                break;
            }
        }
    }
    return result;
}

//функция 'сортирующая' дерево в массив от меньшего к большему или наоборот в зависимости от flag (1 возрастание, 0 убывание)
template<class T>
vector<T> Btree<T>::get_sorted(bool flag)
{
    vector<T> result;
    
    if (flag)
    {
        if (this->root_->left)
        {
            get_sorted(flag, &result, this->root_->left);
        }
        
        result.push_back(this->root_->value);
        if (this->root_->right)
        {
            get_sorted(flag, &result, this->root_->right);
        }

    }

    else
    {
        if (this->root_->right)
        {
            get_sorted(flag, &result, this->root_->right);
        }

        result.push_back(this->root_->value);
        if (this->root_->left)
        {
            get_sorted(flag, &result, this->root_->left);
        }
    }

    return result;
}

//рекурсивная часть функции get_sorted, засовывающая в массив крутые штуки
template<class T>
void Btree<T>::get_sorted(bool flag, vector<T> *result, node* ptr)
{
    if (flag)
    {
        if (ptr->left != nullptr)
        {
            get_sorted(flag, result, ptr->left);
        }

        result->push_back(ptr->value);

        if (ptr->right)
        {
            get_sorted(flag, result, ptr->right);
        }
    }
    else
    {

        if (ptr->right)
        {
            get_sorted(flag, result, ptr->right);
        }
        result->push_back(ptr->value);
        if (ptr->left)
        {
            get_sorted(flag, result, ptr->left);
        }
    }
}

//геттер значения рута
template<class T>
T Btree<T>::get_rootvalue() {return this->root_->value;}

//рекурсивный вывод в виде последовательности чисел
template<class T>
void Btree<T>::show() const
{
    if (this->root_ != nullptr)
    {
        show(this->root_);
        cout << endl;
    }
}

//дополнительная функция для рекурсивного вывода
template<class T>
void Btree<T>::show(node* nodeptr) const
{
    if (nodeptr == nullptr)
    {
        throw runtime_error("Btree::show(node*) передан nullptr");
    }

    if (nodeptr->left)
    {
        show(nodeptr->left);
    }
    cout << nodeptr->value << " " << &nodeptr->value <<  " ";
    if (nodeptr->right)
    {
        show(nodeptr->right);
    }
}