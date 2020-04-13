import random
from random import randrange

n_nodes = int(input("Number of nodes: "))
n_entries = int(input("Number of entries: "))

with open('input.txt', 'w') as f:
    f.write(str(n_nodes) + '\n')
    n = 0
    while n < n_entries - 1:
        f.write(str(randrange(n_nodes)) + ' ' + str(randrange(n_nodes)) + '\n')
        n += 1
    
    f.write(str(randrange(n_nodes)) + ' ' + str(randrange(n_nodes)))