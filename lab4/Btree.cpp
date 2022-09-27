#include "header.h"


void tester(int num)
{
    string asd;
    asd = to_string(num);
    cout << "flag" << num << endl;
}


void tester(string num)
{
    cout << "flag" << num << endl;
}

template<class T>
Btree<T>::Btree(T v)
{
    cout << "Btree::Btree(double v) started" << endl;
    node n;
    n.value = v;
    this->root = &n;
    cout << "Btree::Btree(double v) finished" << endl;
}

template<class T>
Btree<T>::Btree(vector<T> v)
{
    cout << "Btree::Btree(vector<double> v) started" << endl;
    sort(&v);
    int a = v.size()/2;

    cout << "flag12" << endl;
    node n;
    n.value = v[a];
    this->root = &n;
    cout << "flag13" << endl;

    for (int i = 0; i < v.size(); ++i)
    {
        if (i == a) continue;
        add(v[i]);            
    }
    cout << "Btree::Btree(vector<double> v) finished" << endl;
}


template<class T>
Btree<T>::Btree(string filename)
{
    cout << "Btree::Btree(string filename) started" << endl;
    ifstream fp{filename};
    vector<double> v;
    int a = 0;
    while (fp >> a && a != EOF)
    {
        v.push_back(a);
    }


    sort(&v);
    for (int cntr = 0; cntr < v.size(); cntr++)
    {
        cout << v[cntr] << "";
    }
    int numeral = v.size()/2;

    cout << "flag12" << endl;
    node *n = new node;
    n->value = v[numeral];
    this->root = n;
    cout << "flag13" << endl;

    for (int i = 0; i < v.size(); ++i)
    {
        if (i == numeral) continue;
        add(v[i]);            
    }


    cout << "Btree::Btree(string filename) finished" << endl;
}


template<class T>
void Btree<T>::add(T v)
{
    cout << "void Btree::add(double v) started" << endl;
    if (this->root)
        add(this->root, v);
    else 
    {
        node *a = new node;
        a->value = v;
        this->root = a;
    }
    cout << "void Btree::add(double v) finished" << endl;
}

template<class T>
void Btree<T>::add(node* n, T v)
{
    cout << "void Btree::add(node* n, double v) started" << endl;
    if (flag) //пока не буду дописывать возможно тут можно макросом переназначить больше меньше
    {
        if (v > n->value)
        {
            if (n->right){ add(n->right, v);}

            else 
            {
                cout << "addelseflag" << endl;
                node *a = new node; //я добавил динамическое выделение памяти и оно магическим образом заработало
                a->value = v; 
                n->right = a;
            }
        }

        else
        {
            if (n->left){ add(n->left, v);}

            else 
            {
                cout << "addelseflag2" << endl;
                node *a = new node;
                a->value = v;
                n->left = a;
            }
        }
    }
            
    cout << "void Btree::add(node* n, double v) finished" << endl;
}

template<class T>
void Btree<T>::write_to_file(string filename, node* ptr)
{
    cout << "void Btree::write_to_file(string filename, node* ptr) started" << endl;
    if (ptr->left)
        write_to_file(filename, ptr->left);
    ofstream fp{filename}; 
    fp << ptr->value << " ";
    fp.close();
    if (ptr->right)
        write_to_file(filename, ptr->right);   

    cout << "void Btree::write_to_file(string filename, node* ptr) finished" << endl; 
}


template<class T>
void Btree<T>::write_to_file(string filename)
{
    write_to_file(filename, this->root);
}

template<class T>
void Btree<T>::sort(vector<T> *v)
{
    cout << "void Btree::sort(vector<double> v) started" << endl;
    int n = 1;
    int tmp;
    if (flag)
    {
        while (n)
        {
            tester("sort1");
            n = 0;
            for (int i = 0; i < v->size(); i++)
            {
                //вот тут все работает нормально по крайней мере разок оно сделало и вывело норм массив
                if (i+1 != v->size() && v->at(i) > v->at(i+1))
                {
                    cout << v->at(i) << " " << v->at(i+1) << endl;
                    swap(v->at(i), v->at(i+1));
                    n++;
                }
            }
        }       
    }
    for (int cntr = 0; cntr < v->size(); cntr++)
    {
        cout << v->at(cntr) << "";
    }

    cout << "void Btree::sort(vector<double> v) finished" << endl;
}

template<class T>
bool Btree<T>::find(T value)
{
    cout << "bool Btree::find(double value) started" << endl;
    if (value == root->value)
    {
        cout << "Значение найдено" << endl;
        return 1;
    }

    bool result = 0;
    if (value < root->value)
    {
        result = find(value, root->left);
        return result;
    }

    if (value > root->value)
    {
        result = find(value, root->right);
        return result;
    }
    cout << "bool Btree::find(double value) finished" << endl;
}

template<class T>
bool Btree<T>::find(T value, node* ptr)
{
    cout << "bool Btree::find(double value, node* ptr) started" << endl;
    if (value == ptr->value)
    {
        cout << "Значение найдено" << endl;
        return 1;
    }

    bool result = 0;
    if (value < ptr->value)
    {
        if (!ptr->left)
        {
            cout << "Значение не найдено" << endl;
            return result;
        }
        result = find(value, ptr->left);
        return result;
    }

    if (value > root->value)
    {
        if (!ptr->right)
        {
            cout << "Значение не найдено" << endl;
            return result;
        }
        result = find(value, ptr->right);
        return result;
    }
    cout << "bool Btree::find(double value, node* ptr) finished" << endl;
}

//можно давать ей пустой массив на вход и давать работать с ним ну потом на тестировании попробую
//функция сортирующая дерево в массив от меньшего к большему или наоборот в зависимости от flag (1 возрастание, 0 убывание)
template<class T>
vector<T> Btree<T>::get_sorted(bool flag)
{
    cout << "vector<double> Btree::get_sorted(bool flag) started" << endl;
    vector<T> result;
    
    if (flag)
    {
        if (this->root->left)
        {
            get_sorted(flag, &result, this->root->left);
        }
        
        
        result.push_back(this->root->value);
        if (this->root->right)
        {
            get_sorted(flag, &result, this->root->right);
        }

    }

    else
    {
        if (this->root->right)
        {
            get_sorted(flag, &result, this->root->right);
        }

        result.push_back(this->root->value);
        if (this->root->left)
        {
            get_sorted(flag, &result, this->root->left);
        }
    }

    cout << "vector<double> Btree::get_sorted(bool flag) finished" << endl;
    return result;
}

//как то от иф элсов надобно бы перейти к нормальной программе то так цифор малавата получаетса помойму
template<class T>
void Btree<T>::get_sorted(bool flag, vector<T> *result, node* ptr)
{
    cout << "void Btree::get_sorted(bool flag, vector<double> result, node* ptr) started" << endl;
    if (flag)
    {
        tester(2);
        cout << "value" << ptr->value << endl;
        if (ptr->left != nullptr)
        {
            tester(3);
            get_sorted(flag, result, ptr->left);
        }
        result->push_back(ptr->value);
        tester(4);
        if (ptr->right)
        {
            tester(5);
            get_sorted(flag, result, ptr->right);
        }
    }
    else
    {
        tester(1);
        if (ptr->right)
        {
            cout << "flag12";
            get_sorted(flag, result, ptr->right);
        }
        result->push_back(ptr->value);
        if (ptr->left)
        {
            cout << "flag11";
            get_sorted(flag, result, ptr->left);
        }
    }
    cout << "void Btree::get_sorted(bool flag, vector<double> result, node* ptr) finished" << endl;
}

template<class T>
Btree<T>::~Btree(){}