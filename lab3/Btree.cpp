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