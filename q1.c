//Write a program to find first of all non terminals in a grammar 
#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
// Function to calculate First 
void findfirst(char, int, int); 
int count, n = 0; 
// Stores the final result of the First Sets 
char calc_first[10][100]; 
// Stores the final result of the Follow Sets 
char calc_follow[10][100]; 
int m = 0; 
// Stores the production rules 
char production[10][10]; 
char f[10], first[10]; 
int k; 
char ck; 
int e; 
int main(int argc, char **argv) 
{ 
	int jm = 0; 
	int km = 0; 
	int i, choice; 
	char c, ch; 
	count = 8; 
	// The Input grammar 
	strcpy(production[0], "A=BC"); 
	strcpy(production[1], "C=+BC"); 
	strcpy(production[2], "C=e"); 
	strcpy(production[3], "B=FD"); 
	strcpy(production[4], "Y=*FY"); 
	strcpy(production[5], "Y=e"); 
	strcpy(production[6], "F=(A)"); 
	strcpy(production[7], "F=i"); 	
	int kay; 
	char done[count]; 
	int ptr = -1; 
	// Initializing the calc_first array 
	for(k = 0; k < count; k++) { 
		for(kay = 0; kay < 100; kay++) { 
			calc_first[k][kay] = '!'; 
		} 
	} 
	int p1 = 0, p2, xyz; 	
	for(k = 0; k < count; k++) 
	{ 
		c = production[k][0]; 
		p2 = 0; 
		xyz = 0; 	
		// Checking if First of c has 
		// already been calculated 
		for(kay = 0; kay <= ptr; kay++) 
			if(c == done[kay]) 
				xyz = 1; 			
		if (xyz == 1) 
			continue; 	
		// Function call	 
		findfirst(c, 0, 0); 
		ptr += 1; 
		// Adding c to the calculated list 
		done[ptr] = c; 
		printf("\n First(%c) = { ", c); 
		calc_first[p1][p2++] = c; 
		// Printing the First Sets of the grammar 
		for(i = 0 + jm; i < n; i++) { 
			int temp = 0, check = 0; 
			
			for(temp = 0; temp < p2; temp++) { 
				
				if (first[i] == calc_first[p1][temp]) 
				{ 
					check = 1; 
					break; 
				} 
			} 
			if(check == 0) 
			{ 
				printf("%c, ", first[i]); 
				calc_first[p1][p2++] = first[i]; 
			} 
		} 
		printf("}\n"); 
		jm = n; 
		p1++; 
	} 
	
} 
void findfirst(char c, int q1, int q2) 
{ 
	int j; 
	// The case where we 
	// encounter a Terminal 
	if(!(isupper(c))) { 
		first[n++] = c; 
	} 
	for(j = 0; j < count; j++) 
	{ 
		if(production[j][0] == c) 
		{ 
			if(production[j][2] == 'e') 
			{ 
				if(production[q1][q2] == '\0') 
					first[n++] = 'e'; 
				else if(production[q1][q2] != '\0'
						&& (q1 != 0 || q2 != 0)) 
				{ 
					// Recursion to calculate First of New 
					// Non-Terminal we encounter after epsilon 
					findfirst(production[q1][q2], q1, (q2+1)); 
				} 
				else
					first[n++] = 'e'; 
			} 
			else if(!isupper(production[j][2])) 
			{ 
				first[n++] = production[j][2]; 
			} 
			else
			{ 
				// Recursion to calculate First of 
				// New Non-Terminal we encounter 
				// at the beginning 
				findfirst(production[j][2], j, 3); 
			} 
		} 
	} 
} 

