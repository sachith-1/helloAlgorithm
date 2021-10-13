""" 1) Make n positive if n is negative.
2) If number is 0 then return 1
3) If number is 1 then return 0
4) Initialize: odd_count = 0, even_count = 0
5) Loop while n != 0
    a) If rightmost bit is set then increment odd count.
    b) Right-shift n by 1 bit
    c) If rightmost bit is set then increment even count.
    d) Right-shift n by 1 bit
6) return isMutlipleOf3(odd_count - even_count) """

# Python program to check if n is a multiple of 3

# Function to check if n is a multiple of 3
def isMultipleOf3(n):

	odd_count = 0
	even_count = 0

	# Make no positive if + n is multiple of 3
	# then is -n. We are doing this to avoid
	# stack overflow in recursion
	if(n < 0):
		n = -n
	if(n == 0):
		return 1
	if(n == 1):
		return 0

	while(n):
		
		# If odd bit is set then
		# increment odd counter
		if(n & 1):
			odd_count += 1

		# If even bit is set then
		# increment even counter
		if(n & 2):
			even_count += 1
		n = n >> 2

	return isMultipleOf3(abs(odd_count - even_count))

# Program to test function isMultipleOf3
num = 24
if (isMultipleOf3(num)):
	print(num, 'is multiple of 3')
else:
	print(num, 'is not a multiple of 3')


