w,h,x,y = map(float,input().split())
if w-x==w/2 and h-y == h/2:
    print(w*h/2,"1")
else:
  	print(w*h/2,"0")