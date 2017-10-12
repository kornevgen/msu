#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {start_str_size = 8};

struct tree_node 
{
    char *string;
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
};

char 
*read_line (void)
{
    int str_size =  start_str_size, move = 0;
    int flag = 1, more_then_once = 0;
    char *global_line, *tmp;
    if (!(tmp = calloc (str_size + 1, sizeof(*tmp)))) {
        return NULL;
    }
    global_line = tmp;  
    flag = 1;
    while (flag && fgets(global_line + move, str_size + 1, stdin)) {
        for(unsigned int i = move; flag && i < (str_size + move); i++) {
            if (global_line[i] == '\n') {
                global_line[i] = '\0';
                flag = 0;
            }
        }
        if (flag) {
            if (more_then_once) {
                str_size = str_size * 2;
            }
            move = str_size; 
            if (!(tmp = realloc (global_line,(2 * str_size + 1)*(sizeof(*global_line))))) {
                free(global_line);
                return NULL;
            }
            global_line = tmp;
        }
        more_then_once = 1;
    }
    if (!more_then_once) {
        free(global_line);
        return NULL;
    }
    if ((tmp = realloc(global_line, (strlen(global_line) + 1)*sizeof(*global_line)))) {
        global_line = tmp;
    }
    return global_line;
}

struct tree_node 
*create_empty_tree (void) 
{
    struct tree_node *new_tree;
    if (!(new_tree = calloc (1, sizeof(*new_tree)))) {
        return NULL;
    } else {
        return new_tree;
    }
}

struct tree_node
*add_node (struct tree_node *root, char *new_str)
{
    if (!root || !new_str) {
        return NULL;
    }
    if (!root->string) {
        root->string = new_str;
        return root;
    }
    struct tree_node *crr_node = root, *tmp;
    int res;
    while (crr_node != NULL) {
        res = strcmp (crr_node->string, new_str);
        if (res == 0) {
            crr_node = NULL;
        } else if (res > 0) {
            tmp = crr_node;
            crr_node = crr_node->left;
        } else {
            tmp = crr_node;
            crr_node = crr_node->right;
        }
    }
    if (res == 0) {
        free (new_str);
        return root;
    } else {
        if (!(crr_node = calloc(1, sizeof(*tmp)))) {
            return NULL;
        } else {
            crr_node->string = new_str;
            crr_node->parent = tmp;
            if (strcmp(tmp->string, new_str) > 0) {
                tmp->left = crr_node;
            } else {
                tmp->right = crr_node;
            }
        }
    }
    return root;
}

struct tree_node
*erase_node (struct tree_node *root, char *erase_str)
{
    if (!root || !erase_str) {
        return NULL;
    }
    if (!root->string) {
        return NULL;
    }
    struct tree_node *crr_node = root, *tmp, *tmp1;
    int res;
    while (crr_node != NULL) {
        res = strcmp (crr_node->string, erase_str);
        if (res == 0) {
            tmp = crr_node;
            crr_node = NULL;
        } else if (res > 0) {
            crr_node = crr_node->left;
        } else {
            crr_node = crr_node->right;
        }
    }
    if (res == 0) {
        crr_node = tmp;
        if (crr_node->string) {   
            free (crr_node->string);
            crr_node->string = NULL;
        }
        if (crr_node->left == NULL && crr_node->right == NULL) {
            if (crr_node->parent) {
                if (crr_node->parent->left == crr_node) {
                    crr_node->parent->left = NULL;
                    free(crr_node);
                } else {
                    crr_node->parent->right = NULL;
                    free(crr_node);
                }
            }
        } else if (crr_node->left == NULL || crr_node->right == NULL) {
            if (crr_node->left == NULL) {
                tmp1 = crr_node->right;
            } else {
                tmp1 = crr_node->left;
            }
            if (!crr_node->parent) {
                tmp = tmp1;
                crr_node->string = tmp->string;
                crr_node->right = tmp->right;
                crr_node->left = tmp->left;
                if (crr_node->left) {
                    crr_node->left->parent = crr_node;
                } 
                if (crr_node->right) {
                    crr_node->right->parent = crr_node;
                } 
                free(tmp);
            } else if (crr_node->parent->left == crr_node) {
                crr_node->parent->left = tmp1;
                tmp1->parent = crr_node->parent;
                free(crr_node);
            } else {
                crr_node->parent->right = tmp1;
                tmp1->parent = crr_node->parent;
                free(crr_node);
            }
        } else {
            tmp1 = crr_node->right;
            while (tmp1->left != NULL) {
                tmp1 = tmp1->left;
            }
            if (crr_node->right == tmp1) {
                crr_node->string = tmp1->string;
                crr_node->right = tmp1->right;
                if (tmp1->right) {
                    tmp1->right->parent = crr_node;
                }
            } else {
                crr_node->string = tmp1->string;
                tmp1->parent->left = tmp1->right;
                if (tmp->right) {
                    tmp->right->parent = tmp1->parent;
                }
            }
        }
        
    }
    return root;
}

int 
in_tree (struct tree_node *root, char *tgt_str)
{
    if (!root || !tgt_str) {
        return 0;
    }
    if (!root->string) {
        return 0;
    }
    struct tree_node *crr_node = root;
    int res = 1;
    while (crr_node != NULL) {
        res = strcmp (crr_node->string, tgt_str);
        if (res == 0) {
            crr_node = NULL;
        } else if (res > 0) {
            crr_node = crr_node->left;
        } else {
            crr_node = crr_node->right;
        }
    }
    if (res) {
        return 0;
    } else {
        return 1;
    }
}

void
show (struct tree_node *root) 
{
    if (root) {
        show(root->left);
        if (root->string) {
            printf("%s\n", root->string);
        }
        show(root->right);
    }
}

void
destroy (struct tree_node *root)
{
    if (root) {
        destroy(root->right);
        destroy(root->left);
        if (root->string) {
            free(root->string);
        }
        free(root);
    }
}

int
main (void)
{
    struct tree_node *main_tree;
    char *input_str;
    if (!(main_tree = create_empty_tree())) {
        return 1;
    }   
    while ((input_str = read_line())) {
        if (in_tree(main_tree, input_str)) {
            erase_node (main_tree, input_str);
            free(input_str);
        } else {
            add_node(main_tree, input_str);
        }
    }
    show(main_tree);
    destroy(main_tree);
    return 0;
}
