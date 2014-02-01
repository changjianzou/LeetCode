  int sqrt(int x) {

        if(x <= 1) return x;

        int low = 1, high = x, mid = 0;

        while(low < high)
        {
            mid = (low + high) / 2;

            if(mid == x / mid)
            {
                return mid;
            }else if(mid > x / mid){
                high = mid - 1;
            }else{
                if( mid + 1 > x / (mid+1) ) return mid;
                low = mid + 1;
            }
        }

        return high;
    }
