void sortList(Node **head)
{
    // Your Code Here
    Node *prev = (*head);
    Node *curr = (*head)->next;

    // Traverse list
    while (curr != NULL)
    {
        // If curr is smaller than prev, then
        // it must be moved to head
        if (curr->data < prev->data)
        {
            // Detach curr from linked list
            prev->next = curr->next;

            // Move current node to beginning
            curr->next = (*head);
            (*head) = curr;

            // Update current
            curr = prev;
        }

        // Nothing to do if current element
        // is at right place
        else
            prev = curr;

        // Move current
        curr = curr->next;
    }
}