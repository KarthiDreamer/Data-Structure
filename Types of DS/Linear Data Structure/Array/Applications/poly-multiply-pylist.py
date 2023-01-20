# Addition of Polynomial

def multiPoly(poly1,poly2):
    #add two polynomials (all terms will be included in the final polynomial)
    poly3=[]

    for i in range(len(poly1)):
        for j in range(len(poly2)):
            #add the power, multiply coefficients
            poly3.append([poly1[i][0]+poly2[j][0],poly1[i][1]*poly2[j][1]])

    # sort in decending order
    poly3=sorted(poly3,key=lambda x:x[0],reverse=True)
    i=0

    #duplicate removal function
    while i<len(poly3)-1:
        #checks if next list value(polynomial) has same power
        if(poly3[i][0]==poly3[i+1][0]):
            #adds to the current coefficient and remove the polynomial(list)
            poly3[i][1]+=poly3[i+1][1]
            poly3.pop(i+1)    
        else:
            #if next one is not same power polynomial , increment to the next polynomial
            i +=1

    return poly3

def displayPoly(poly):
    print("\nThe resultant polynomial is")
    for i in poly:
        print("The power of x is ",i[0])
        print("The coefficient of x is ",i[1])

def getPoly(poly,n):
    for i in range(n):
        x = int(input("Enter the power of x: "))
        c = int(input("Enter the coefficient: "))
        poly.append([x,c])

poly1 = []
poly2 = []
poly3 = []
n1 = int(input("\nEnter the number of non zero terms in 1st polynomial: "))
getPoly(poly1,n1)

n2 = int(input("\nEnter the number of non zero terms in 2nd polynomial: "))
getPoly(poly2,n2)

poly3 = multiPoly(poly1,poly2)
displayPoly(poly3) 