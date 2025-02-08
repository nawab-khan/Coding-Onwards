/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &mount, int size){

        int l = 0, r = size - 1, m;

        while(l <= r){
            
            m = (l + r)/2;

            if(mount.get(m) > mount.get(m+1))
                r = m - 1;
            else
                l = m + 1;

        }

        return l;

    }

    int incSearch(MountainArray &mount, int l, int r, int target){

        while(l <= r){

            int m = (l + r)/2;

            if(mount.get(m) == target)
                return m;
            else if(mount.get(m) > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;

    }

        int decSearch(MountainArray &mount, int l, int r, int target){

        while(l <= r){

            int m = (l + r)/2;

            if(mount.get(m) == target)
                return m;
            else if(mount.get(m) < target)
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;

    }

    int findInMountainArray(int target, MountainArray &mount) {
        
        int peakPos = findPeak(mount, mount.length());

        int a = incSearch(mount, 0, peakPos, target);
        int b = decSearch(mount, peakPos + 1, mount.length() - 1, target);

        if(a != -1)
            return a;

        return b;

    }
};