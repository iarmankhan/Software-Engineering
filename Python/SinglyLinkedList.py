class Node:
    """ 
    A node in singly linked list
    """
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __repr__(self):
        return repr(self.data)
    


class SinglyLinkedList:

    def __init__(self):
        """ 
        Creates a new singly linked list
        Takes O(1) time
        """
        self.head = None

    def __repr__(self):
        """ 
        Return a string representation of the list
        Takes O(n) time
        """
        nodes = []
        curr = self.head
        while curr:
            nodes.append(repr(curr))
            curr = curr.next
        return '[ ' + ', '.join(nodes) + ' ]'


    def prepend(self, data):
        """ 
        Insert a new element at the beginning of the list
        Takes O(1) time
        """
        self.head = Node(data, self.head)

    def append(self, data):
        """
        Insert a new element at the end of the list
        Takes O(n) time
        """
        if not self.head:
            self.head = Node(data)
            return

        curr = self.head
        while curr.next:
            curr = curr.next

        curr.next = Node(data)

    def find(self, key):
        """
        Search for the first element with data matching 
        key. Return the element or None if not found.
        Take O(n) time
        """
        curr = self.head
        while curr and curr.data != key:
            curr = curr.next

        return curr

    def remove(self, key):
        """
        Removes the first occurrence of the key in the list
        Takes O(n) time
        """
        curr = self.head
        prev = None
        while curr and curr.data != key:
            prev = curr
            curr = curr.next

        if prev is None:
            self.head = curr.next
        elif curr:
            prev.next = curr.next
            curr.next = None

    def reverse(self):
        """  
        Reverse the list in-place
        Takes O(n) time
        """
        curr = self.head
        prev_node = None
        next_node = None
        while curr:
            next_node = curr.next
            curr.next = prev_node
            prev_node = curr
            curr = next_node
        self.head = prev_node


if __name__=='__main__': 

    llist = SinglyLinkedList()
    llist.prepend(10)
    llist.prepend(20)
    llist.prepend(30)
    print(llist)
    llist.append(40)
    llist.append(50)
    llist.append(60)
    print(llist)
    llist.reverse()
    print(llist)
    llist.remove(30)
    print(llist)
    print(llist.find('X'))
