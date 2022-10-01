#pragma once

#include <iostream>
#include <vector>


class RB_tree
{
private:
    struct node
    {
        //0 - красный, 1 - черный
        bool is_black = 0; //пока что бул, потом попробую всунуть бит куда нибудь но покачто я не уверен что не потеряю данные да и так проектировать попроще будет
        int* value;

        node* parent = nullptr;//принципе можно попробывать тут добавить этсамое еще 2 указателя для понятности а потом убрать их, но покачто я без них попробыю
        node* left_child = nullptr;
        node* right_child = nullptr;
        node(int);
    };

    node* root;

    void add_element(int, node*);
    void tr_rearrange(node*);
    void case_a(node*);
    void case_b(node*);
    void case_c(node*);

public:
    RB_tree();

    void add_element(int);
};