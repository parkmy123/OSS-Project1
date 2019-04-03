/*
	오픈소스SW 프로젝트 깃허브 체험하기 - 연결리스트 코드

	리스트 데이터 삭제 : 박문영 - parkmy123
	리스트 데이터 삽입 : 지하린 - JiHaRin
	리스트 데이터 검색 : 채윤재 - GroovyCat
	리스트 데이터 출력 : 우성 - woo sung

	뼈다구만 만든거니 각자 맡은 부분 원하시는 데로 수정하시면 됩니다. 
	다른 방식이 마음에 들면 뜯어고치시면 됩니다.
*/

#include <stdio.h>

// 노드 구조체 선언
typedef struct cell {
	int element;
	struct cell *next;
}node;

node *head = NULL;

//앞에 데이터 삽입
void insert_head_of_list(int val)
{
	printf("HAHA\n");
}

//뒤에 데이터 삽입
void insert_end_of_list(int val)
{
	printf("HAHA\n");
}

//연결리스트 출력
void print_list()
{
	printf("HAHA\n");
}

//리스트 데이터 삭제
void del_list()
{
	printf("HAHA\n");
}

//리스트 데이터 검색
void search_list()
{
	printf("HAHA\n");
}

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
		else if (check == 4)
			search_list();
		else if (check == 5)
			print_list();
		else if (check == 6)
			break;
	}

	return 0;
}
