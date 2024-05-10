#include<stdio.h>
#define MAXN 30045
int main() {
    int number_of_test_case, i;
    scanf("%d", &number_of_test_case);
    while (number_of_test_case--) {
        int number_of_towns_citizen, number_of_towns_people;
        scanf("%d %d", &number_of_towns_citizen, &number_of_towns_people);
        int parent[MAXN], size[MAXN];
        for (i = 0; i < number_of_towns_citizen; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        int max_size = 1;
        for (i = 0; i < number_of_towns_people; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            A--; 
            B--;

        
            while (A != parent[A]) A = parent[A];
            while (B != parent[B]) B = parent[B];

            if (A == B) continue;
            if (size[A] < size[B]) {
                parent[A] = B;
                size[B] += size[A];
                if (size[B] > max_size) max_size = size[B];
            } else {
                parent[B] = A;
                size[A] += size[B];
                if (size[A] > max_size) max_size = size[A];
            }
        }
        printf("%d\n", max_size);
    }
    return 0;
}
