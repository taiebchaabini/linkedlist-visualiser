#include "main.h"

list_t *create_node(char *str)
{
    list_t *new = malloc(sizeof(list_t) * 1);

    if (new == NULL)
        return (NULL);

    new->str = str;
    new->next = NULL;

    return (new);
}

int count_nodes(list_t *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return (count);
}

void insert_node_at_index(list_t **head, char *str, unsigned int index)
{
    list_t *new = NULL;
    list_t *tmp = *head;
    unsigned int i = 0;

    new = create_node(str);

    if (index == 0)
    {
        new->next = *head;
        *head = new;
        return;
    }

    while (i < index)
    {
        if (i == index - 1)
        {
            new->next = tmp->next;
            tmp->next = new;
            return;
        }
        tmp = tmp->next;
        i++;
    }
}

//
int main()
{
    /* Single linked list */
    list_t *head;

    head = create_node("Holberton");
    insert_node_at_index(&head, "School", count_nodes(head));
    insert_node_at_index(&head, "Is", count_nodes(head));
    insert_node_at_index(&head, "A great school", count_nodes(head));
    insert_node_at_index(&head, "Hello", count_nodes(head));
    insert_node_at_index(&head, "Test", count_nodes(head));

    insert_node_at_index(&head, "Fabien", 0);
    insert_node_at_index(&head, "Yoan", 2);
    insert_node_at_index(&head, "Hugo SWE", 8);

    write_json_to_file(head, 1);
    return 0;
}