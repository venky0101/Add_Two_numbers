struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
struct ListNode* result=(struct ListNode*)malloc(sizeof(struct ListNode));
result->val=0;
result->next=NULL;
struct ListNode* p=l1;//stores value of l1
struct ListNode* q=l2;//stores value of l2
struct ListNode* temp;//to store value of result
temp=result;

struct ListNode* new;
int sum=0,carry=0;
if(p==NULL && q==NULL)
    goto last;
while(1)
{
first: sum=(p?p->val:0)+(q?q->val:0)+carry;
temp->val=sum%10;
carry=sum/10;
p=p?p->next:0;
q=q?q->next:0;
if(p==NULL)
{
if(carry>0)
{
new=(struct ListNode*)malloc(sizeof(struct ListNode));
new->next=NULL;
temp->next=new;
temp=new;
goto first;
}

    }
    if(q==NULL)
    {
        if(carry>0)
        {
              new=(struct ListNode*)malloc(sizeof(struct ListNode));
            new->next=NULL;
            temp->next=new;
            temp=new;
            goto first;
        }
            
    }
    if(carry>0 || (p!=NULL || q!=NULL))
    {
     new=(struct ListNode*)malloc(sizeof(struct ListNode));
            new->next=NULL;
            temp->next=new;
            temp=new;
    }  
    if(carry==0 && p==NULL && q==NULL)
    {
        goto last;
    }
}
last:
return result;
}
