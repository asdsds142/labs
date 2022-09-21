#include "header.h"




Btree::Btree(double v)
{

    node n;
    n.value = v;
    this->root = &n;
}


Btree::Btree(vector<double> v)
{
    sort(v);
    int a = v.size()/2;

    node n;
    n.value = v[a];
    this->root = &n;

    for (int i = 0; i < v.size(); i++)
    {
        if (i = a) continue;
        add(v[i]);            
    }
}



Btree::Btree(string filename)
{
    ifstream fp{filename};
    vector<double> v;
    int a = 0;
    while (fp >> a && a != EOF)
    {
        v.push_back(a);
    }
    Btree a{v};
    *this = a;
}



void Btree::add(double v)
{
    if (this->root)
        add(this->root, v);
    else 
    {
        node a;
        a.value = v;
        this->root = &a;
    }
}


void Btree::add(node* n, double v)
{
    if (flag) //пока не буду дописывать возможно тут можно макросом переназначить больше меньше
    {
        if (v > n->value)
        {
            if (n->right){ add(n->right, v);}

            else 
            {
                node a;
                a.value = v;
                n->right = &a;
            }
        }

        else
        {
            if (n->left){ add(n->left, v);}

            else 
            {
                node a;
                a.value = v;
                n->left = &a;
            }
        }
    }
        

}


void Btree::write_to_file(string filename, node* ptr)
{
    if (ptr->left)
        write_to_file(filename, ptr->left);
    ofstream fp{filename}; 
    fp << ptr->value << " ";
    fp.close();
    if (ptr->right)
        write_to_file(filename, ptr->right);    
    
}



void Btree::write_to_file(string filename)
{
    write_to_file(filename, this->root);
}


void Btree::sort(vector<double> v)
{
    int n = 1;
    int tmp;
    if (flag)
    {
        while (n)
        {
            n = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] > v[i+1])
                {
                    tmp = v[i];
                    v[i] = v[i+1];
                    v[i] = tmp;
                    n++;
                }
            }
        }       
    }
}


bool Btree::find(double value)
{
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
}


bool Btree::find(double value, node* ptr)
{
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
}

//можно давать ей пустой массив на вход и давать работать с ним ну потом на тестировании попробую
//функция сортирующая дерево в массив от меньшего к большему или наоборот в зависимости от flag (1 возрастание, 0 убывание)
vector<double> Btree::get_sorted(bool flag)
{
    vector<double> result;
    
    if (flag)
    {
        if (this->root->left)
        {
            get_sorted(flag, result, this->root->left);
        }
        else
        {
            result.push_back(this->root->value);
            if (this->root->right)
            {
                get_sorted(flag, result, this->root->right);
            }
        }
    }

    else
    {
        if (this->root->right)
        {
            get_sorted(flag, result, this->root->right);
        }
        else
        {
            result.push_back(this->root->value);
            if (this->root->left)
            {
                get_sorted(flag, result, this->root->left);
            }
        }
    }

    return result;
}

//проверить передачу массива, но так вроде должно работать хоть я и не тестировал

void Btree::get_sorted(bool flag, vector<double> result, node* ptr)
{
    if (flag)
    {
        if (ptr->left)
        {
            get_sorted(flag, result, ptr->left);
        }
        else
        {
            result.push_back(ptr->value);
            if (ptr->right)
            {
                get_sorted(flag, result, ptr->right);
            }
        }
    }

    else
    {
        if (ptr->right)
        {
            get_sorted(flag, result, ptr->right);
        }
        else
        {
            result.push_back(ptr->value);
            if (ptr->left)
            {
                get_sorted(flag, result, ptr->left);
            }
        }
    }
}