#include<stdio.h>
#include<stdlib.h>
typedef struct _List {
    struct _List *next;
    int value;
} List;

void mergesort(List **headRef);
List* sort(List* a,List* b);
void FrontBackSplit(List* source,List** frontRef, List** backRef);


void mergesort(List** headRef) {
  List* head = *headRef;
  List* a;
  List* b;
 
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
  FrontBackSplit(head, &a, &b); 
 
  mergesort(&a);
  mergesort(&b);
  *headRef = sort(a, b);
}
 

List* sort(List* a,List* b) {
  List* result = NULL;
 

  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  if (a->value <= b->value)
  {
     result = a;
     result->next = sort(a->next, b);
  }
  else
  {
     result = b;
     result->next = sort(a, b->next);
  }
  return(result);
}
 

void FrontBackSplit(List* source,List** frontRef, List** backRef) {
  List* fast;
  List* slow;
  if (source==NULL || source->next==NULL)
  {

    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 

    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}


