# Useful Python Stuff
## Websties
- [pydocs](https://docs.python.org/3/)


## Data Structs
``` python
# Tuple
mytuple = ()

# Lists
mylist = []

# Dictionaries
mydict = {}
mydict = dict()
mydict = collections.defaultdict(int)
mydict = collections.ordereddict()

# ndarray
import numpy as np
np.array([1,2,23])
```

## Strings
```python
mystring = mystring[::-1] # reverse string
mystring.strip() # remove whitespace at begin and end
mystring.replace('abc', 'new') # replace all instances
mystring.find("abs") # find index of first occurence
mystring.lower() # lowercase all characters

len(mystring) # get length of string
' '.join(mystring) # join every character my a space

```

## Useful Functions
``` python
enumerate()
zip()
map()
```

## Sorting
``` python
mylist.sort()
sorted(mylist)
```

## Searching
``` python
# linear search
if a in mylist # returns true if a in list
if substr in mystring # returns true if substr is contained within mystring
```
