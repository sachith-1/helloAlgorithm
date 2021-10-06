class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, data):
        self.items.append(data)

    def pop(self):
        return self.items.pop()

    def display(self):
        return self.items

s = Stack()
while True:
    print('1.push')
    print('2.pop')
    print('3.display')
    print('4.quit')
    ch = int(input('What would you like to do-'))
    if ch == 1:
        s.push(int(input("Value-")))
    elif ch == 2:
        if s.is_empty():
            print('Stack is empty.')
        else:
            print('Popped value: ', s.pop())
    elif ch == 3:
        print(s.display())
    elif ch == 4:
        print('Final Stack=',s.display())
        break
