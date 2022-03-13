a=1
b=2
num=eval(input())
while num!=1:
    num-=1
    a=a+b
    t=a
    a=b
    b=t
print(a)