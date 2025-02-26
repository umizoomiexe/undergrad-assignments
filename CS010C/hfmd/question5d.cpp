//5-d pecolate up for heap 

void maxheap::percolate_up(int* A, int index){
   int parent_index;
   while(index > 0) {
      parent_index = (index - 1) / 2;

      if(A[index] <= A[parent_index]) {
         return;
      }

      else{
        int temp= A[index];
        A[index] = A[parent_index];
        A[parent_index] = temp;
        index = parent_index;
      }
   }
}