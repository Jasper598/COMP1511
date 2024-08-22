int remove_duplicates(int length, int source[length], int destination[length]){
   int i,j,n=length,k;
     for(i=0;i<n-1;++i) 
 {
        for(j=i+1;j<n;++j) 
        if(source[i]==source[j])
        {
                for(k=j;k<n-1;++k) 
             source[k]=source[k+1];
             --n; 
             --j; 
             }
   }
    for(i=0;i<n;++i)
       destination[i]=source[i];
    return i;
}     
