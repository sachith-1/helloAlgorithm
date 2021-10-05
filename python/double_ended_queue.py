
import collections

# initializing deque
de = collections.deque([1, 2, 3])

de.extend([4, 5, 6])

# printing modified deque
print("The deque after extending deque at end is : ")
print(de)
de.extendleft([7, 8, 9])

print("The deque after extending deque at beginning is : ")
print(de)


de.rotate(-3)

# printing modified deque
print("The deque after rotating deque is : ")
print(de)

# using reverse() to reverse the deque
de.reverse()

# printing modified deque
print("The deque after reversing deque is : ")
print(de)

# get right-end value and eliminate
startValue = de.pop()

print("The deque after popping value at end is : ")
print(de)

# get left-end value and eliminate
endValue = de.popleft()

print("The deque after popping value at start is : ")
print(de)

# eliminate element searched by value
de.remove(5)

print("The deque after eliminating element searched by value : ")
print(de)
