from queue import Queue
def minIndex(q,s_index):
    min_index=-1
    min_val=999999999
    n=q.qsize()
    for i in range(n):
        curr=q.queue[0]
        q.get()
        
        if curr<=min_val and i<=s_index:
            min_index=i
            min_val=curr
        q.put(curr)
    return min_index

def inserts(q,min_index):
    min_val=None
    n=q.qsize()
    for i in range(n):
        curr=q.queue[0]
        q.get()
        if i!=min_index:
            q.put(curr)
        else:
            min_val=curr
    q.put(min_val)
    
def sort_queue(q):
    for i in range(1,q.qsize()+1):
        min_index=minIndex(q,q.qsize()-i)
        inserts(q,min_index)
        
if __name__ == '__main__':
    q = Queue()
    q.put(21) 
    q.put(5) 
    q.put(11)
    q.put(4) 
      
    # Sort queue 
    sort_queue(q) 
      
    # Prsorted queue 
    while (q.empty() == False):
        print(q.queue[0], end = " ") 
        q.get()
  