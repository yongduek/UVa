#include <cmath>
#include <iostream>  
using namespace std;  
  
  
int main() {  
  
 cout << "int: " << sizeof (int) << endl; 
 cout << "unsigned: " << sizeof (unsigned) << endl; 
 cout << "unsigned long: " << sizeof (unsigned long) << endl; 
 cout << "unsigned long long: " << sizeof (unsigned long long) << endl; 

 unsigned long long n;
 printf ("1<<30 = %llu\n", n=1<<30);
 printf ("1<<31 = %llu\n", n=1<<31);
 for (int i=0; i<60; i++) {
	n = 1 << i;
	printf ("1<<%d = %llu %lf\n", i, n, pow(2.,(double)i));
 }
    return 0;  
}  
