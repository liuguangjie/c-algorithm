#include <iostream>

using namespace std;

class Array{
    int len;
    int *data;
public:
    Array() {len=0; cout << "start" << endl;}
    Array(int len):len(len) {
        
    }
    void print() {
        for (int i=0;i<len; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;

    }
    Array& add(int ele){
        int *newArr = new int[len+1];
        for (int i=0;i<len;i++) {
            newArr[i] = data[i];
        }
        newArr[len] = ele;
        data = newArr;
        len ++;
        return  *this;
    }
    
    Array& del(int index) {
        int *newArr = new int[len - 1];

        for (int i=0;i<len-1;i++) {
            if (i < index) {
                newArr[i] = data[i];
            } else {
                newArr[i] = data[i+1];
            }
        }
        data = newArr;
        len--;
        return *this;
    }

    Array& insert(int index, int ele) {
        // copy 之前的
        int *newArr = new int[len + 1];
        int i= 0;
        for(i=0; i< index;i++) {
            newArr[i] = data[i];
        }
        // 插入点
        newArr[index] = ele;

        // copy剩下的数据
        for (i = len; i > index; i--) {
            newArr[i] = data[i-1];
        }

        data = newArr;
        len++;
        return *this;
    }

    ~Array(){}
};

int main()
{
    Array arr;
    arr.add(8).add(9).add(1).add(10);
    arr.print();

    arr.del(2);
    arr.print();


    arr.insert(1, 666).insert(4, 777);

    arr.print();

}
