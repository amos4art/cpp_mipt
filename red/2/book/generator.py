import random

with open('in.txt', 'a') as f:
    max_q = 1000000
    max_user = 100000
    page = 0
    task_list = ['CHEER', 'READ']
    
    f.write(str(max_q)+'\n')
    
    for i in range(0, max_q):
        q = random.choice(task_list)
        if q == 'CHEER':
            f.write(q + ' ' + str(random.randint(0, max_user)) + '\n')
        if q == 'READ':
            page = random.randint(0, 1000)
            f.write(q + ' ' + str(random.randint(0, max_user)) + ' ' + str(page) + '\n')