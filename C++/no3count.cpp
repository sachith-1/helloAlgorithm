# Python program to count numbers upto n that don't contain 3

# Returns count of numbers which are in range from 1 to n
# and don't contain 3 as a digit
def count(n):
	
	# Base Cases ( n is not negative)
	if n < 3:
		return n
	elif n >= 3 and n < 10:
		return n-1
		
	# Calculate 10^(d-1) ( 10 raise to the power d-1 ) where d
	# is number of digits in n. po will be 100 for n = 578
	
	po = 1
	while n/po > 9:
		po = po * 10
	
	# Find the MSD ( msd is 5 for 578 )
	msd = n/po
	
	if msd != 3:
		# For 578, total will be 4*count(10^2 - 1) + 4 + ccount(78)
		return count(msd) * count(po-1) + count(msd) + count(n%po)
	else:
		# For 35 total will be equal to count(29)
		return count(msd * po - 1)
		
# Driver Program
n = 578
print count(n)


