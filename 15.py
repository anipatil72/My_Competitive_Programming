# ॥ श्री गणेशाय नमः ॥
import math

import sys


sys.set_int_max_str_digits(100000000)



def binaryExp(a, n):
    
    if (n==1):
        return a

    # end if
    if (n%2==1):
        return a*binaryExp(a, n - 1)
   
    x = binaryExp(a, n/2)

    return x*x

print(binaryExp(2, 345))
   

   # end if 


# ॥ जय श्री राम जय श्री कृष्ण ॥