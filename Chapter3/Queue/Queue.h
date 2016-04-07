#ifndef _Queue_h
#define _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef ElementType int

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType x, Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue );

#endif