def merge(A, start, end, mid):
	temp = [0]*(end-start+1)

	i,j,k = start, mid+1, 0

	while i<=mid and j<=end:
		if A[i]<=A[j]:
			temp[k] = A[i]
			k+=1
			i+=1
		else:
			temp[k] = A[j]
			k+=1
			j+=1

	while i<=mid:
		temp[k] = A[i]
		k+=1
		i+=1

	while j<=end:
		temp[k] = A[j]
		k+=1
		j+=1

	for i in range(end-start+1):
		A[start + i] = temp[i]


def mergesort(A, start, end):
	if start<end:
		mid = (start+end)//2
		mergesort(A, start, mid)
		mergesort(A, mid+1, end)
		merge(A, start, end, mid)

if __name__ == '__main__':
	print("Enter space separated list of floats:")
	A = [float(x) for x in input().split()]
	start = 0
	end = len(A) - 1
	mergesort(A, start, end)
	print(A)