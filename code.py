import math
N=1000000007
fact={}

t=int(raw_input())

while t:
	ch=raw_input()
	a={}
	n=len(ch)
	fact[n]=(math.factorial(n))%N
	for c in ch:
		if a.get(c,0):
			a[c]+=1
		else:
			a[c]=1
	den=1
	for i in a:
		y=int(a[i])
		if y>1:
			if not fact.get(y,0):
				fact[y]=(math.factorial(y))%N
			den=(den*fact[y])%N

	print(fact[n]/den)

	t-=1