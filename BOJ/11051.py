from math import factorial as f
n, m = input().split()
n = int(n)
m = int(m)

print(f(n) // (f(n-m) * f(m) ))