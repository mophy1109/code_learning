// 题目描述
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        int p1 = 0;
        int p2 = rotateArray.size() -1;
        int mid = ceil((p1+p2)/2);

        while(p2>p1){
            if (p2-p1 == 1) break;

            //这里有个坑，如果区间的A[p1], A[p2], A[mid]三个值相等，则用二分无法继续查找最小值，因此需要使用顺序查找
            if(rotateArray[p1] == rotateArray[p2] && rotateArray[p1] == rotateArray[mid]){
                return findMinimum(rotateArray);
            }
            if(rotateArray[mid] >= rotateArray[p1]){
                p1 = mid;
            }else if(rotateArray[mid] <= rotateArray[p2]){
                p2 = mid;
            }
            mid = ceil((p1+p2)/2);
        }
        mid++;
        return rotateArray[mid];
    }

private:
    int findMinimum(const vector<int>& rotateArray){
        int i;
        for (i = 1; i< rotateArray.size(); i++){
            if(rotateArray[i] < rotateArray[i-1]) break;
        }
        return rotateArray[i];
    }
};