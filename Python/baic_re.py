import re

string = "abcdefg"

m = re.match("[a-z]", string)
if m is not None:
    print (m.group())
else:
    print ("not found")

s = re.search("^[a-z][1-2]+", string+"123")
if s is not None:
    print (s.group())
else:
    print ("not found")

fa = re.findall("[a,b,g][a-z].", string)
print (fa)

fi = re.finditer("[^a]", string)
for it in fi:
    print (it.group(), it.start(), it.end(), it.span())
