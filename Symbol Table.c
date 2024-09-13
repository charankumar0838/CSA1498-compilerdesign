#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
struct SymbolTableEntry {
char name[50];
char type[20];
int size;
int address; // Address field (replaces scope)
};
struct SymbolTableEntry symbolTable[MAX];    
int count = 0;

void insert(char name[], char type[], int size, int address) {
for (int i = 0; i < count; i++) {
    if (strcmp(symbolTable[i].name, name) == 0) {
        printf("Error: Symbol '%s' already exists in the table.\n", name);
        return;
    }
}
strcpy(symbolTable[count].name, name);
strcpy(symbolTable[count].type, type);
symbolTable[count].size = size;
symbolTable[count].address = address;
count++;
printf("Symbol '%s' inserted successfully.\n", name);
}
void search(char name[]) {
for (int i = 0; i < count; i++) {
    if (strcmp(symbolTable[i].name, name) == 0) {
        printf("Symbol found: Name = %s, Type = %s, Size = %d, Address = %d\n",
               symbolTable[i].name, symbolTable[i].type, symbolTable[i].size, symbolTable[i].address);
        return;
    }
}
printf("Symbol '%s' not found in the symbol table.\n", name);
}
void display() {
if (count == 0) {
    printf("Symbol table is empty.\n");
    return;
}
printf("\nSymbol Table:\n");
printf("---------------------------------------------------\n");
printf("| %-10s | %-10s | %-6s | %-10s |\n", "Name", "Type", "Size", "Address");
printf("---------------------------------------------------\n");
for (int i = 0; i < count; i++) {
    printf("| %-10s | %-10s | %-6d | %-10d |\n", symbolTable[i].name, symbolTable[i].type, symbolTable[i].size, symbolTable[i].address);
}
printf("---------------------------------------------------\n");
}
int main() {
int choice;
char name[50], type[20];
int size, address;
while (1) {
    printf("\nSymbol Table Operations:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the symbol name: ");
            scanf("%s", name);
            printf("Enter the symbol type: ");
            scanf("%s", type);
            printf("Enter the symbol size: ");
            scanf("%d", &size);
            printf("Enter the symbol address: ");
            scanf("%d", &address);
            insert(name, type, size, address);
            break;
        case 2:
            printf("Enter the symbol name to search: ");
            scanf("%s", name);
            search(name);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
    }
}
return 0;
}
