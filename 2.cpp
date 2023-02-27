#include <iostream> 

using namespace std;
struct NODE {
    int value;
    struct NODE* next;
};

struct si {
    size_t size;
    struct NODE* head;
};

void addelem(si* list, char elem)
{
    NODE* newElem = new NODE;
    newElem->value = elem;
    if (list->size == 0)
    {
        list->head = newElem;
        list->head->next = list->head;
    }
    else
    {
        struct NODE* temp;
        temp = list->head;
        list->head = newElem;
        newElem->next = temp;
    }
    ++list->size;
}

void permutations(si* list, si* listp, si* listm) {
    NODE* tmp = list->head;
    for (int i = 0; i < list->size; ++i)
    {
        if (tmp->value > 0) {
            addelem(listp, tmp->value);
        }
        else {
            addelem(listm, tmp->value);
        }
        tmp = tmp->next;
    }
}

si* dell(si* list) {
    NODE* L = list->head;
    si* NewList = new si;
    NewList->size = 0;
    NewList->head = NULL;
    for (int i = 0; i < list->size; ++i)
    {
        if (L->value >= 0) {
            addelem(NewList, L->value);
        }
        L = L->next;
    }
    return NewList;
    delete NewList;
}
void maxx(si* list) {
    int maxx = -1;
    NODE* D = list->head;
    NODE* L = list->head;
    NODE* pos = L->next;
    for (int i = 0; i < list->size; ++i)
    {
        if (L->value > maxx) {
            maxx = L->value;
            pos = L->next;

        }
        L = L->next;
    }
    L = list->head;
        for (int i = 0; i < list->size; ++i)
        {
            if (L->value == maxx && L->next == pos) {
                L->value = list->head->value;
                list->head->value = maxx;
                break;
            }
            L = L->next;
    }
}
void pr(si* list)
{
    NODE* tmp = list->head;
    cout << "List values: " << endl;
    for (int i = 0; i < list->size; ++i)
    {
        cout << "Value: " << tmp->value << endl;
        tmp = tmp->next;
    }

}

int main()
{
    si* list = new si;
    list->size = 0;
    list->head = NULL;
    si* listplus = new si;
    listplus->size = 0;
    listplus->head = NULL;
    si* listmin = new si;
    listmin->size = 0;
    listmin->head = NULL;

    addelem(list, -1);
    addelem(list, 0);
    addelem(list, 4);
    addelem(list, 7);
    addelem(list, 2);
    addelem(list, 3);

    permutations(list, listplus, listmin);

    pr(list);
    pr(listplus);
    pr(listmin);
    cout << "------------------------" << endl;
    listmin = dell(listmin);
    cout << "after" << endl;
    pr(list);
    pr(listplus);
    pr(listmin);
    cout << "------------------------" << endl;
    cout << "after" << endl;
    maxx(listplus);
    pr(listplus);
    delete list;
    delete listplus;
    delete listmin;
    return 0;
}
