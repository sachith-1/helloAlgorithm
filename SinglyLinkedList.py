
class Node:
  def __init__(self,data):
    self.data = data
    self.next = None


class Link1:
  def __init__(self):
    self.head = None


  def getlength(self):
    count = 0
    n=self.head

    while n is not None:
      count = count+1
      n=n.next

    
    return count

  
  def printLL(self):

    if self.head is None:
      print("Empty list")
      return

    else:
      n=self.head
      while n is not None:
        print(n.data)
        n=n.next

  def addB(self,data):
    new_node = Node(data)
    new_node.next = self.head
    self.head = new_node

  def addE(self,data):
    new_node = Node(data)
    n = self.head
    if self.head is None:
      self.head = new_node
    while n.next is not None:
       n=n.next

    n.next = new_node

  def search(self,data):
    n=self.head
    while n is not None:
      if n.data == data:
        print("yes, it's here")
        return
      else:
        n=n.next

    if n is None:
      print("No, it's not here")

  def addAN(self,data,N):
    new_node = Node(data)
    n=self.head

    if self.head is None:
      print("empty")
      return


    while n is not None:
      if n.data == N:
        new_node.next = n.next
        n.next = new_node
        return

      else:
        n=n.next

      if n is None:
         print("Node isn't Exist")


  def addBN(self,data,N):
    new_node = Node(data)
    n=self.head

    if self.head is None:
      print("empty")
      return

    if n.data==N:
      new_node.next = self.head
      self.head = new_node

    else:

      while n.next is not None:

        if n.next.data==N:
          new_node.next = n.next
          n.next = new_node
          return
         

        else:
          n=n.next

      if n.next is None:
         print("Node isn't Exist")


  def DelB(self):

    if self.head is None:
      print("empty")
      return

    else:
      
      self.head = self.head.next
      return

  def DelE(self):
    n = self.head
    if self.head is None:
      print("empty")
      return

    if self.head.next is None:
      self.head=None
      return

    else:
      while n.next.next is not None:
        n = n.next

      n.next = None


  def DelNode(self,N):
    n = self.head

    if self.head is None:
      print("empty")
      return

    else:

      if self.head.data == N:
        self.head = self.head.next
        return

      while n.next is not None:
        if n.next.data == N:
          n.next = n.next.next
          return
        else:
          n=n.next

      if n.next is None:
        print("Node is not there")
        return


  def addIndex(self,index,data):

    count = self.getlength()

    if index < 0 or index>count:
      print("Invalid")
      return

    if index == 0:
      self.addB(data)
      return

    else:

      k=0
      n=self.head

      while n is not None:

        if k == index-1:
          self.addAN(data,n.data)
          return

        else:
          k=k+1
          n=n.next


  def DelIndex(self,index):
    
    count = self.getlength()

    if index < 0 or index>=count:
      print("Invalid")
      return

    if index == 0:
      self.DelB()
      return

    else:

      k=0
      n=self.head

      while n is not None:

        if k == index:
          self.DelNode(n.data)
          return

        else:
          k=k+1
          n=n.next



  def rotateK(self,k):
    
    if self.head is None:
      print("empty")
      return

    for i in range(k):
      data = self.head.data
      self.DelB()
      self.addE(data)


      

  def reverse(self):

    if self.head is None:
      print("empty")
      return

    l=self.getlength()

    n=self.head

    while n.next is not None:
      n = n.next

    Ldata = n.data

    for i in range(l-1):

      data = self.head.data
      self.DelB()
      self.addAN(data,Ldata)

  def reverse2(self):
        prev = None
        current = self.head
        while(current is not None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev
   

 


LL = Link1()

LL.addB(10)
LL.addE(70)
LL.addBN(20,10)
LL.addAN(100,70)
LL.addIndex(4,60)
LL.DelIndex(5)



LL.search(100)
 

LL.printLL()
LL.reverse2()
print('\n')
LL.printLL()




