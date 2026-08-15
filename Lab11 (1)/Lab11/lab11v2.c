#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPS 10
#define MAX_NAME_LEN 20

/* ---- Struct Definitions (Given) ---- */

typedef struct package {
    char name[MAX_NAME_LEN];
    struct package* dependencies[MAX_DEPS];
    int dep_count;
} package_t;

typedef struct node {
    package_t* data;
    struct node* next;
} node_t;

typedef struct developer {
    char name[30];
    package_t* installed[MAX_DEPS];
    package_t* to_install[MAX_DEPS];
    int inst_count;
    int want_count;
} developer_t;


/* ---- Provided Helper Functions ---- */

int getnextline(FILE* fp, char* buffer)
{
    if (fgets(buffer, 1000, fp) == NULL)
        return 0;

    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    return 1;
}

void splitline(char* line, char parts[][MAX_NAME_LEN], int* number_of_parts)
{
    *number_of_parts = 0;
    char* token = strtok(line, " \t");
    while (token != NULL && *number_of_parts < MAX_DEPS + 1) {
        strcpy(parts[*number_of_parts], token);
        (*number_of_parts)++;
        token = strtok(NULL, " \t");
    }
}


/* ---- Function Prototypes ---- */

node_t* read_packages(char* filename);
void check_installations(developer_t* developers, int num_developers, node_t* package_list);


/* ---- Main Function (Do Not Change) ---- */

int main(void)
{
    node_t* package_list = read_packages("packages.txt");

    if (package_list == NULL) {
        printf("Error: Could not read packages or file not found.\n");
        return 1;
    }

    printf("Loaded packages:\n");
    node_t* current = package_list;
    while (current != NULL) {
        printf("  %s", current->data->name);
        if (current->data->dep_count > 0) {
            printf(" (depends on:");
            for (int i = 0; i < current->data->dep_count; i++)
                printf(" %s", current->data->dependencies[i]->name);
            printf(")");
        }
        printf("\n");
        current = current->next;
    }

    developer_t developers[2];

    strcpy(developers[0].name, "Alice");
    developers[0].inst_count = 2;
    developers[0].want_count = 1;

    strcpy(developers[1].name, "Bob");
    developers[1].inst_count = 1;
    developers[1].want_count = 2;

    current = package_list;
    while (current != NULL) {
        if (strcmp(current->data->name, "gcc") == 0) {
            developers[0].installed[0] = current->data;
            developers[1].installed[0] = current->data;
        }
        if (strcmp(current->data->name, "make") == 0) {
            developers[0].installed[1] = current->data;
        }
        if (strcmp(current->data->name, "cmake") == 0) {
            developers[0].to_install[0] = current->data;
        }
        if (strcmp(current->data->name, "cmake") == 0) {
            developers[1].to_install[0] = current->data;
        }
        if (strcmp(current->data->name, "valgrind") == 0) {
            developers[1].to_install[1] = current->data;
        }
        current = current->next;
    }

    printf("\nDevelopers who cannot install all desired packages:\n");
    check_installations(developers, 2, package_list);

    current = package_list;
    while (current != NULL) {
        node_t* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}


/* ---- TODO: Implement These Functions ---- */

/*
 * TODO: Helper function to find a package by name
 */
package_t* find_package(node_t* head, char* name) {
    node_t* current = head;
    while (current != NULL) {
        if (strcmp(current->data->name, name) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}


/*
 * TODO: Implement read_packages
 */
node_t* read_packages(char* package)
{
    FILE* fp = fopen("packages.txt", "r");
    if (fp == NULL) return NULL;

    node_t* head = NULL;
    node_t* tail = NULL;
    char line[1000];
    char parts[MAX_DEPS + 1][MAX_NAME_LEN];
    int num_parts;

    while (getnextline(fp, line)) {
        splitline(line, parts, &num_parts);
        if (num_parts == 0) continue;

        package_t* new_pkg = (package_t*)malloc(sizeof(package_t));
        strcpy(new_pkg->name, parts[0]);
        new_pkg->dep_count = num_parts - 1;

        for (int i = 0; i < new_pkg->dep_count; i++) {
            new_pkg->dependencies[i] = find_package(head, parts[i + 1]);
        }

        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = new_pkg;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    fclose(fp);
    return head;
}

/*
 * TODO: Implement check_installations
 */
void check_installations(developer_t* developers, int num_developers, node_t* package_list)
{
    for (int i = 0; i < num_developers; i++) {
        int can_install_all = 1;

        for (int j = 0; j < developers[i].want_count; j++) {
            package_t* pkg_to_install = developers[i].to_install[j];

            for (int k = 0; k < pkg_to_install->dep_count; k++) {
                package_t* needed_dep = pkg_to_install->dependencies[k];
                int found = 0;

                // Requirement: Use pointer comparison (==)
                for (int m = 0; m < developers[i].inst_count; m++) {
                    if (developers[i].installed[m] == needed_dep) {
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    can_install_all = 0;
                    break;
                }
            }
            if (!can_install_all) break;
        }

        if (!can_install_all) {
            printf("%s\n", developers[i].name);
        }
    }
}
