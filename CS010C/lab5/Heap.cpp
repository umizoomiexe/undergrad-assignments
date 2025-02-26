//Heap.cpp

using namespace std; 

Heap::Heap() { 
    numItems = 0; 
}

void Heap::enqueue(PrintJob* newPrintJob){ 
    if(numItems >= MAX_HEAP_SIZE){ 
        return;
    }
    arr[numItems] = newPrintJob; 
    int currentIndex = numItems; 

    numItems++; 
    while (currentIndex>0 && arr[currentIndex]->getPriority() > arr[(currentIndex-1)/2]->getPriority()){ 
        swap(currentIndex, (currentIndex -1)/2);
        currentIndex = (scurrentIndex-1)/2;
    }
}

void Heap::dequeue() { 
    if(numItems>0) { 
        arr[0] = arr[numItems-1];
        numItems--;
        trickleDown(0);
    }
}

void Heap::trickleDown(int index){ 
    int largest = index;
    int left = 2* index +1;

    if(left < numItems && arr[left] -> getPriority() > arr[largest]-> getPriority()){ 
        largest = left;
    }

    if(left+1 < numItems && arr[left+1] -> getPriority() > arr[largest]-> getPriority()){
        largest = left+1; 
    }

    if(largest != index){ 
        swap(index,largest);
        trickleDown(largest);
    }
}

PrintJob* Heap::highest() { 
    if(numItems >0){ 
        return arr[0]
    }

    return nullptr;
}

void Heap::swap(int index1, int index2) { 
    PrintJob* temp = arr[index1];

    arr[index1] = arr[index2];
    arr[index2] = temp; 
}

void Heap::print() { 
    if(numItems>0) { 
        cout << "Priority: " << arr[0]-> getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() <<
    }
}