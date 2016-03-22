#include "swap.c"

void bubble_sort(List **head)
{
	//check head exist
    if (head == NULL || (*head == NULL))
        return ;
	
    int num_list = 0;
    int i = 0;
    int sub_i,sub_for_Max;
    List *sub_head=*head;
	List *tmp_head;
	
	//count list size
    for (;sub_head;) {
        num_list ++;
        sub_head = sub_head->next;
    }
	tmp_head = *head;

    for (;i < num_list; i++) {
        sub_head = tmp_head;
        sub_for_Max = num_list-i-1;

        for (sub_i = 0;sub_i < sub_for_Max;sub_i++) {
            if (sub_head->value < sub_head->next->value) {
                tmp_head = swap(tmp_head,sub_head,sub_head->next);
			}
			else
            sub_head = sub_head->next;
        }
    }
	*head = tmp_head;
    return ;
}
