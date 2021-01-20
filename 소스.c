#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// 연결리스트 

// 노드 , 헤드노드 전역변수로 설정
typedef struct node
{
	int data;
	struct node* next;
} Node;
Node* head=NULL;// 헤드노드 생성 & 현재 아무것도 가리키는 노드 없음 

int main()
{

	
	
	return 0;
}


void add_first(int item)// 헤드노드가 가리키는 노드를 새로운 노드로 설정
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head; // 현제 헤드가 가리키는 노드(헤드노드)를 두번째 노드로 이동 
	head = tmp;      // 헤드노드를 tmp노드로 설정 
}

void insert_after(int item,Node* prev)// 지정해준 노드뒤에 삽입 
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

}

Node* remove_first()// 헤드노드 삭제후 그 주소 리턴 why? 메모리 반환하기 위해 
{
	if (head == NULL) {   // 예외처리 저장된 노드가 없을때  
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
		return tmp;  //  주소반환하는 이유: 노드 free함수로 삭제하려고 
	}
}

void remove(int removedata)// 삭제할 데이터 저장하고 있는 노드 삭제 
{	
	Node* prev = head;
	Node* now = head->next;
	while (1)// 제거할 데이터 저장하고있는 노드 찾기 
	{
		if (prev->data == removedata)
		{
			 free(remove_first());  // 헤드노드 제거 
			 return;
		}
		if (now->data == removedata)
		{
			free(remove_after(prev));// 제거할 데이터 가지고있는 노드 제거 
			return;
		}
			
		now = now->next;
		prev = prev->next;
	}

}

