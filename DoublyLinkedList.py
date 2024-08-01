class Node:
    def __init__(self, value, next = None, previous= None):
        self.value = value
        self.next = next
        self.previous = previous



class LinkedList:
    def __init__(self, head = None,tail = None):
        self.head = head
        self.tail = tail
        self.length = 0
        if(head != None):
            temp = self.head
            while(temp != None):
                self.length += 1
                if(temp.next == None):
                    tail = temp
                temp = temp.next

    def isEmpty(self):
        return self.head == None

    def insertAtStart(self, value):
        newNode = Node(value)
        if(self.isEmpty()):
            self.head = newNode
            self.tail = newNode
        else:
            newNode.next = self.head
            self.head.previous = newNode
            self.head = newNode
        self.length += 1
    
    def insertAtLast(self, value):
        newNode =Node(value)
        self.length += 1
        if(self.isEmpty()):
            self.head = newNode
            self.tail = newNode
            return
        else:
            newNode.previous = self.tail
            self.tail.next = newNode
            self.tail = newNode
            

    def deleteFromEnd(self):
        if(self.isEmpty()):
            return
        if(self.length == 1):
            self.length -=1 
            self.tail = self.head = None
            return
        secondLast = self.tail.previous
        self.tail.previous = None
        secondLast.next = None
        self.tail = secondLast
        
        self.length -= 1

    def deleteFromStart(self):
        if(self.isEmpty()):
            return
        if(self.length == 1):
            self.length -=1 
            self.tail = self.head = None
            return
        temp = self.head
        self.head = temp.next
        temp.next = None
        self.head.previous = None
        temp =None
        self.length-=1 
        
    def findNthElement(self, nth):
        if(self.length < nth):
            print(f'Length of current linkedlist is {self.length} which smaller then {nth} elemnt required')
            return
        temp = self.head
        value = None
        for i in range(1, self.length+1):
            if(i == nth):
                value = temp.value
                break
            else:
                temp = temp.next
        return value
        
    def reverse(self):
        tempList = LinkedList()
        len= self.length
        for i in range(1, len+1):
            tempList.insertAtStart(self.head.value)
            self.deleteFromStart()
        self.head = tempList.head
        self.tail = tempList.tail
        self.length = tempList.length
    
    def sortAscending(self):
        if(self.isEmpty()):
            return
        for i in range(1, self.length+1):
            back = self.head

            while(True):
                if(back.next == None):
                    break
                forward = back.next
                if(back.value > forward.value):
                    temp = back.value
                    back.value = forward.value
                    forward.value = temp
                back = back.next

    def sortDescending(self):
        if(self.isEmpty()):
            return
        for i in range(1, self.length+1):
            back = self.head

            while(True):
                if(back.next == None):
                    break
                forward = back.next
                if(back.value < forward.value):
                    temp = back.value
                    back.value = forward.value
                    forward.value = temp
                back = back.next

    def printList(self):
        temp = self.head
        while(temp != None):
            print(temp.value, end='-->')
            temp = temp.next
        print(None)

l1 = LinkedList()
for i in range(0, 10):
    l1.insertAtLast(i)
print(l1.findNthElement(10))
l1.printList()
l1.deleteFromEnd()
l1.reverse()
l1.printList()
l1.sortAscending()
l1.printList()
l1.sortDescending()
l1.printList()
l1.deleteFromEnd()
l1.deleteFromStart()
l1.printList()
l1.insertAtLast(99)
l1.printList()



