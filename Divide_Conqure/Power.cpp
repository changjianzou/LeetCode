 //recursive
    double pow2(double x, int n) {

        if(n == 0) return 1;

        double half = pow(x, n/2);

        return n % 2 == 0 ? half*half : half*half*x;

    }

    double pow(double x, int n)
    {
        bool sign = n >= 0 ? true : false;

        n = sign ? n : -n;

        double p = pow2(x,n);

        return sign ? p : 1 / p;
    }
