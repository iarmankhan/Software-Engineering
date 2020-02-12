class Node:
    """ A node in doubly linked list """
    def __init__(self, data, prev=None, next=None):
        self.prev = prev
        self.data = data
        self.next = next

    def __repr__(self):
        return repr(self.data)


class DoublyLinkedList:
    def __init__(self):
        """ 
        Create a new doubly linked list
        Time O(1)
        """
        self.head = None

    def __repr__(self):
        """ 
        Return a string representation of the list
        Time O(n)
        """
        nodes = []
        curr = self.head
        while curr:
            nodes.append(repr(curr))
            curr = curr.next

        return '[ ' + ', '.join(nodes) + ' ]'

    def pushFront(self, data):
        """
        Insert a new element at the beginning
        Time O(1)
        """
        if self.head is None:
            node = Node(data, None, None)
        else:
            node = Node(data, None, self.head)
            self.head.prev = node
        self.head = node

    def topFront(self):
        """
        Return the first element of the list
        Time O(1)
        """
        return self.head

    def popFront(self):
        """ 
        Remove the first element of the list
        Time O(1)
        """
        self.head.next.prev = None
        self.head = self.head.next

    def pushBack(self, data):
        """
        Add a new element at the end of the list
        Time O(n)
        """
        if not self.head:
            self.head = Node(data)
            return
        
        curr = self.head
        while curr.next:
            curr = curr.next

        curr.next = Node(data, curr)

    def topBack(self):
        """
        Returns the last element of the list
        Time O(n)
        """
        curr = self.head
        while curr.next:
            curr = curr.next
        return curr.data

    def popBack(self):
        """
        Removes the last element of the list
        Time O(n)
        """
        curr = self.head
        while curr.next.next:
            curr = curr.next
        curr.next = None

    def isEmpty(self):
        """
        Check if list is empty or not
        Time O(1)
        """
        return True if self.head is None else False

    def addBefore(self, key, data):
        """
        Add an element before given key
        Time O(n)
        """
        curr = self.head
        if key == curr.data:
            self.pushFront(data)
            return
        while curr:
            if curr.next is None:
                break
            if curr.next.data == key:
                node = Node(data, curr.next.prev, curr.next)
                curr.next = node
                break
            else:
                curr = curr.next
        return

    def addAfter(self, key, data):
        """
        Add a new element after given key
        Time O(n)
        """
        curr = self.head
        while curr:
            if curr.data == key:
                node = Node(data, curr, curr.next)
                curr.next = node
                break
            else:
                curr = curr.next
        return

    def find(self, key):
        """
        Search for the particular key
        Time O(n)
        """
        curr = self.head
        while curr and curr.data != key:
            curr = curr.next

        return True if curr else False

    def remove(self, key):
        """
        Removes the first occurrence of the key
        Time O(n)
        """
        curr = self.head
        while curr and curr.data != key:
            curr = curr.next
        
        if not curr:
            return
        
        if curr.prev is None:
            self.head = curr.next
        elif curr.next is None:
            curr.prev.next = curr.next
        else:
            curr.prev.next = curr.next
            curr.next.prev = curr.prev
        return


if __name__ == '__main__':
    dlist = DoublyLinkedList()
    dlist.pushFront(10)
    dlist.pushFront(20)
    dlist.pushFront(30)
    dlist.pushFront(40)
    print(dlist)
    dlist.remove(10)
    print(dlist)
