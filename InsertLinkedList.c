// 리눅스 쓸때는 필요없음.
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//아까 만든 헤더파일 추가
#include "InsertLinkedList.h"

//공백 연결리스트 생성 연산

//헤더에서 정의한 LLH함수 정의
linkedList_h*createLinkedList_h(void){
	//링크드리스트 헤더파일의 포인터는 L이다 = 주소값이 L에 있다.
	linkedList_h* L;
	//L의 메모리를 할당한다.
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	// 공백리스트= 비어있음 NULL = L의 헤더는 비어있다
	L->head = NULL;
	//헤더가 NULL인 L을 리턴한다.
	return L;
}

// 연결리스트 전체메모리 해제 연산

//아까 선언한것의 정의
void freeLinkedList_h(freeLinkedList_h*L){
	//리스트 노드의 포인터값 p를 선언, 이것은 L의 전 주소값
	listNode* p;
	//L의 헤더값이 NULL이 될때까지 = 시작부터 끝까지 반복
	while(L->head !=NULL){
		// p는 L의 헤더값을 갖는다.
		p = L->head;
		//L의 헤더값은 L의 헤더값의 링크값이다
		L->head = L->head->link;
		//동적할당 해제 = 메모리가 있었는데요, 없었습니다.
		free(p);
		//p값을 NULL로 바꾼다. 초기화.
		p = NULL;
	}
}

//연결리스트 순서대로 출력하는 연산

//아까 헤더파일에다 선언해놓은 그것을 정의.
void printlist(linkedList_h* L) {
	//리스트노드의 포인터 p선언
	listNode* p;
	// L=( 출력. 그냥 문자를 출력한것.
	printf("L=(");
	//p에 L의 헤더값을 넣는다.
	p = L->head;
	// p에 L의 헤더값이 들어가는데. 헤더값이 NULL이면 마지막이니까, 아닐때까지
	while (p != NULL) {
		//p의 맴버인 데이터값을 출력한다.
		printf("%s", p->data);
		//p는 p의 멤버인 Link의 값을 갖는다.
		p = p->link;
		//만일 p의값이 NULL이 아니라면 = 끝이 아니라면 콤마를 출력한다.
		if (p != NULL) printf(",");
	}
	//아까 L=( 을 출력한것을 닫는모양을 만들기위해 출력.
	printf(")\n");
	}
//헤더파일에서 선언한것에 대한 정의, 이번에는 해당값의 데이터값을 갖는다.
void insertFirstNode(linkedList_h*L,char*x){
	//리스트노드의 포인터 newmode 선언.
	listNode* newNode;
	//뉴 노드에다가 listnode 포인터만큼 동적할당
	newNode = (listNode*)malloc(sizeof(listNode));
	//뉴 노드와 데이터를 붙인다. 뉴노드는 아무것도없었으니까 사실상 대입인가?
	strcpy(newNode->data, x);
	//뉴 노드의 멤버인 link는 L의 멤버인 헤더값을 갖는다.
	newNode->link = L->head;
	}

//노드를 pre 뒤에 삽입하는 연산.

