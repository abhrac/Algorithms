class Node:
    def __init__(self, label=None, weight=0):
        self.label=label;
        self.weight=weight;
        self.next=None;
    def adj(self, v, w):
        temp=Node(v, w);
        temp.next=self.next;
        self.next=temp;
    def printNode(self):
        temp=self;
        while(temp!=None):
            print((temp.label+1), "(", temp.weight, ")", end="  ");
            temp=temp.next;
        print();

def create(n):
    l=[];
    for i in range(0, n):
        l.append(Node(i));
    return l;

def addEdge(l, u, v, w):
    l[u-1].adj((v-1), w);

def display(l):
    for i in l:
        i.printNode();

class Heap:
    def __init__(self, size=0, value=100000):
        self.l=[[i, value] for i in range(0, size)];
        self.pos=[i for i in range(0, size)];
    def empty(self):
        return (len(self.l)==0);
    def parent(self, i):
        if(i!=0):
            return (((i+1)//2)-1);
        return (i);
    def filterUp(self, i):
        p=self.parent(i);
        while(i>0 and self.l[i][1]<self.l[p][1]):
            p=self.parent(i);
            self.pos[self.l[i][0]], self.pos[self.l[p][0]]=self.pos[self.l[p][0]], self.pos[self.l[i][0]];
            self.l[i], self.l[p]=self.l[p], self.l[i];
            i=p;
    def filterDown(self, root):
        min=root;
        left=(2*root)+1;
        right=(2*root)+2;
        if(left<len(self.l) and (self.l[min][1]>self.l[left][1])):
            min=left;
        if(right<len(self.l) and (self.l[min][1]>self.l[right][1])):
            min=right;
        if(min!=root):
            self.pos[self.l[min][0]], self.pos[self.l[root][0]]=self.pos[self.l[root][0]], self.pos[self.l[min][0]];
            self.l[min], self.l[root]=self.l[root], self.l[min];
            self.filterDown(min);
    def decKey(self, key, value=-100000):
        i=self.pos[key];
        if(self.l[i][1]<value):
            return;
        self.l[i][1]=value;
        self.filterUp(i);
    def extractMin(self):
        if(len(self.l)>0):
            min=self.l[0];
            self.l[0]=self.l[-1];
            self.pos[self.l[-1][0]]=0;
            del self.l[-1];
            self.filterDown(0);
        return min;
    def printHeap(self):
        print([i for i in self.l]);

def Dijkstra(graph, source):
    visited=[0 for i in range(0, len(graph))];
    h=Heap(len(graph), 100000);
    h.decKey(source, 0);
    print("Shortest paths using Dijkstra's Algorithm:");
    while(not h.empty()):
        min=h.extractMin();
        print((min[0]+1), "(", min[1], ")");
        visited[min[0]]=1
        temp=graph[min[0]].next;
        while(temp!=None):
            if(not visited[temp.label]):
                w=min[1]+temp.weight;
                h.decKey(temp.label, w);
            temp=temp.next;

if __name__=='__main__':
    n=int(input("Enter the number of vertices:"));
    graph=[];
    graph=create(n);
    e=int(input("Enter the number of edges:"));
    print("Enter the edges:");
    for i in range (0, e):
        s=input();
        edge=[int(x) for x in s.split()];
        addEdge(graph, edge[0], edge[1], edge[2]);
        addEdge(graph, edge[1], edge[0], edge[2]);
    display(graph);
    Dijkstra(graph, 0);
