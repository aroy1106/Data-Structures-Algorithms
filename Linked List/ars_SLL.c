#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void create(struct node **h,int no)
{
	int i;
	struct node *cur,*l;
	for(i=0;i<no;i++)
	{
		cur=malloc(sizeof(struct node));
		scanf("%d",&cur->data);
		cur->next=NULL;
		if(*h==NULL)
		{
			*h=l=cur;
		}else
		{
			l->next=cur;
			l=cur;
		}
	}
}
int insert(struct node **h,int v,int pos)
{
	int i;
	struct node *cur,*p;
	cur=malloc(sizeof(struct node));
	if(cur==NULL)
		return 1;
	cur->data=v;
	cur->next=NULL;
	if(*h==NULL){
		*h=cur;
	}else if(pos==0){
		cur->next=*h;
		*h=cur;
	}else{
		for(i=1,p=*h;i<pos && p->next!=NULL;p=p->next,i++);
		cur->next=p->next;
		p->next=cur;
	}
	return 0;
}
int del(struct node **h,int pos,int *k){
	int i;
	struct node *prv,*p;
	if(*h==NULL){
		return 1;
	}else{
		for(i=1,p=*h;i<pos && p!=NULL;i++){
			prv=p;
			p=p->next;
		}
		if(p==NULL){
			return 1;
		}else{
			*k=p->data; 
			if(p==*h)
				*h=p->next;
			else
				prv->next=p->next;
			free(p);
			return 0;	
		}
	}
}

void display(struct node *h){
	struct node *cur=h;
	while(cur!=NULL){
		printf("%d\t",cur->data);
		cur=cur->next;
	}
	printf("\n");
}
int main(){
	int k;
	struct node *head=NULL;
	create(&head,5);
	display(head);
	insert(&head,10,0);
	display(head);
	insert(&head,11,9);
	display(head);
	insert(&head,12,3);
	display(head);
	del(&head,3,&k);
	display(head);
	del(&head,1,&k);
	display(head);
	return 0;
}














