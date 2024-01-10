class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2){
        int l1 = nums1.length;
        int l2 = nums2.length;
        int []result = new int[l1+l2];
        for(int i=0;i < l1 ; i++)
        {
            result[i] = nums1[i];
        }
        for(int i=0,int j=l1 ; i<l2 ; i++,j++)
        {
            result[j] = nums2[i];
        }

        for(int m=0; m<result.length-1 ; m++)
        {
            for(int n=m+1 ; n<result.length ; j++)
            {
                if(result[m] > result[n])
                {
                    result[m] = result[m] + result[n];
                    result[n] = result[m] - result[n];
                    result[m] = result[m] - result[n];
                }
            }
        }

        if(result.length%2==0){
            
        }
    
    }
}