#include <iostream>
#include "../HeadFile/Queue_Link.h"
using namespace std;

Status InitQueue(LinkQueue& queue) {
	queue.front = queue.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!queue.front)
		exit(OVERFLOW);
	queue.front->next = NULL;
	return OK;
} //InitQueue
Status DestroyQueue(LinkQueue& queue) {
	while (queue.front) {
		queue.rear = queue.front->next;
		free(queue.front);
		queue.front = queue.rear;
	}
	return OK;
} //DestroyQueue
Status ClearQueue(LinkQueue&);  //ClearQueue

bool QueueEmpty(LinkQueue queue) {
	return queue.front == queue.rear;
} //QueueEmpty
int QueueLength(LinkQueue queue) {
	QueuePtr p = queue.front->next;
	int j = 0;
	while (p) {
		++j;
		p = p->next;
	}
	return j;
} //QueueLength

Status GetHead(LinkQueue queue, ElemType& e){
	if (queue.front == queue.rear)
		return ERROR;
	e = queue.front->next->data;
	return OK;
}//GetHead

Status EnQueue(LinkQueue& queue, ElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	queue.rear->next = p;
	queue.rear = p;
	return OK;
} //EnQueue
Status DeQueue(LinkQueue& queue, ElemType& e) {
	if (queue.front == queue.rear)
		return ERROR;
	QueuePtr p = queue.front->next;
	e = p->data;
	queue.front->next = p->next;
	if (queue.rear == p)
		queue.rear = queue.front;
	free(p);
	return OK;
} //DeQueue

Status QueueTraverse(LinkQueue queue, int (*func)(ElemType)) {
	QueuePtr p = queue.front->next;
	while (p && !func(p->data))
		p = p->next;
	if (p)
		return ERROR;
	return OK;
} //QueueTraverse