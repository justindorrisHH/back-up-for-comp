class PrimeSimple{
    public static void main(string[]){
        boolean prime ;//boolean . Is the number prime?
        long n;// number to check
        long count;//count the total primes
        double ddiv;//double divisor
        int div;// integer divisor
        int pivot ;  //the pivot is halfway
        n = 2;
        while (n < 100){
                prime = true; //asume the number is prime
                pivot = (int)math.sqrt(n);
                for (div = 2; div < pivot+1;div++){
                        ddiv= div;
                        if ((n % 2 == 0) && (n > 2)) {
                                prime = false;
                                break;
                        }//end if
                        //system.out.println(n+"     "n+/ddiv + "< double    integer >" + n/div);//debug
                        if ((n / ddiv) == (n / div)) {
                            prime = false;
                            break;
                        }//end if
                }//end for
                if(prime)system.out.println(n+ " is prime ");
                //if(prime)system.out.println(n+ " ");
            n++;
        }//end while
    }//end main
}//end PrimeSimple
