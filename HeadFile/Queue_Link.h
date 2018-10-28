#ifndef QUEUE_LINK_H
#define QUEUE_LINK_H
#include "DS.h"
typedef struct QNode {
	ElemType data;
	struct QNode* next;
} QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;
/*				   1.front-->headnode-->QNode1-->...-->QNodeN-->0
a queue(LinkQueue)=|						   		      |
				   2.rear-------------------------->-----/
*/
Status InitQueue(LinkQueue&);
Status DestroyQueue(LinkQueue&);
Status ClearQueue(LinkQueue&);
bool QueueEmpty(LinkQueue);
int QueueLength(LinkQueue);
Status GetHead(LinkQueue,ElemType&);
Status EnQueue(LinkQueue&,ElemType);
Status DeQueue(LinkQueue&,ElemType&);
Status QueueTraverse(LinkQueue,int(*)(ElemType));
#endif