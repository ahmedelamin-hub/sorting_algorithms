#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: The first node
 * @node2: The second node
 * @list: A double pointer to the start of the list
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    /* Edge case: check for null pointers */
    if (!node1 || !node2 || !list)
        return;

    /* If node1 has a previous node, link it to node2 */
    if (node1->prev)
        node1->prev->next = node2;

    /* Link node2's next node to node1 */
    if (node2->next)
        node2->next->prev = node1;

    /* Swap the next and previous pointers of node1 and node2 */
    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    /* If node2 is now the first node, update the list head */
    if (!node2->prev)
        *list = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm.
 * @list: A double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    if (!list || !(*list) || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        insert = current;
        current = current->next;
        while (insert->prev && insert->n < insert->prev->n)
        {
            swap_nodes(list, insert->prev, insert);
            print_list(*list);
        }
    }
}
