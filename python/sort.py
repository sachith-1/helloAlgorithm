def sort(l):
	"""
	this is a recursive function to sort an array of integers
	"""
	if not l:
		return [] 
	return sort([x for x in l if x<l[0]]) + [x for x in l if x==l[0]] + sort([x for x in l if x>l[0]])
