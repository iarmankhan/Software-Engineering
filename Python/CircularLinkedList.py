class Node:

    def __init__(self, data=None):
        self.data = data
        self.next = None

    def __repr__(self):
        return repr(self.data)

class CircularLinkedList:

    def __init__(self):
        self.head = None

    def __repr__(self):
        nodes = []
        temp = self.head 
        if self.head is not None: 
            while(True): 
                nodes.append(repr(temp)) 
                temp = temp.next
                if (temp == self.head): 
                    break 
        return '[ ' + ', '.join(nodes) + ' ]'

    
    def pushFront(self, data):
        node = Node(data);
        if(self.head is None):
            self.head = node
            node.next = self.head
        else:
            node.next =



    def topFront(self):
        return self.head
    
    def popFront(self):

            
