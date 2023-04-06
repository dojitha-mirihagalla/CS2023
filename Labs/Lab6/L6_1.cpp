#include <iostream>
#include <vector>
using namespace std;
/*
Hacker Rank Lab 6 question 1

*/


//-----------------------------------------------------------------------------------------------
//     codes to buildup the question background


struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedListNode* head = NULL;

void insert(int x){
    struct SinglyLinkedListNode* new_node  =  (struct SinglyLinkedListNode*) malloc(sizeof(struct SinglyLinkedListNode));
    new_node->data = x;
    new_node->next =NULL;

    if(head == NULL){head =new_node;}
    else{
        struct SinglyLinkedListNode* current_node = head;
        while (current_node->next!=NULL)
        {
            current_node =  current_node->next;            
        }
        current_node->next = new_node;
    }
}
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

void print_vec_arr(vector <int> arr){
    int size = arr.size();
    for (int i = size-1; i>=0;i--){
        cout<<arr[i]<<endl;
    }
}


void reversePrint(SinglyLinkedListNode* llist){
   vector <int> temp_vec_arr ;
   struct SinglyLinkedListNode* currentnode = llist;

   while (currentnode != NULL)
   {
    temp_vec_arr.push_back(currentnode->data);
    currentnode = currentnode->next;
   }
   
    print_vec_arr(temp_vec_arr);

}



int main(){
    insert(3);
    insert(13);
    insert(23);
    insert(33);
    insert(433);

    reversePrint(head);


    return 0;
}