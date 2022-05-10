import numpy as np

# print('hi')

n = int(input())

r = int(input().split()[0])

result = []
for row in range(r):
	result.append(input().split(' '))
result = np.array(result).astype(float)
# print(result.dtype)
for _ in range(n - 1):
	r = int(input().split()[0])

	mat = []
	for row in range(r):
		mat.append(input().split(' '))
	mat = np.array(mat).astype(float)
	# print(mat)
	result = result@mat

print(result)