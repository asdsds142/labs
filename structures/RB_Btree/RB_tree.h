#pragma once

#include <iostream>
#include <vector>

//todo: протестировать, вроде нормально написал но не тестировал и до конца не уверен
//вроде забыл в реарренже сделать проверку на красный рут надо будет еще и это доделать
class RB_tree
{
private:
    struct node
    {
        //0 - красный, 1 - черный
        bool is_red = 1; //пока что бул, потом попробую всунуть бит куда нибудь но покачто я не уверен что не потеряю данные да и так проектировать попроще будет
        int* value;

        node* parent = nullptr;//принципе можно попробывать тут добавить этсамое еще 2 указателя для понятности а потом убрать их, но покачто я без них попробыю
        node* left_child = nullptr;
        node* right_child = nullptr;
        node(int);

        node* get_sibling_p();
        bool get_sibling_color();
        void case_a();
        void case_b();
    };

    node* root;

    void add_element(int, node*);
    void tr_rearrange(node*);

public:
    RB_tree();

    void add_element(int);
    void find(int);
    
};