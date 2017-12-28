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

if __name__=='__main__':
    h=Heap(5);
    h.printHeap()
    h.decKey(1, 3);
    h.printHeap();
    h.decKey(0, -10);
    h.printHeap();
    h.decKey(2, -11);
    h.printHeap();
    h.decKey(1, -12);
    h.printHeap();
    print(h.extractMin());
    h.printHeap();
    h.decKey(4, -13);
    h.decKey(3, -100);
    print(h.extractMin());
    h.printHeap();
    print(h.empty());
    print(h.extractMin());
    h.printHeap();
    print(h.empty());
    print(h.extractMin());
    print(h.extractMin());
    print(h.empty());
