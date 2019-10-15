#include <stdio.h>
#include <stdlib.h>

struct student {
 int value;
 struct student *lchild;
 struct student *rchild;
};

void arraytotree(int *a, int len, struct student **p) {
 if(len) {
  *p = (struct student*)malloc(sizeof(struct student));
  (*p)->value = a[len/2];
  arraytotree(a, len/2, &((*p)->lchild));
  arraytotree(a+len/2+1, len-len/2-1, &((*p)->rchild));
 } else {
  *p = NULL;
 }
}

void display_tree(struct student *head) {
 if(head->lchild)display_tree(head->lchild);
 printf("%d\t", head->value);
 if(head->rchild)display_tree(head->rchild);
}

int main() {

 int a[] = {1,2,3,4,9,10,33,56,78,90};
 struct student *tree;
 arraytotree(a, sizeof(a)/sizeof(a[0]), &tree);
 printf("After convert:\n");
 display_tree(tree);
 printf("\n");
 return 0;

}