// 헤더에 선언한것에 대한 정의, 이번에는 리스트노드의 포인터 pre가 추가되었다.
void insertMiddleNode(linkedList_h*L,listNode*pre,char*x){
	//리스트 노드의 포인터 뉴노드선언
	listNode* newNode;
	//뉴 노드 동적할당
	newNode = (listNode*)malloc(sizeof(listNode));
	//뉴 노드의 맴버인 data에 data인 x값을 붙인다.
	strcpy(newNode->data, x);
	//만약 L의 헤더값이 NULL이라면, 마지막인것이므로. newNode의 링크값을 NULL로.
	if (L->head == NULL) {
		newNode->link = NULL;
		//L의 헤더값은 newNode값을 갖는다. 사실상 종료인가?
		L->head = newNode;
	}
	//마지막 노드도 아니고, 전 노드값이 NULL이었다면? 이미 끝나있는것이니...
	else if(pre == NULL){
		//뉴노드 링크값은 L의 헤더값 = NULL
		newNode->link = L->head;
		//L의 헤더값은 newNode값을 갖는다. 사실상 종료인가?
		L->head = newNode;
	}
	//이제 끝이 아니라는걸 알았으니까, 노드를 연결한다.
	else {
		//뉴 노드링크는 pre의 링크다.
		newNode->link = pre->link;
		//pre의 링크값에 newNode의 값이 나타내는것 = listnode의 주소값을 넣는다
		pre->link = newNode;
	}


	//마지막 노드를 삽입하는 연산

	//마지막이라, pre 노드값이 필요없음.
	void insertLastNode(linkedList_h*L,char*x){
		//리스트노드의 포인터값, 뉴노드선언
		listNode *newNode;
		//임시보관용 temp
		listNode *temp;
		//언제나 그렇듯 동적할당
		newNode = (listNode*)malloc(sizeof(listNode));
		//뉴노드의 멤버인 데이터에 데이터값 x를 넣는다.
		strcpy(newNode->data, x);
		//마지막 이니까, 링크값에 NULL 넣음.
		newNode->link = NULL;
		//만일, 현재리스트가 공백이라면 = 끝이라면.
		if(L->head ==NULL){
			//이 노드는 리스트의 시작노드로 연결된다.
			L->head = newNode;
			//종료
			return;
	}
		//현재리스트가 공백이 아니라면 = 끝이 아니라면
		else
		//임시저장한 temp값에 L의 헤더값을 넣습니다.
		temp = L->head;
		//링크값이 NULL이 나올때까지 돌린다.
		while (temp->link != NULL)
			//temp에 temp의 링크값을넣는다.
			temp = temp->link;
		//temp의 link가 NULL = 마지막값 이므로
		//temp의 link에 newNode 값을 박는다.
		temp->link = newNode;
}

	void deleteNode(linkedList_h*L.listNode*p){
		//리스트노드의 포인터 pre선언
		listNode* pre;
	//만일 L의 헤더값이 NULL이라면 = 공백리스트 = 없음 = 삭제 할 이유없음
	if (L->head == NULL)return;

	//만일 L의 링크값이 NULL이라면 = 노드에 하나만 있다면
	if (L->head->link == NULL) {
		//L의 헤더값의 메모리할당 해제
		free(L->head);
		//리스트 시작포인터 NULL로 만듬.
		L->head = NULL;
		//종료
		return;
	}
	// 만일p가 NULL이라면 = 삭제할 노드가 더이상 없다면
	else if (p == NULL) return;

	else {
		//만약 그렇지않으면? 삭제할 노드 p의 선행노드 포인터 pre로 찾음.
		pre = L->head;
		//pre의 링크가 p와 맞을때까지 계속 돌린다.
		while (pre->link != p) {
			pre = pre->link;
		}
		//이제 p를 찾았으니, p의 링크를 찾아와서 다음노드를 연결한다.
		pre->link = p->link;
		//이제 찾았던건 메모리 해제해서 버린다.
		free(p);
	}

}
	//리스트노드의 포인터 searchNode 정의,리스트노드헤더, 찾을노드
	listNode* searchNode(linkedList_h* L, char* x) {
		//리스트노드 포인터값 임시보관용 temp
		listNode* temp;
		//L의 헤더값 가져옴.
		temp = L->head;
		//NULL값을 가져올때까지 = 즉, 모든리스트를 뒤져보겠다는뜻.
		while (temp != NULL) {
			//만약 temp의 data값과 찾을노드가 같다면 temp를 리턴.
			//strcmp는 두 문자가 같으면 0반환 ->
			//두문자가 같음 = temp가 찾는노드랑 같음 = 노드를찾았음
			if (strcmp(temp->data, x) == 0)return temp;
			//다르다면... temp의 링크값을 temp에 넣어서 계속찾음.
			else temp = temp->link;
		}
		//temp값을 리턴, 참고로 if문에서 찾았으면 temp를 리턴했을것.
		//제대로 찾았다면 여기있는 return을 볼 일이 없다.
		return temp;
	}

	//리스트의 노드순서를 reverse 해주는 연산.
	
	//이 이상의 설명은 생략한다
	void reverse(linkedList_h* L) {

		//퍼스트, 미들, 라스트 3개라 3개의 노드포인터를 선언함
		listNode* p;
		listNode* q;
		listNode* r;

		//포인터p를 첫번째 노드에 설정한다.
		p = L->head;
		q = NULL;
		r = NULL;

		//리스트의 첫번째 노드부터 링크를 따라 다음노드로 이동하면서
		//노드간의 연결을 바꿔준다.

		//첫번째 노드가 NULL이 아닐때까지 = 노드전체를 만나게될것
		//시작부터 헤더가 NULL로 날아갔기때문에, 링크를 헤더로만들고, 마지막으로 q에 헤더를 달아준다
		//어처피 노드의 마지막인 r의 링크는 NULL이 될거라 상관없다.
		while (p != NULL) {

			r = q;
			q = p;
			p = p->link;
		}
		
		L->head = q;
	}
