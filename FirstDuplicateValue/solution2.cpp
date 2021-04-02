#include <vector>
using namespace std;

/* 因为数组元素的取值范围是 1 ~ array.size()
 * 所以可以将元素值，映射为数组index-1，首次遇到某个元素时将映射后下标所指向的值其乘以-1
 * 这样到下次再遇到相同的元素时，只要判断其映射后的值是否为负数，即可判断是否遇到重复值
 *
 */
int firstDuplicateValue(vector<int> array) 
{ 
	for (int i = 0; i < array.size(); i++) {
		int absValue = abs(array[i]);
		if (array[absValue-1] < 0) {
			return absValue;
		}
		array[absValue-1] *= -1;
	}
	
	return -1;
}

