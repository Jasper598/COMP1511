// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int b,c,d,e;
    b=0;
    c=0;
    e=0;
    while(b<length){
       d=0;
       while(d<length){
          if(source1[b]==source2[d]){
          destination[e]=source1[b];
          c++;
          d++;
          e++;
          break;}
          else {d++;}
       }
       b++;
       }
return c;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
