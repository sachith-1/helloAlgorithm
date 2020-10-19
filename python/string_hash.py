
MOD = int(1e9+7)
P = 31 

toint = lambda x: ord(x)-96
def make_hash(s):
	l = [0]*(len(s)+1)
	pow = [0]*(len(s)+1)
	l[0] = toint(s[0])
	pow[0] = 1  
	for i in range(1,len(s)):
		l[i] = (l[i-1]*P + toint(s[i]))%MOD
		pow[i] = (pow[i-1]*P)%MOD

	return {'hash':l,'pow':pow}

def get_hash(hdic, l, r):
	h = hdic['hash']
	p = hdic['pow']
	# H[L-1] IS JUSTIFIED FOR L=0
	return (h[r] - h[l-1]*p[r-l+1]%MOD + MOD)%MOD



# driver code: finds in how many ways a string can be split into 4 parts so that first two and last two parts are equal
def main():
	s = input()
	l = len(s)
	hdict = make_hash(s)
	ans = 0
	for i in range(2,l-1,2):
		a = 0, i//2 -1 
		b = a[1]+1, i-1
		c = i, i+(l-i)//2-1
		d = c[1]+1, l-1
		X_ = get_hash(hdict, *a)==get_hash(hdict, *b)
		_X = get_hash(hdict, *c)==get_hash(hdict, *d)
		ans += X_&_X
	print(ans)

if __name__=='__main__':
	for _ in range(int(input())):
		main()
