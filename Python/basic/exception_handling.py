'''
except, else, finally are optional for try-except
'''

#basic try-except
try:
    if a is 1:
        print ("a is 1")
except:
    print ("a is undefined")


#except with an error type
#else that executes when exception doesn't happen
try:
    a = 1
    if a is 1:
        print ("a is 1")
except NameError:
    print ("There is an name error")
else:
    print ("There is no exception")


#finally that always executes
try:
    #a = 1
    if a is 1:
        print ("a is 1")
except:
    print ("a is undefined")
finally:
    print ("always executes")

#raise an exception
try:
    raise NameError
except NameError:
    print ("There is an name error")
