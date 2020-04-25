#include<stdio.h>
#define OK 1
#define ERROR 0
#define ListSize 100
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}LNode,*LinkList;

//����һ���յĵ�����L,��ʼ��
int IniList(LinkList &L){
    L = new LNode;//Ϊͷ������洢��Ԫ
    if(!L)
        return ERROR;//���㹻���ڴ�ռ䣬��ʼ��ʧ��
    L -> next = NULL;
    return OK;
}

//��������
int DestoyList(LinkList &L){
    LinkList p;
    while (L){
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

//��L����Ϊ�ձ�
void ClearList(LinkList &L){
    LinkList p,q;
    p = L->next;//pָ���һ�����
    while(p){   //û����β
        q = p ->next;
        delete p;
        p = q;
    }
    L -> next = NULL;//ͷָ��ָ����Ϊ��
}

//����L������Ԫ�ظ���
int LengthList(LinkList L){
    LinkList p = L -> next;//pָ���һ�����
    int i = 0;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

//��LΪ�ձ��򷵻�true, ���򷵻�false
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
    return p;//����L��ֵΪe������Ԫ�ص�λ�ã�����ʧ�ܷ���NULL
}

//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ��
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

//��ֵΪe���½����뵽��ĵ�i������λ����
int ListInsert(LinkList &L,int i, ElemType e){
    LinkList p = L, q;
    int j = 0;
    while(p && j < i - 1){//Ѱ�ҵ�i-1�����
        p = p ->next;
        j++;
    }
    if(!p || i < 1)
        return ERROR;//i���ڱ�+1��С��1
    q = new LNode;  //�����½��q
    q -> data = e;  //�����q ����������Ϊe
    q -> next = p -> next;//�����q ����L��
    p -> next = q;
    return OK;
}

//�����ɾ�����
int ListDelete(LinkList &L,int i, ElemType &e){
    LinkList p = L,q;
    int j = 0;
    while(p -> next && j < i-1){//Ѱ�ҵ�i����㣬����pָ����ǰ��
        p = p -> next;
        j++;
    }
    if(!(p -> next) || i < 1)
        return ERROR;           //ɾ��λ�ò�����
    q = p -> next;              //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
    p -> next = q -> next;      //�ı䱻ɾ�����ǰ������ָ����
    e = q -> data;              //���汻ɾ���ڵ��������
    delete q;                   //�ͷű�ɾ�����Ŀռ�
    return OK;
}

//��ֵɾ�����
int ListDeleteValue(LinkList &L,ElemType e){
    LinkList p = L,q = L -> next;
    while(q && q -> data != e){ //Ѱ��Ԫ��ֵ����e�Ľ�㣬����pָ����ǰ��
        p = q;
        q = q -> next;
    }
    if (!q)
        return ERROR;           //û���ҵ�ֵΪe�Ľ��
    p -> next = q -> next;      //�ı䱻ɾ���ڵ��ǰ������ָ����
    delete q;                   //�ͷű�ɾ�����Ŀռ�
    return OK;
}

//�ڵ������ͷ�������㽨��������
void CreateList_F(LinkList &L,int n){
    //��λ������n��Ԫ�ص�ֵ������������L
    //Ҫ������ǰ�巨����������֮ǰ����Ҫִ��InitList()��ʼ��������
    //���Ƚ���һ������ͷ���Ŀձ�
    LinkList p;
    printf("�밴������������Ԫ�ص�ֵ��");
    for(int i = n ; i > 0; i--){
        p = new LNode;          //�����½��
        scanf("%d",&p -> data); //����Ԫ��ֵ
        p -> next = L -> next ;
        L ->next = p;           //���뵽��ͷ
    }
}

//�ڵ������β�������㽨��������
void CreateList_R(LinkList &L,int n){
    //��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
    //Ҫ������ǰ�巨����������֮ǰ����Ҫִ��IntList()��ʼ��������
    //���Ƚ���һ������ͷ���Ŀձ�
    LinkList p, r = L;
    printf("�밴������������Ԫ�ص�ֵ��");
    for(int i = 0;i < n;i++){
        p = new LNode;         //�����½��
        scanf("%d",&p -> data); //����Ԫ��ֵ
        p -> next = NULL;
        r -> next = p;          //���뵽��β
        r = p;                  //rָ���µ�β���
    }
}

//������Ա�
void DispList(LinkList L){
    printf("������Ϊ��");
    if(ListEmpty(L)){
        printf("��գ�\n");
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

//��ʾ�˵�
void Showmenu(){
    printf("\n");
    printf("   --���Ա���ʽ�洢����������ʾ--  \n");
    printf("***********************************\n");
    printf("*    1 ----������ĳ�ʼ��         *\n");
    printf("*    2 ----���ٵ�����             *\n");
    printf("*    3 ----��յ�����             *\n");
    printf("*    4 ----������ĳ���         *\n");
    printf("*    5 ----�жϵ������Ƿ�Ϊ��     *\n");
    printf("*    6 ----�������е�i��Ԫ�ص�ֵ  *\n");
    printf("*    7 ----����Ԫ��ֵΪe��Ԫ��    *\n");
    printf("*    8 ----��������Ԫ��           *\n");
    printf("*    9 ----�����ɾ������Ԫ��     *\n");
    printf("*    10----��ֵɾ������Ԫ��       *\n");
    printf("*    11----��ͷ�巨����������     *\n");
    printf("*    12----��β�巨����������     *\n");
    printf("*    0 ----�˳�                   *\n");
    printf("***********************************\n");
    printf("��ѡ��˵���(0--12): ");
}

void List(){
    int choice;
    ElemType item;
    int Position;
    int number;
    LinkList L;
    int flag = 0;               //�Ƿ񴴽����˵�����
    while(choice){
        Showmenu();
        _flushall();
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("��ʼ�����������\n");
            if(IniList(L)){
                printf("��ʼ���ɹ���\n");
                flag = 1;       //��־˳���Ĵ���
            }
            else{
                printf("��ʼ��ʧ�ܣ�\n");
            }
            break;
        case 2:
            if(flag){           //���������
                DestoyList(L);
                flag = 0;       //��������ɾ��
                printf("������ɾ���ɹ�! \n");
            }
            else {
                printf("���������ڣ�����ʧ��! \n");
            }
            break;
        case 3:
            if(flag){           //���������
                ClearList(L);
                printf("��������ճɹ���\n");
                DispList(L);    //������Ա�
            }
            else{
                printf("���������ڣ�����ʧ��! \n");
            }
            break;
        case 4:
            if(flag){           //���������
                printf("������Ԫ�ظ���Ϊ %d \n",LengthList(L));
                DispList(L);    //������Ա�
            }
            else{
                printf("���������ڣ�����ʧ��! \n");
            }
            break;
        case 5:
            if(flag){           //���������
                printf("������%s.\n",ListEmpty(L)?"��":"����");
                DispList(L);    //������Ա�
            }
            else{
                printf("���������ڣ�����ʧ��! \n");
            }
            break;
        case 6:
			if(flag){           //���������
                printf("������Ԫ�ص�λ��ţ�");
                scanf("%d",&Position);
                if(GetElem(L,Position,item)){
                    printf("��%d��Ԫ��Ϊ��%c\n",Position,item);
                }
                else{
                    printf("�����λ�������\n");
                }
                DispList(L);
            }
            else{
                printf("���������ڣ�����ʧ��! \n");
            }
            break;
        case 7:
            if(flag){           //���������
                printf("������Ԫ�ص�ֵ��");
                _flushall();
                scanf("%d",&item);
                LinkList P = LocateElem(L,item);
                if(P){
                    printf("��Ԫ���ҵ�,��ַΪ %x ��\n",P);
			    }
                else{
                    printf("��Ԫ��û�ҵ���\n");
                }
                DispList(L);    //������Ա�
            }
            else{
                printf("���������ڣ�����ʧ��! \n");
            }
            break;
        case 8:
            if(flag){           //���������
                printf("������Ԫ�ص�ֵ��");
                _flushall();
                scanf("%d",&item);
                printf("������Ҫ��������Ԫ�ص�λ��ţ�");
                scanf("%d",&Position);
                if(ListInsert(L,Position,item))
                    printf("��Ԫ�ز���ɹ���\n");
                else
                    printf("�����λ�������");
                DispList(L);    //������Ա�
            }
            else{
               printf("���������ڣ�����ʧ��! \n");
            }
            break;
            case 9:
                if(flag){           //���������
                    printf("������Ҫɾ������Ԫ�ص�λ��ţ�");
                    scanf("%d",&Position);
                    if(ListDelete(L,Position,item)){
                        printf("ɾ����Ԫ��Ϊ %d ��\n",item);
                    }
                    else{
                        printf("�����λ�������");
                    }
                    DispList(L);    //������Ա�
                }
                else{
                    printf("���������ڣ�����ʧ��! \n");
                }
                break;
            case 10:
                if(flag){           //���������
                    printf("������Ҫɾ����Ԫ�أ�");
                    _flushall();
                    scanf("%d",&item);
                    if(ListDeleteValue(L,item)){
                        printf("ɾ����Ԫ��Ϊ %d��\n",item);
                    }
                    else{
                        printf("��Ԫ�ز����ڣ�ɾ��ʧ�ܣ�\n");
                    }
                    DispList(L);    //������Ա�
                }
                else{
                    printf("���������ڣ�����ʧ��! \n");
                }
                break;
            case 11:
                if(flag){           //���������
                    ClearList(L);   //��յ�����
                    printf("��ͷ�巨����������\n");
                    printf("������Ҫ����Ԫ�صĸ�����");
                    scanf("%d",&number);
                    _flushall();
                    CreateList_F(L,number);
                    DispList(L);    //������Ա�
                }
                else{
                    printf("���������ڣ�����ʧ��! \n");
                }
                break;
            case 12:
                if(flag){           //���������
                    ClearList(L);   //��յ�����
                    printf("��β�巨����������\n");
                    printf("������Ҫ����Ԫ�صĸ�����");
                    scanf("%d",&number);
                    _flushall();
                    CreateList_R(L,number);
                    DispList(L);    //������Ա�
                }
                else{
                    printf("���������ڣ�����ʧ��! \n");
                }
                break;
            case 0:
                printf("\n\t���������\t\n");
                DestoyList(L);
                break;
            default:
                printf("\n\tѡ��������������룡\t\n");
                break;
        }
    }
}

int main(){
    List();
    return 0;
}
