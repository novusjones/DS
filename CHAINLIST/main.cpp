typedef struct DuLnode{
    int data;
    struct DuLnode *prior;
    struct DuLnode *next;
}DuLnode, *DuLinkList;//结构体指针是为了动态操做链表

bool InitList(DuLinkList &L){ //传引用
   L = new DuLnode; //创建头结点
   if(L == nullptr) return false; //分配内存失败
   L->prior = L->next = nullptr; //头结点的前驱和后继都指向空
   return true;
}


int main(){
    DuLinkList L; 
    InitList(L);
    return 0;
}