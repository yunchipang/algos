#include <stdio.h>
  
void hanoi_tower(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    hanoi_tower(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    hanoi_tower(n-1, aux_rod, to_rod, from_rod);
}
  
int main()
{
    int n = 4; 			// Number of disks
    char s = 'S';		// S: Source rods
    char d = 'D';		// D: Destination rod 
    char e = 'E'; 		// E: Extra rod

    hanoi_tower(n, s, d, e);  
    return 0;
}
