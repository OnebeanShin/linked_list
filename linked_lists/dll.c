#include <stdio.h>
#include <stdlib.h>

void init(), dll_input(), dll_print(), dll_delete();

struct DNODE{ //double linked list 선언 
	struct DNODE *llink; //왼쪽 노드를 가리키는 포인터 
	int data; //노드에 저장하는 데이터 
	struct DNODE *rlink; //오른쪽 노드를 가리키는 포인터 
} *head, *tail, *ptr;

int main(){
	init(); //초기화 해야됨 
	int index, flag = 0;
	while(flag==0){
		printf("Enter [(1)Input, (2)Print, (3)Delete, (4)Exit]: ");
		scanf("%d", &index);
		if (index==1){dll_input();}
		else if(index==2){dll_print();}
		else if(index==3){dll_delete();}
		else if(index==4){printf("Exit this Program\n"); flag=1;}
		else{printf("Enter AGain (between 1 and 4)\n");}
	}
	return 0;
}


void init(){
	head = (struct DNODE*)malloc(sizeof(struct DNODE)); //head 노드 만듬 
	tail = (struct DNODE*)malloc(sizeof(struct DNODE)); //tail 노드 만듬 
	head->data=0;
	tail->data=0;
	
	head->rlink=tail; //head의 오른쪽이 tail을 가리키게 함
	head->llink=head; //head의 왼쪽이 head를 가리키게 함
	tail->rlink=tail; //tail의 오른쪽이 tail을 가리키게 함
	tail->llink=head; //tail의 왼쪽이 head를 가리키게 함 
}

void dll_input(){ //노드 추가하는 함수 
	int in_data;
	printf("\t data: "); scanf("%d", &in_data); //data 입력받음
	struct DNODE *newnode=(struct DNODE *)malloc(sizeof(struct DNODE)); //새로운 노드 생성
	newnode->data=in_data; //새로운 노드에 data 저장 
	ptr=tail;
	ptr->llink->rlink = newnode; //ptr의 왼쪽, 즉 head의 오른쪽은 newnode를 가리킴
	newnode->llink = ptr->llink; //newnode의 왼쪽은 ptr의 왼쪽, 즉 head를 가리킴
	ptr->llink=newnode; //ptr의 왼쪽은 newnode를 가리킴 
	newnode->rlink=ptr; //newnode의 오른쪽은 ptr을 가리킴 
	
}

void dll_print(){ //출력하는 함수 
	ptr=head; //ptr이 처음을 가리킴 
	while(ptr->rlink!=tail){ //ptr이 가리키는 오른쪽 노드가 tail이 될 때까지 
		printf("%d, ", ptr->data);
		ptr = ptr->rlink; //ptr은 ptr의 오른쪽 노드를 가리킴 
	}
	printf("%d\n", ptr->data);
} 

void dll_delete(){ //삭제하는 함수 
	int delete_data;
	printf("\tdata for delete: "); scanf("%d", &delete_data); //삭제할 data 입력
	ptr = head; //ptr이 처음을 가리킴 
	while(ptr!=tail){ //ptr이 가리키는 오른쪽 노드가 tail이 될 때까지
		if(ptr->data==delete_data){ //ptr이 가리키는 노드의 data가 delete_data와 같을 때 
			ptr->rlink->llink = ptr->llink; //ptr의 오른쪽 노드의 llink가 ptr의 왼쪽 노드를 가리키게 함 
			ptr->llink->rlink = ptr->rlink; //ptr의 왼쪽 노드의 rlink가 ptr의 오른쪽 노드를 가리키게 함 
			free(ptr); //ptr이 가리키는 노드를 삭제 
			return; 
		}	
		ptr = ptr->rlink; //ptr은 ptr의 오른쪽 노드를 가리킴
	}

}
