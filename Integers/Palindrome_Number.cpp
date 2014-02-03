bool isPalindrome(int x) {
        if(x < 0) return false;

        int pow = 1;

        while(x / 10 >= pow) pow *= 10;

        while(x >= 10){
            if(x / pow != x % 10) return false;

            x  -= x / pow * pow;

            x /= 10;

            pow /= 100;
        }

        return true;
    }
