You need to design a data structure called MapSum that supports two operations:

Insert Operation: Store a key-value pair where the key is a string and the value is an integer. If the key already exists in the map, replace the old value with the new value.

Sum Operation: Given a prefix string, return the sum of all values whose keys start with that prefix.

The MapSum class should implement:

MapSum(): Constructor that initializes an empty MapSum object
insert(key, val): Adds or updates the key-value pair in the map
sum(prefix): Returns the sum of all values whose keys begin with the given prefix
For example, if you insert ("apple", 3) and ("app", 2), then calling sum("ap") would return 5 because both "apple" and "app" start with "ap", and 3 + 2 = 5.

