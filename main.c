/*
	오픈소스SW 프로젝트 깃허브 체험하기 - 연결리스트 코드

	리스트 데이터 삭제 : 박문영 - parkmy123
	리스트 데이터 삽입 : 지하린 - JiHaRin
	리스트 데이터 검색 : 채윤재 - GroovyCat - 수정 : 함수 선언, 정의 순서 변경, malloc.h 선언, 리스트 검색 함수
	리스트 데이터 출력 : 장우성 - s0w0s

	뼈다구만 만든거니 각자 맡은 부분 원하시는 데로 수정하시면 됩니다. 
	다른 방식이 마음에 들면 뜯어고치시면 됩니다.
*/

#include <stdio.h>
#include <malloc.h>  

// 노드 구조체 선언
typedef struct cell {
	int element;
	struct cell *next;
}node;

node *head = NULL;
node *tail = NULL;

void insert_head_of_list(int val);  
void insert_end_of_list(int val);   
void print_list();                  
void del_list();                    
void search_list(node* head, int val); // 검색하고자 하는 데이터를 입력해 해당 데이터가 몇번째 노드에 있는지 확인하는 함수 

int main(void)
{
	int check = 0; //선택지 변수
	int num = 0; //삽입할 데이터 변수

	printf("*****************************************************\n\n");
	printf("                Linked_list 프로그램\n\n");
	printf("*****************************************************\n\n");
	printf("               1. 앞에 데이터 삽입\n");
	printf("               2. 뒤에 데이터 삽입\n");
	printf("               3. 리스트 삭제\n");
	printf("               4. 리스트 검색\n");
	printf("               5. 리스트 출력\n");
	printf("               6. 프로그램 종료\n\n");

	while (1)
	{

		printf("메뉴를 선택하시오 : "); scanf_s("%d", &check);

		if (check == 1)
			insert_head_of_list(num);
		else if (check == 2)
			insert_end_of_list(num);
		else if (check == 3)
			del_list();
		else if (check == 4) {
			printf("검색하고자 하는 값을 입력하세요 : ");
			scanf_s("%d", &num);
			if (num == head->num) {
				searchNode(head, num);
			}
			else
				printf("원하시는 값이 리스트에 없습니다.\n");
			continue;
		}
		else if (check == 5)
			print_list();
		else if (check == 6)
			break;
	}

	return 0;
}

//앞에 데이터 삽입
void insert_head_of_list(int val)
{
	node *tmp;
	tmp = (node*)malloc(sizeof(node));

	tmp->element = val;
	tmp->next = head;
	head = tmp;
}

//뒤에 데이터 삽입
void insert_end_of_list(int val)
{
	node *tmp;

	tmp = (node*)malloc(sizeof(node));

	tmp->element = val;
	tmp->next = NULL;
	tail = head;

	if (head == NULL)
	{
		head = tmp;
	}
	else
	{
		while ((tail->next) != NULL)
		{
			tail = tail->next;
		}

		tail -> next = tmp;
	}
}

//연결리스트 출력
void print_list()
{
	node * print;
	print = head;
	
	if(print == NULL){
	printf("리스트가 존재 하지 않습니다...\n");
	return;
	}
	
	while(print->next != NULL){
	printf(" %d - " ,print->element);
		print =print->next;
	}
	
	printf (" %d \n",print->element);
	
}

//리스트 데이터 제거
void del_list()
{
	int val;
	node *pre; //제거할 값 이전의 노드를 찾기 위한 포인터
	node *tmp = head;

	printf("삭제할 데이터값 입력 : \n"); scanf_s("%d", &val);

	if (tmp->next == NULL) //노드가 한 개일 경우
	{
		if (tmp->element == val)
		{
			head = NULL;
			return;
		}
		else
			printf("해당 데이터가 리스트에 없습니다.");
	}
	else
	{
		while (tmp != NULL)
		{
			if (tmp->element == val)
			{
				pre = head;

				while (pre->next != tmp) //없앨 노드 직전 노드 찾기
					pre = pre->next;

				pre->next = tmp->next; //없앨 노드의 이전 노드와 다음 노드 연결
				free(tmp);
				return;
			}

			tmp = tmp->next;
		}

		if (tmp == NULL)
			printf("해당 데이터가 리스트에 없습니다.\n\n");
	}
}

//리스트 데이터 검색
void search_list(node* head, int val)
{
 	node* cur = head; 
	int n = 1;  // ?번째 노드를 나타내는 변수
	while (cur != NULL) {
		node* tmp = cur->next; 
		if (val == cur->element) {
			printf("%d 번째 노드에 있습니다.\n", n);
		}
		n++;
		cur = tmp;
	}
}
