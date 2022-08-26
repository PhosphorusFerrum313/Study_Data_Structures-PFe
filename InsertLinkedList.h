#pragma once

//단순- 연결리스트 노드구조, 구조체로 정의
typedef struct ListNode {
	//앞자리 char형 4바이트사용
	char data[4];
	//이것을 구조체, Link로 정의
	struct ListNode* link;
	//전역변수 선언
}listNode;

// 리스트 이니시에이트 노드인 head를 구조체로 정의
typedef struct {
	//리스트 노드의 헤더 선언
	listNode* head;
}linkedList_h;

//LLH 구조체, CLL헤더, 입력값없음
linkedList_h* createLinkedList_h(void);

//함수들은 선언, 입력값을 LLH의 헤더값 포인터로 받는다. 이제 L은...
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h* L);
//LLH 헤더 주소값과, 아까만든 4바이트짜리 구조체입력값받는다.
void insertFirstNode(linkedList_h* L, char* x);
//LLH 헤더 주소값, 그 주소값의 전 주소값, 4바이트짜리 구조체입력값 받는다.
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);
//LLH 헤더 주소값, 그리고 구조체 입력값 받는다.
//마지막 입력값이므로, 어처피 NULL임.
void insertLastNode(linkedList_h* L, char* x);
//LLH 헤더 주소값 L, 리스트노드 포인터 p 선언
void deleteNode(linkedList_h* L, listNode* p);
//리스트노드 구조체 - 명칭 :서치노드 - 링크드리스트 헤더파일 L선언, 데이터값
listNode* searchNode(linkedList_h* L, char* x);
//링크드리스트 구조체의 헤더 포인터 L선언
void reverse(linkedList_h* L);
