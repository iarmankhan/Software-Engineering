class Node:

    def __init__(self, key=None, data=None):
        self.key = key
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

    def isNodeExist(self, key):
        temp = None
        ptr = self.head

        if ptr is None:
            return temp
        else:
            while True:
                if ptr.key == key:
                    temp = ptr
            
                if ptr == self.head:
                    break
            return temp

    def pushFront(self, key, data):
        newNode = Node(key, data)
        if self.isNodeExist(newNode.key) != None:
            print("Node with key already exist")
        else:
            if self.head is None:
                self.head = newNode
                newNode.next = self.head
                print("Node pushed at front")
            else:
                ptr = self.head
                while ptr.next != self.head:
                    ptr = ptr.next
                
                ptr.next = newNode
                newNode.next = self.head
                self.head = newNode
                print("Node pushed at front")


    def topFront(self):
        return self.head

    def popFront(self):
        if self.head is None:
            return
        ptr = self.head

        while ptr.next != self.head:
            ptr = ptr.next

        ptr.next = self.head.next
        self.head = ptr


cl = CircularLinkedList()    
cl.pushFront(1, 10)
cl.pushFront(2, 11)
print(cl)
cl.popFront()
print(cl)


            
