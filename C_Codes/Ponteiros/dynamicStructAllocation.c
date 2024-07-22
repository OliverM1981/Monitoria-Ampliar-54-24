#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person *p = (struct Person*)malloc(sizeof(struct Person));
    if (p == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    strcpy(p->name, "John Doe");
    p->age = 30;

    printf("Name: %s, Age: %d\n", p->name, p->age);

    free(p);
    return 0;
}
