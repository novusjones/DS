#include <iostream>
using namespace std;
typedef struct DuLnode{
    int data;
    struct DuLnode *prior;
    struct DuLnode *next;
}DuLnode, *DuLinkList;//结构体指针是为了动态操做链表

bool InitList(DuLinkList &L){ //传地址
   L = new DuLnode; //new分配内存，返回内存首地址，将地址赋值给指针L
   if(L == nullptr) return false; //分配内存失败
   L->prior = L->next = nullptr; //头结点的前驱和后继都指向空
   return true;
}
// 依次打印双链表的值
void PrintDuList(DuLinkList L){
    DuLinkList p = L -> next;
    while(p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
}
// 头插法创建双链表
void CreateDuList_H(DuLinkList &L){
    int n;
    DuLinkList s;
    cout << "头插法创建双链表，输入链表长度："<<endl;
    cin >> n;
    cout << "依次输入链表元素" << endl;
    while(n--){
        s = new DuLnode;
        cin >> s->data;
        if(L->next == nullptr){
            s->prior = L;
            s->next = nullptr;
            L->next = s;
        }else{
        s->next = L->next;
        L->next->prior = s;
        s->prior = L;
        L->next = s;
        }
    }
}

int main(){
    DuLinkList L; //定义结构体指针
    InitList(L);
    CreateDuList_H(L);
    PrintDuList(L);
    return 0;
}