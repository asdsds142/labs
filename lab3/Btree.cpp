#include "header.h"

/*; функции использувовавшиеся для отладки
void tester(int num)
{
    string asd;
    asd = to_string(num);
    cout << "flag" << num << endl;
}


void tester(string num)
{
    cout << "flag" << num << endl;
}*/



//конструктор ноды
Btree::node::node(double val) : value(val){}

Btree::node::~node()
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

Btree::~Btree()
{
    time_checker tch{"~Btree"};
    if (this->root)
    {
        delete this->root;
    }
}



//конструктор
Btree::Btree(double v)
{
    time_checker ch{"Btree"};
    //cout << "Btree::Btree(double v) started" << endl;
    node* n = new node(v);
    this->root = n;
    //cout << "Btree::Btree(double v) finished" << endl;
}


//конструктор перемешения 
Btree::Btree(Btree&& other)
{
    this->root = other.root;
    other.root = nullptr;
}

//конструктар
Btree::Btree(vector<double> v)
{
    time_checker ch{"Btree(vector)"};
    //cout << "Btree::Btree(vector<double> v) started" << endl;
    int a = v.size()/2;

    /*for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    */
    node* n = new node(v[a]);
    this->root = n;

    for (int i = 0; i < v.size(); ++i)
    {
        if (i == a) continue;
        add(v[i]);            
    }
    //cout << "Btree::Btree(vector<double> v) finished" << endl;
}


//конструктар
Btree::Btree(string filename)
{
    //cout << "Btree::Btree(string filename) started" << endl;
    ifstream fp{filename};
    if (!fp)
        throw runtime_error("файл не открыт");
    vector<double> v;
    int a = 0;
    while (fp >> a && a != EOF)
    {
        v.push_back(a);
    }


    //sort(&v);
    for (int cntr = 0; cntr < v.size(); cntr++)
    {
        cout << v[cntr] << " ";
    }
    int numeral = v.size()/2;

    node *n = new node(v[numeral]);
    this->root = n;

    for (int i = 0; i < v.size(); ++i)
    {
        if (i == numeral) continue;
        add(v[i]);            
    }


    //cout << "Btree::Btree(string filename) finished" << endl;
}


//функция добавляющая ноду с значением v в дерево
void Btree::add(double v)
{

    //cout << "void Btree::add(double v) started" << endl;
    if (this->root)
    {
        //add(this->root, v);
        cycle_add(v); //работает немного быстрее
    }
    else 
    {
        node *a = new node(v);
        this->root = a;
    }
   // cout << "void Btree::add(double v) finished" << endl;
}

void Btree::cycle_add(double val)
{
    node* current_node = this->root;
    while(1)
    {
        if (val > current_node->value)
        {
            if (current_node->right)
            {
                current_node = current_node->right;
            }
            else
            {
                current_node->right = new node(val);
                break;
            }
        }
        else
        {
            if (current_node->left)
            {
                current_node = current_node->left;
            }
            else
            {
                current_node->left = new node(val);
                break;
            }
        }
    }
}


void Btree::add(node* n, double v)
{
    //cout << "void Btree::add(node* n, double v) started" << endl;
        //cout << "value = " << v << " n->value = " << n->value << endl;
        if (v > n->value)
        {
            if (n->right){ add(n->right, v); }

            else 
            {
                node *a = new node(v); //я добавил динамическое выделение памяти и оно магическим образом заработало
                n->right = a;
            }
        }

        else
        {
            if (n->left){ add(n->left, v);}

            else 
            {
                node *a = new node(v);
                n->left = a;
            }
        }    
    //cout << "void Btree::add(node* n, double v) finished" << endl;
}

//функция записывающая дерево в файл, правильность не проверялась (уже вижу что не совсем пральна)
void Btree::write_to_file(string filename, node* ptr)
{
    //cout << "void Btree::write_to_file(string filename, node* ptr) started" << endl;
    if (ptr->left)
        write_to_file(filename, ptr->left);
    ofstream fp{filename}; 
    fp << ptr->value << " ";
    fp.close();
    if (ptr->right)
        write_to_file(filename, ptr->right);   

    //cout << "void Btree::write_to_file(string filename, node* ptr) finished" << endl; 
}



void Btree::write_to_file(string filename)
{
    write_to_file(filename, this->root);
}


//ненужная функция, раньше использовал ее для сортировки массива для выбора оптимального корня дерева, но потом я прочитал про rb-tree
/*
void Btree::sort(vector<double> *v)
{
    //cout << "void Btree::sort(vector<double> v) started" << endl;
    int n = 1;
    int tmp;
    while (n)
    {
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
    for (int cntr = 0; cntr < v->size(); cntr++)
    {
        cout << v->at(cntr) << "";
    }

    //cout << "void Btree::sort(vector<double> v) finished" << endl;
}*/

//функция ищущая ключ value по дереву и возвращающая 0/1 + пишущая в cout результат поиска
bool Btree::find(double value)
{
    //cout << "bool Btree::find(double value) started" << endl;
    if (value == root->value)
    {
        cout << "Значение найдено" << endl;
        return 1;
    }

    bool result = 0;
    if (value < root->value && root->left)
    {
        result = find(value, root->left);
    }

    if (value > root->value && root->right)
    {
        result = find(value, root->right);
    }
    return result;
    //cout << "bool Btree::find(double value) finished" << endl;
}


bool Btree::find(double value, node* ptr)
{
    //cout << "bool Btree::find(double value, node* ptr) started" << endl;
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
    }

    if (value > root->value)
    {
        if (!ptr->right)
        {
            //cout << "Значение не найдено" << endl;
            return result;
        }
        result = find(value, ptr->right);
    }
    return result;
    //cout << "bool Btree::find(double value, node* ptr) finished" << endl;
}

//можно давать ей пустой массив на вход и давать работать с ним ну потом на тестировании попробую
//функция сортирующая дерево в массив от меньшего к большему или наоборот в зависимости от flag (1 возрастание, 0 убывание)
vector<double> Btree::get_sorted(bool flag)
{
    //cout << "vector<double> Btree::get_sorted(bool flag) started" << endl;
    vector<double> result;
    
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

    //cout << "vector<double> Btree::get_sorted(bool flag) finished" << endl;
    return result;
}



void Btree::get_sorted(bool flag, vector<double> *result, node* ptr)
{
    //cout << "void Btree::get_sorted(bool flag, vector<double> result, node* ptr) started" << endl;
    if (flag)
    {
        //cout << "value" << ptr->value << endl;
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
            //cout << "flag12";
            get_sorted(flag, result, ptr->right);
        }
        result->push_back(ptr->value);
        if (ptr->left)
        {
            //cout << "flag11";
            get_sorted(flag, result, ptr->left);
        }
    }
    //cout << "void Btree::get_sorted(bool flag, vector<double> result, node* ptr) finished" << endl;
}


//возвращает значение корня
double Btree::get_rootvalue() {return this->root->value;}


//выводит дерево слева направо на экран
void Btree::show()
{
    cout << "функция-метод Btree::show() показываем дерево начала свою работу: " << endl; 
    if (this->root != nullptr)
    {
        show(this->root);
        cout << endl;
    }
}

void Btree::show(node* nodeptr)
{
    if (nodeptr == nullptr)
    {
        throw runtime_error("Btree::show(node*) передан nullptr");
    }

    if (nodeptr->left)
    {
        show(nodeptr->left);
    }
    cout << nodeptr->value << " ";
    if (nodeptr->right)
    {
        show(nodeptr->right);
    }
}