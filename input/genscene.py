from numpy import *
from math import *

file = "scene.txt"
fout = open(file, 'a')

def outv(v, var):
    str = " %f %f %f\n" % (v[0],v[1],v[2])
    fout.write(var + str)

def outc(c, var):
    str = " %f\n" % c
    fout.write(var + str)

a = array([1,2,3])
OutVec(a, 'v')
