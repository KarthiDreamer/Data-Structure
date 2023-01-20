# TowerOfHanoi using python

def TowerOfHanoi(n,src,dst,temp):
    if n==0:
        return

    #swap dst and temp , n=n-1
    TowerOfHanoi(n-1,src,temp,dst)

    print("The rod {} is moved from {} to {} ".format(n,src,dst))

    #swap src and temp , n=n-1
    TowerOfHanoi(n-1,temp,dst,src)

N=3

TowerOfHanoi(N,'A','C','B')