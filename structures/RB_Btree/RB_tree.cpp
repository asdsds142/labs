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
        nodeptr->is_black = 1;
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
    if (1) //выражение
    {
        case_a;
        if(1)
        {
            
        }
    }

    if (1)
    {
        
    }
}
