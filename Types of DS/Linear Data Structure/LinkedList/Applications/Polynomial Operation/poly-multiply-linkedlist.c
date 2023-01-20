#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct Term {
    int coef;   // Coefficient of the term
    int exp;    // Exponent of the term
    struct Term *next;  // Pointer to the next term
};

// Function to create a new term and add it to the polynomial
void addTerm(struct Term **poly, int coef, int exp) {
    // Allocate memory for the new term
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coef = coef;
    newTerm->exp = exp;
    newTerm->next = NULL;

    // If the polynomial is empty, add the new term to the head
    if (*poly == NULL) {
        *poly = newTerm;
        return;
    }

    // Find the correct position to add the new term
    struct Term *current = *poly;
    struct Term *prev = NULL;
    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    // Add the new term to the polynomial
        if (prev == NULL) {
        newTerm->next = current;
        *poly = newTerm;
    }
    else {
        newTerm->next = current;
        prev->next = newTerm;
    }
}

// Function to multiply two polynomials
struct Term *polyMult(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;

    struct Term *term1 = poly1;
    while (term1 != NULL) {
        struct Term *term2 = poly2;
        while (term2 != NULL) {
            int coef = term1->coef * term2->coef;
            int exp = term1->exp + term2->exp;
            addTerm(&result, coef, exp);
            term2 = term2->next;
        }
        term1 = term1->next;
    }

    return result;
}

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;

    int coef, exp;
    printf("Enter terms for polynomial 1 (end with 0 0): \n");
    scanf("%d %d", &coef, &exp);
    while (coef != 0 && exp != 0) {
        addTerm(&poly1, coef, exp);
        scanf("%d %d", &coef, &exp);
    }

    printf("Enter terms for polynomial 2 (end with 0 0): \n");
    scanf("%d %d", &coef, &exp);
    while (coef != 0 && exp != 0) {
        addTerm(&poly2, coef, exp);
        scanf("%d %d", &coef, &exp);
    }

    struct Term *result = polyMult(poly1, poly2);

    printf("Resulting polynomial: ");
    struct Term *current = result;
    while (current != NULL) {
        printf("%dx^%d ", current->coef, current->exp);
        current = current->next;
    }

    return 0;
}


