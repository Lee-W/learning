a = [1, 2, 3, 4, 5]


def filterFun(x):
    return x > 3

filtered = list(filter(filterFun, a))
print (filtered)
