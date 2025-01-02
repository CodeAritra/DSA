#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coef;
    int exp;
    struct Node* next;
};
typedef struct Node Node;
void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    if (*poly == NULL) {
        *poly = temp;
        return;
    }
    Node* current = *poly;
    while (current->next != NULL) {
        current = current->next;
    } 
    current->next = temp;
}
void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}
Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}
int main()
{
    int c,e,ch=0;
    struct Node *p1=NULL;
    struct Node *p2=NULL;
    printf("enter for polynomial 1 : ");
    printf("enter the number of terms  :");
    scanf("%d",&ch);
    while(ch>0)
    {
    	ch=ch-1;
    	printf("enter the coefficient and exponent : ");
    	scanf("%d %d",&c,&e);
    	insert(&p1,c,e);
	}
	printf("enter for polynomial 2: ");
    printf("enter the number of terms  :");
    scanf("%d",&ch);
    while(ch>0)
    {
    	ch=ch-1;
    	printf("enter the coefficient and exponent : ");
    	scanf("%d %d",&c,&e);
    	insert(&p2,c,e);
	}
	printf("\nthe first polynmial is : ");
	print(p1);
	printf("\nthe second polynmial is : ");
	print(p2);
	printf("\nTHE ADDITION OF ABOVE POLYNOMIAL IS : ");
	struct Node *temp=add(p1,p2);
	print(temp);
    return 0;
}