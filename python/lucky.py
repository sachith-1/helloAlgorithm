# Python program to check for lucky number

def isLucky(n):
	
	
	
	if isLucky.counter > n:
		return 1
	if n % isLucky.counter == 0:
		return 0
	
	
	next_position = n - (n/isLucky.counter)
	
	isLucky.counter = isLucky.counter + 1
	
	return isLucky(next_position)
	
	
# Driver Code

isLucky.counter = 2 # Acts as static variable
x = 5
if isLucky(x):
	print x,"is a Lucky number"
else:
	print x,"is not a Lucky number"
	

