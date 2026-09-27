#include <stdio.h>

// Function prototype (declaration) so main() knows it exists
int move_disks(int n, char source, char dest, char temp);

int main() { 
    printf("dhur...\n"); 
    move_disks(5, 'S', 'D', 'T');
    return 0; 
}

// Move disks function definition
int move_disks(int n, char source, char dest, char temp) { 
    if (n > 0) { 
        move_disks(n - 1, source, temp, dest); 
        printf("\tMove disk %d from %c to %c.\n", n, source, dest);
        move_disks(n - 1, temp, dest, source); 
    } 
    return 0; 
}
