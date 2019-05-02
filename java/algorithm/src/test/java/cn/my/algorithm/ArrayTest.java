package cn.my.algorithm;

import cn.my.algorithm.array.MyArray;
import org.junit.Test;

import java.util.Arrays;

public class ArrayTest {

    @Test
    public void t1() {
        /*MyArray myArray = new MyArray();
        myArray.add(3).add(4).add(5).add(6);
        myArray.print();*/
        System.out.println(1/2);
    }

    /**
     * 删除数组元素
     */
    @Test
    public void t2() {

        int[] arr = new int[]{2,4,5,7,8,9};
        /*System.out.println(Arrays.toString(arr));
        boolean f = false;

        int del = 9;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == del) {
                f = true;
            }
            if (f) {
                if (i + 1 == arr.length) {
                    arr[i] = 0;
                } else {
                    arr[i] = arr[i+1];
                }

            }
        }
        System.out.println(Arrays.toString(arr));*/
        System.out.println(Arrays.toString(arr));
        int del = 5;
        int index = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == del) {
                index = i;
                break;
            }
        }

        int[] newArr = new int[arr.length-1];

        for (int i = 0; i < newArr.length; i++) {
            if (i < index) {
                newArr[i] = arr[i];
            } else {
                newArr[i] = arr[i+1];
            }

        }

        arr = newArr;
        System.out.println(Arrays.toString(arr));


    }


    @Test
    public void testBinarSearch() {

        int[] arr = {1,2,3,4,5,6,7,8,9};


        int left=0, right=arr.length;
        int mid;
        int a = 41;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] > a) {
                right = mid -1;
            } else if (arr[mid] < a) {
                left = mid +1;
            } else if (arr[mid] == a) {
                System.out.println("找到了...");
                break;
            } else {
                System.out.println("没有找到");
                break;
            }
        }

    }

}
