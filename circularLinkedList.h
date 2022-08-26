#pragma onece
//이번에는 원형 연결리스트 노드 구조를 구조체로 정의

typedef struct ListNode{
	char data[4];
	struct Listnode *link;
} listNode;

//리스트 시작 헤더노드를 구조체로 정의
typedef struct {
	listNode *head;
}linkedList_h;

//미리 선언해놓는다
linkedList_h *createLinkedList_h(void);
//이번에는 L이 아니라 CL로 쓰는데, 아마도 Circular 때문에 그런듯하다...
void printList(linkedList_h* CL);
void insertFirstNode(linkedList_h *CL, char *x);
void insertMiddleNode(linkedList_h*CL,listNode*pre,char *x);
//라스트 노드가 없는 이유는, 원형 연결리스트의 라스트노드가 곧 퍼스트노드라서 그렇다
//그리고 딜리트노드랑 서치노드 둘다 조금씩 다르다.
void deleteNode(linkedList_h*CL,listNode*old);
listNode*searchNode(linkedList_h*CL,char*x);


