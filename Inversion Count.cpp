typedef long long ll;
    ll ans = 0;
    long long int inversionCount(long long arr[], long long N)
    {
        ans = 0;
        mergeSort(arr, 0, N-1);
        return ans;
    }
    void mergeSort(ll arr[], ll lo, ll hi) {
        if(lo<hi) {
            ll mid = lo + (hi-lo)/2;
            mergeSort(arr, lo, mid);
            mergeSort(arr, mid+1, hi);
            merge(arr, lo, mid, hi);
        }
    }
    void merge(ll arr[], ll lo, ll mid, ll hi) {
        ll n1 = mid-lo+1, n2 = hi-mid;
        ll arr1[n1], arr2[n2];
        for(ll i=0; i<n1; i++) arr1[i] = arr[lo+i];
        for(ll i=0; i<n2; i++) arr2[i] = arr[mid+i+1];
        ll i=0, j=0, k=lo;
        while(i<n1 && j<n2) {
            if(arr1[i]<=arr2[j]) arr[k++] = arr1[i++];
            else {
                ans += n1 - i; // Only this line added in merge sort code
                arr[k++] = arr2[j++];
            }
        }
        while(i<n1) arr[k++] = arr1[i++];
        while(j<n2) arr[k++] = arr2[j++];
    }