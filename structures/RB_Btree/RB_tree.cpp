#include "RB_tree.h"

using namespace std;


RB_tree::node::node(int val)
{
    this->value = new int(val);
}


RB_tree::RB_tree()
{
    this->root = nullptr;
}


void RB_tree::add_element(int val)
{   
    if (this->root)
        add_element(val, this->root);
    else
    {
        node* nodeptr = new node(val);
        nodeptr->is_red = 0;
        this->root = nodeptr;
    }
}

void RB_tree::add_element(int val, node* nodeptr)
{
    if (!nodeptr)
    {
        throw runtime_error("Ошибка add_element получил пустую ноду");
    }

    if (val < *nodeptr->value)
    {
        if (nodeptr->left_child)
        {
            add_element(val, nodeptr->left_child);
        }
        else
        {
            node* nodep = new node(val);
            nodeptr->left_child = nodep;
            tr_rearrange(nodep);
        }
    }
    else
    {
        if (nodeptr->right_child)
        {
            add_element(val, nodeptr->right_child);
        }
        else
        {
            node* nodep = new node(val);
            nodeptr->right_child = nodep;
            tr_rearrange(nodep);
        }
    }
}


void RB_tree::tr_rearrange(node* nodeptr)
{
    if (nodeptr->parent->is_red == 0) //случай 1 все хорошо
    {
        
    }

    else if(nodeptr->parent->get_sibling_color() == 0) //случай 2 красная проблема, сосед черный
    {
        nodeptr->case_a();
    }

    else //случай 3 красная проблема сосед красный
    {
        nodeptr->case_b();
        tr_rearrange(nodeptr->parent->parent);
    }
}


RB_tree::node* RB_tree::node::get_sibling_p()
{
    if (this == this->parent->left_child)
    {
        return this->parent->right_child;
    }

    if (this == this->parent->right_child)
    {
        return this->parent->left_child;
    }

    else
    {
        cout << "get_sibling_p, необычное поведение" << endl;
    }
}


bool RB_tree::node::get_sibling_color()
{
    node* node_p;
    node_p = this->get_sibling_p();

    if (node_p == nullptr)
    {
        return 0;
    }

    else
    {
        return node_p->is_red;
    }
}

void RB_tree::node::case_a() //случай: красная проблема, брат родителя черный
{
    node* gr_gr_parent_p = this->parent->parent->parent; //если дедушка рут то сюда запишется нуллптр поэтому проверка вроде не нужна
    //вроде все так тут в функции сделал но не до конца уверен нужна тестировка то блин эти указатели могут случайно не так работать по моей глупости
    //потенциальная проблема вот тот что повыше может не то передавать, возможно нужен указатель на указатель и потом его разыменовывать хотя может и так нормально
    if (this->parent == this->parent->parent->left_child)
    {
        this->parent->parent->left_child = this->parent->right_child;
        this->parent->right_child = this->parent->parent;
        //тут еще перекраску забыл 
    }
    
    else
    {
        this->parent->parent->right_child = this->parent->left_child;
        this->parent->left_child = this->parent->parent;
    }

    this->parent->parent->parent = this->parent;
    this->parent->parent = gr_gr_parent_p;
}


void RB_tree::node::case_b() //случай: красная проблема, брат родителя красный(перекрашиваем, двигаемся дальше)
{
    this->parent->get_sibling_p()->is_red = 0; //вот тут вот проверить работу вроде хорошо написал но я раньше так не писал особо и не уверен
    this->parent->is_red = 0;
    this->parent->parent->is_red = 1;
}