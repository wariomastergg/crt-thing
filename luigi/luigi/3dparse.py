def parse_obj(filename):
    vertices = []
    texture_coords = []
    normals = []
    faces = []

    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if line.startswith('v '):
                # Vertex
                vertices.append([float(x) for x in line.split()[1:]])
            elif line.startswith('vt '):
                # Texture coordinate
                texture_coords.append([float(x) for x in line.split()[1:]])
            elif line.startswith('vn '):
                # Normal
                normals.append([float(x) for x in line.split()[1:]])
            elif line.startswith('f '):
                # Face
                face = []
                for v in line.split()[1:]:
                    indices = [int(x) if x else 0 for x in v.split('/')]
                    face.append(indices)
                faces.append(face)

    return vertices, texture_coords, normals, faces

vertices, texture_coords, normals, faces = parse_obj('Documents/luigi/luigijp.obj')

#print("Vertices:", vertices)
#print("Texture Coordinates:", texture_coords)
#print("Normals:", normals)
#print("Faces:", faces)
n = 0
for i in faces:
    for o in i:
        for j in o:
            if j > n:
                n = j
#print(len(vertices))

def compare(a, b):
    if a == b or a[::-1] == b:
        return True
    else:
        return False

def mul(a, s):
    return [a[0]*s, a[1]*s]
def add(a, s):
    return [a[0]+s, a[1]+s]

edges = []

for i in range(len(faces)):
    e1 = [faces[i][0][0]-1 , faces[i][1][0]-1]
    e2 = [faces[i][1][0]-1 , faces[i][2][0]-1]
    e3 = [faces[i][2][0]-1 , faces[i][0][0]-1]
    if not ( edges.__contains__( e1 ) or edges.__contains__( e1[::-1] ) ):
        edges.append(e1)
    
    if not ( edges.__contains__( e2 ) or edges.__contains__( e2[::-1] ) ):
        edges.append(e2)
    
    if not ( edges.__contains__( e3 ) or edges.__contains__( e3[::-1] ) ):
        edges.append(e3)

#for i in vertices:
#    print("{" + f"{i[0]}, {i[1]}, {i[2]}" + "},")

#for i in vertices:
#    print("{" + f"{0}, {0}" + "},")

for i in edges:
    print("{" + f"{i[0]-144}, {i[1]-144}" + "},")

print(edges)
#edges

    


from pygame import *
from math import *
from random import *

w,h = 640,480
cx,cy = w/2,h/2
#initialize the screen
screen = display.set_mode( (w, h) )



running = True

while running:
    for i in event.get():
        if i.type == QUIT:
            running = False
    screen.fill((0,0,0))
    for i in range(len(faces)):
    
        draw.lines(screen, (255,255,255),True, [
            add(mul(vertices[faces[i][0][0]-1][0:2],500),100),
            add(mul(vertices[faces[i][1][0]-1][0:2],500),100),
            add(mul(vertices[faces[i][2][0]-1][0:2],500),100)
            ])

    display.flip() 