#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ���Ḯ��Ʈ 

// ��� , ����� ���������� ����
typedef struct node
{
	int data;
	struct node* next;
} Node;
Node* head=NULL;// ����� ���� & ���� �ƹ��͵� ����Ű�� ��� ���� 

int main()
{

	
	
	return 0;
}


void add_first(int item)// ����尡 ����Ű�� ��带 ���ο� ���� ����
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head; // ���� ��尡 ����Ű�� ���(�����)�� �ι�° ���� �̵� 
	head = tmp;      // ����带 tmp���� ���� 
}

void insert_after(int item,Node* prev)// �������� ���ڿ� ���� 
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

}

Node* remove_first()// ����� ������ �� �ּ� ���� why? �޸� ��ȯ�ϱ� ���� 
{
	if (head == NULL) {   // ����ó�� ����� ��尡 ������  
		return NULL;             
	}
	else {
		Node* tmp = head;  
		head = head->next;
		return tmp;
	}
}

Node* remove_after(Node* prev)
{
	Node* tmp = prev->next;
	if (tmp == NULL) {
		return NULL;
	}
	else {
		prev->next = tmp->next;
		return tmp;  //  �ּҹ�ȯ�ϴ� ����: ��� free�Լ��� �����Ϸ��� 
	}
}

void remove(int removedata)// ������ ������ �����ϰ� �ִ� ��� ���� 
{	
	Node* prev = head;
	Node* now = head->next;
	while (1)// ������ ������ �����ϰ��ִ� ��� ã�� 
	{
		if (prev->data == removedata)
		{
			 free(remove_first());  // ����� ���� 
			 return;
		}
		if (now->data == removedata)
		{
			free(remove_after(prev));// ������ ������ �������ִ� ��� ���� 
			return;
		}
			
		now = now->next;
		prev = prev->next;
	}

}

