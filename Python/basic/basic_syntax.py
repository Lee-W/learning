#standard iutput
a = input("Please enter a ")
#standard output
print (1,2,3, sep='@', end='\t')
print (4)


#like ? : syntax in C++
x = 'yes' if 5>3 else 'no'
print ("Is 5 lager than 3?", x)


#list handling
a = [1, 2, 3, 4, 5]
print (a)
[print(i*2, end=" ") for i in a]
print ()
[print(i*3) for i in a if i==4]


#parallel asignment
a,b,c = 1, 2, 3
print (a,b,c)


#format a string
x = 1
print ("%d" % x)


#store functions into a list is allowed
def fun1(A):
    print (A)
def fun2(B):
    print (2*B)
funList = [fun1, fun2]
funList[0](5)  # print 5
funList[1](5)  # print 10


#return the ascii code or unicode of string
ascii('嗨')


#return quotient and remainer
a = divmod(5,3)
print ("5/3", a)


#return max or min
a = [1,2,3,4,5]
M = max(a)
m = min(1,2,3,4,5)
print (M, m)


#sum
a = [1,2,3,4,5]
s = sum(a)
print (s)


#pow(x,y,z) return x^y%z which z is optional
pow(5, 2, 3)
