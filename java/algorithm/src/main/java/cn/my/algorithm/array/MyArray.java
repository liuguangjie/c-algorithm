package cn.my.algorithm.array;

public class MyArray {

    private int[] arr = null;
    private int len;
    private int max;
    public MyArray() {
        this(3);
    }

    public MyArray(int max) {
        this.max = max;
        this.len = 0;
        arr = new int[max];

    }


    public MyArray add(int elem) {
        checkCapacity();
        arr[len++] = elem;
        return this;
    }

    /**检查扩容*/
    protected void checkCapacity() {
        /**
         *
         public static native void arraycopy(Object src,  int  srcPos,
         Object dest, int destPos,
         int length
         */
        if (len >= max) {
            int[] dest = new int[len*2];
            System.arraycopy(arr, 0, dest,0, arr.length);
            arr = dest;
        }
    }


    public void print() {

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }


}
