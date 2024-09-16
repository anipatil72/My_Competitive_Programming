# ॥ श्री गणेशाय नमः ॥
import math
import itertools


def subtract_strings(a, b):
    a_num = int(a)
    b_num = int(b)

    dif = a_num - b_num

    dif_s = str(dif)

    print("This is dif_s : ", dif_s)

    n = len(dif_s)

    tem = ""

    for i in range(4 - n):
        tem += '0'

    fin_dif = tem + dif_s

    return dif_s


origin = "4123"

small = ''.join(sorted(origin))
high = ''.join(sorted(origin, reverse=True))

print("This is the original string : ", origin)
print("This is the small string : ", small)
print("This is the high string : ", high)

sid = subtract_strings(high, small)


# ॥ जय श्री राम जय श्री कृष्ण ॥
