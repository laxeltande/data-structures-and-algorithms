This project is a sorting program that uses insertion sort (from lecture 1). The command ./testSort2 with arguments (like ./testSort2 35 46 21 17) is used to test it. 

Answer 1
If the signature for mySort stays the same that means for betterSort(int data[], first, last) the first and last should give the size n. This can be achieved by taking first as 0 and last as n-1. So the betterSort would be used as betterSort(d, 0, n - 1) in the mySort function.