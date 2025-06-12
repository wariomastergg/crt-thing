
from pygame import *
from math import *
from random import *

w,h = 640,480
cx,cy = w/2,h/2
#initialize the screen
screen = display.set_mode( (w, h) )
#
#vert = []
#for i in range(10):
#    f=2*pi*i/10
#    vert.append([sin(f)*3,cos(f)*3+.000001,0])
#    pass
#edg = []
#for i in range(0,len(vert)-1):
#    edg.append([i,i+1])
#
#vert = [
#    [2,2,1],
#    [-2,2,1],
#    [-2,-2,1],
#    [2,-2,1],
#    [.5,2,-1],
#    [-2,.5,-1],
#    [-.5,-2,-1],
#    [2,-.5,-1],
#    
#]


#vert = [
#    [2,2,1],
#    [-2,2,1],
#    [-2,-2,1],
#    [2,-2,1],
#    [.5,2,-1],
#    [-2,.5,-1],
#    [-.5,-2,-1],
#    [2,-.5,-1],
#    
#]
#
vert = [
    [1,1,1],
    [-1,1,1],
    [-1,-1,1],
    [1,-1,1],
    [1,1,-1],
    [-1,1,-1],
    [-1,-1,-1],
    [1,-1,-1],
    
]
edg = [
    [0,1],
    [1,2],
    [2,3],
    [3,0],

    [4,5],
    [5,6],
    [6,7],
    [7,4],

    [0,4],
    [1,5],
    [2,6],
    [3,7],
]

col = []
for i in range(len(edg)):
    col.append((randrange(0,255),randrange(0,255),randrange(0,255)))

p = []
for i in range(len(vert)):
    p.append([0,0])

#change in angle over the x axis usinng radians
ax = 0
#change in angle over the y axis usinng radians
ay = 0
#angle step
stp = radians(360)
#resize value for displaying
rz = 100

def ang(x1,y1,x2,y2):
    dx = x1-x2
    dy = y1-y2
    d = sqrt((dx)**2+(dy)**2)
    if dy >= 0:
        a = asin(dx/d)
    else:
        a = -asin(dx/d)+pi
    return [a,d,dx,dy]



drag = False
k = [0,0]
j = [0,0]
b = [0,0]

running = True

while running:
    for i in event.get():
        if i.type == QUIT:
            running = False
        
        if i.type == KEYDOWN:
            if i.key == K_RIGHT:
                k[0] += stp
            if i.key == K_LEFT:
                k[0] -= stp
            if i.key == K_UP:
                k[1] += stp
            if i.key == K_DOWN:
                k[1] -= stp
        if i.type == MOUSEBUTTONDOWN:
            drag = True
            j = [mouse.get_pos()[0]+b[0], mouse.get_pos()[1]+b[1]]
        if i.type == MOUSEBUTTONUP:
            drag = False
            b = k
    if drag:
        k[0] = j[0]-mouse.get_pos()[0]
        k[1] = j[1]-mouse.get_pos()[1]
        print(k)
    ax,ay = radians(k[0]),radians(k[1])

    screen.fill((0,0,0))
    for i in range(len(vert)):
        v = vert[i]
        c = ang(0,0,v[0],v[1])
        a,d,dx,dy = c[0],c[1],c[2],c[3]
        #u = sqrt(dx**2-v[2]*2)
        x = ( sin(a+ax)*rz*abs(v[0]) )+cx
        y = ( cos(a+ax)*rz*sin(ay)*abs(v[1])+sin(ay+v[2])*rz*abs(v[2]) )+cy
        p[i] = [x,y]
        #draw.rect(screen, (255,255,255), [x,y,10,10])
    for i in range(len(edg)):
        eg = edg[i]
        draw.line(screen, col[i], [p[eg[0]][0],p[eg[0]][1]], [p[eg[1]][0],p[eg[1]][1]])
    display.flip() 