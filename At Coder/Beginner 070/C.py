from functools import reduce
n=int(input())
a=[int(x) for x in input().split()]
def lcm(a, b):
    if a > b:
        greater = a
    else:
        greater = b

    while True:
        if greater % a == 0 and greater % b == 0:
            lcm = greater
            break
        greater += 1

    return lcm

def get_lcm_for(your_list):
    return reduce(lambda x, y: lcm(x, y), your_list)

ans=get_lcm_for(a)
print(ans)
