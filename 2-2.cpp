#include<stdio.h>
#define OK 1
#define ERROR 0
#define ListSize 100
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}LNode,*LinkList;

//构造一个空的单链表L,初始化
int IniList(LinkList &L){
    L = new LNode;//为头结点分配存储单元
    if(!L)
        return ERROR;//无足够的内存空间，初始化失败
    L -> next = NULL;
    return OK;
}

//销毁链表
int DestoyList(LinkList &L){
    LinkList p;
    while (L){
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

//将L重置为空表
void ClearList(LinkList &L){
    LinkList p,q;
    p = L->next;//p指向第一个结点
    while(p){   //没到表尾
        q = p ->next;
        delete p;
        p = q;
    }
    L -> next = NULL;//头指针指针域为空
}

//返回L中数据元素个数
int LengthList(LinkList L){
    LinkList p = L -> next;//p指向第一个结点
    int i = 0;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

//若L为空表，则返回true, 否则返回false
int ListEmpty(LinkList L){
    if(L->next == NULL)
		return true;
	else
		return false;
}

LinkList LocateElem(LinkList L,ElemType e){
    LinkList p;
    p = L->next;
    while(p && p->data != e)
        p = p ->next;
    return p;//返回L中值为e的数据元素的位置，查找失败返回NULL
}

//在带头结点的单链表L中查找第i各元素
int GetElem(LinkList L,int i,ElemType &e){
    LinkList p = L->next;
    int j = 1;
    while(p != NULL && j < i){
        p = p ->next;
        j++;
    }
    if (!p || i < 1)
        return ERROR;
    e = p->data;
    return OK;
}

//将值为e的新结点插入到表的第i个结点的位置上
int ListInsert(LinkList &L,int i, ElemType e){
    LinkList p = L, q;
    int j = 0;
    while(p && j < i - 1){//寻找第i-1个结点
        p = p ->next;
        j++;
    }
    if(!p || i < 1)
        return ERROR;//i大于表长+1或小于1
    q = new LNode;  //生成新结点q
    q -> data = e;  //将结点q 的数据域置为e
    q -> next = p -> next;//将结点q 插入L中
    p -> next = q;
    return OK;
}

//按序号删除结点
int ListDelete(LinkList &L,int i, ElemType &e){
    LinkList p = L,q;
    int j = 0;
    while(p -> next && j < i-1){//寻找第i个结点，并令p指向其前驱
        p = p -> next;
        j++;
    }
    if(!(p -> next) || i < 1)
        return ERROR;           //删除位置不合理
    q = p -> next;              //临时保存被删结点的地址以备释放
    p -> next = q -> next;      //改变被删除结点前驱结点的指针域
    e = q -> data;              //保存被删除节点的数据域
    delete q;                   //释放被删除结点的空间
    return OK;
}

//按值删除结点
int ListDeleteValue(LinkList &L,ElemType e){
    LinkList p = L,q = L -> next;
    while(q && q -> data != e){ //寻找元素值等于e的结点，并令p指向其前驱
        p = q;
        q = q -> next;
    }
    if (!q)
        return ERROR;           //没有找到值为e的结点
    p -> next = q -> next;      //改变被删除节点的前驱结点的指针域
    delete q;                   //释放被删除结点的空间
    return OK;
}

//在单链表的头部插入结点建立单链表
void CreateList_F(LinkList &L,int n){
    //逆位序输入n个元素的值，建立单链表L
    //要求，在用前插法创建单链表之前，需要执行InitList()初始化单链表，
    //即先建立一个带表头结点的空表
    LinkList p;
    printf("请按逆序依次输入元素的值：");
    for(int i = n ; i > 0; i--){
        p = new LNode;          //生成新结点
        scanf("%d",&p -> data); //输入元素值
        p -> next = L -> next ;
        L ->next = p;           //插入到表头
    }
}

//在单链表的尾部插入结点建立单链表
void CreateList_R(LinkList &L,int n){
    //正位序输入n个元素的值，建立带头结点的单链表L
    //要求，在用前插法创建单链表之前，需要执行IntList()初始化单链表，
    //即先建立一个带表头结点的空表
    LinkList p, r = L;
    printf("请按正序依次输入元素的值：");
    for(int i = 0;i < n;i++){
        p = new LNode;         //生成新结点
        scanf("%d",&p -> data); //输入元素值
        p -> next = NULL;
        r -> next = p;          //插入到表尾
        r = p;                  //r指向新的尾结点
    }
}

//输出线性表
void DispList(LinkList L){
    printf("单链表为：");
    if(ListEmpty(L)){
        printf("表空！\n");
        return;
    }
    LinkList p = L -> next;
    while(p){
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("\n");
}

int _flushall(void){
}

//显示菜单
void Showmenu(){
    printf("\n");
    printf("   --线性表链式存储基本运算演示--  \n");
    printf("***********************************\n");
    printf("*    1 ----单链表的初始化         *\n");
    printf("*    2 ----销毁单链表             *\n");
    printf("*    3 ----清空单链表             *\n");
    printf("*    4 ----求单链表的长度         *\n");
    printf("*    5 ----判断单链表是否为空     *\n");
    printf("*    6 ----检索表中第i个元素的值  *\n");
    printf("*    7 ----检索元素值为e的元素    *\n");
    printf("*    8 ----插入数据元素           *\n");
    printf("*    9 ----按序号删除数据元素     *\n");
    printf("*    10----按值删除数据元素       *\n");
    printf("*    11----按头插法创建单链表     *\n");
    printf("*    12----按尾插法创建单链表     *\n");
    printf("*    0 ----退出                   *\n");
    printf("***********************************\n");
    printf("请选择菜单号(0--12): ");
}

void List(){
    int choice;
    ElemType item;
    int Position;
    int number;
    LinkList L;
    int flag = 0;               //是否创建好了单链表
    while(choice){
        Showmenu();
        _flushall();
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("初始化单链表操作\n");
            if(IniList(L)){
                printf("初始化成功！\n");
                flag = 1;       //标志顺序表的存在
            }
            else{
                printf("初始化失败！\n");
            }
            break;
        case 2:
            if(flag){           //单链表存在
                DestoyList(L);
                flag = 0;       //单链表已删除
                printf("单链表删除成功! \n");
            }
            else {
                printf("单链表不存在，操作失败! \n");
            }
            break;
        case 3:
            if(flag){           //单链表存在
                ClearList(L);
                printf("单链表清空成功！\n");
                DispList(L);    //输出线性表
            }
            else{
                printf("单链表不存在，操作失败! \n");
            }
            break;
        case 4:
            if(flag){           //单链表存在
                printf("单链表元素个数为 %d \n",LengthList(L));
                DispList(L);    //输出线性表
            }
            else{
                printf("单链表不存在，操作失败! \n");
            }
            break;
        case 5:
            if(flag){           //单链表存在
                printf("单链表%s.\n",ListEmpty(L)?"空":"不空");
                DispList(L);    //输出线性表
            }
            else{
                printf("单链表不存在，操作失败! \n");
            }
            break;
        case 6:
			if(flag){           //单链表存在
                printf("请输入元素的位序号：");
                scanf("%d",&Position);
                if(GetElem(L,Position,item)){
                    printf("第%d个元素为：%c\n",Position,item);
                }
                else{
                    printf("输入的位序号有误！\n");
                }
                DispList(L);
            }
            else{
                printf("单链表不存在，操作失败! \n");
            }
            break;
        case 7:
            if(flag){           //单链表存在
                printf("请输入元素的值：");
                _flushall();
                scanf("%d",&item);
                LinkList P = LocateElem(L,item);
                if(P){
                    printf("该元素找到,地址为 %x ！\n",P);
			    }
                else{
                    printf("该元素没找到！\n");
                }
                DispList(L);    //输出线性表
            }
            else{
                printf("单链表不存在，操作失败! \n");
            }
            break;
        case 8:
            if(flag){           //单链表存在
                printf("请输入元素的值：");
                _flushall();
                scanf("%d",&item);
                printf("请输入要插入数据元素的位序号：");
                scanf("%d",&Position);
                if(ListInsert(L,Position,item))
                    printf("该元素插入成功！\n");
                else
                    printf("输入的位序号有误！");
                DispList(L);    //输出线性表
            }
            else{
               printf("单链表不存在，操作失败! \n");
            }
            break;
            case 9:
                if(flag){           //单链表存在
                    printf("请输入要删除数据元素的位序号：");
                    scanf("%d",&Position);
                    if(ListDelete(L,Position,item)){
                        printf("删除的元素为 %d ！\n",item);
                    }
                    else{
                        printf("输入的位序号有误！");
                    }
                    DispList(L);    //输出线性表
                }
                else{
                    printf("单链表不存在，操作失败! \n");
                }
                break;
            case 10:
                if(flag){           //单链表存在
                    printf("请输入要删除的元素：");
                    _flushall();
                    scanf("%d",&item);
                    if(ListDeleteValue(L,item)){
                        printf("删除的元素为 %d！\n",item);
                    }
                    else{
                        printf("该元素不存在，删除失败！\n");
                    }
                    DispList(L);    //输出线性表
                }
                else{
                    printf("单链表不存在，操作失败! \n");
                }
                break;
            case 11:
                if(flag){           //单链表存在
                    ClearList(L);   //清空单链表
                    printf("按头插法创建单链表\n");
                    printf("请输入要插入元素的个数：");
                    scanf("%d",&number);
                    _flushall();
                    CreateList_F(L,number);
                    DispList(L);    //输出线性表
                }
                else{
                    printf("单链表不存在，操作失败! \n");
                }
                break;
            case 12:
                if(flag){           //单链表存在
                    ClearList(L);   //清空单链表
                    printf("按尾插法创建单链表\n");
                    printf("请输入要插入元素的个数：");
                    scanf("%d",&number);
                    _flushall();
                    CreateList_R(L,number);
                    DispList(L);    //输出线性表
                }
                else{
                    printf("单链表不存在，操作失败! \n");
                }
                break;
            case 0:
                printf("\n\t程序结束！\t\n");
                DestoyList(L);
                break;
            default:
                printf("\n\t选择错误，请重新输入！\t\n");
                break;
        }
    }
}

int main(){
    List();
    return 0;
}
