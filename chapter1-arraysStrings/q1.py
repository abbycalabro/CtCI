def isUnique(x):
    seen = set()
    return not any(i in seen or seen.add(i) for i in x)


print isUnique("ABCD")
print isUnique("ABCAD")
