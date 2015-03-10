#include <iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		char ans[20];
		int index = 0;
		int cur = num / 1000;
		num = num % 1000;
		switch (cur)
		{
		case 1:
			ans[index++] = 'M';
			break;
		case 2:
			ans[index++] = 'M';
			ans[index++] = 'M';
			break;
		case 3:
			ans[index++] = 'M';
			ans[index++] = 'M';
			ans[index++] = 'M';
			break;
		default:
			break;
		}

		cur = num / 100;
		num = num % 100;
		switch (cur)
		{
		case 1:
			ans[index++] = 'C';
			break;
		case 2:
			ans[index++] = 'C';
			ans[index++] = 'C';
			break;
		case 3:
			ans[index++] = 'C';
			ans[index++] = 'C';
			ans[index++] = 'C';
			break;
		case 4:
			ans[index++] = 'C';
			ans[index++] = 'D';
			break;
		case 5:
			ans[index++] = 'D';
			break;
		case 6:
			ans[index++] = 'D';
			ans[index++] = 'C';
			break;
		case 7:
			ans[index++] = 'D';
			ans[index++] = 'C';
			ans[index++] = 'C';
			break;
		case 8:
			ans[index++] = 'D';
			ans[index++] = 'C';
			ans[index++] = 'C';
			ans[index++] = 'C';
			break;
		case 9:
			ans[index++] = 'C';
			ans[index++] = 'M';
			break;
		default:
			break;
		}

		cur = num / 10;
		num = num % 10;
		switch (cur)
		{
		case 1:
			ans[index++] = 'X';
			break;
		case 2:
			ans[index++] = 'X';
			ans[index++] = 'X';
			break;
		case 3:
			ans[index++] = 'X';
			ans[index++] = 'X';
			ans[index++] = 'X';
			break;
		case 4:
			ans[index++] = 'X';
			ans[index++] = 'L';
			break;
		case 5:
			ans[index++] = 'L';
			break;
		case 6:
			ans[index++] = 'L';
			ans[index++] = 'X';
			break;
		case 7:
			ans[index++] = 'L';
			ans[index++] = 'X';
			ans[index++] = 'X';
			break;
		case 8:
			ans[index++] = 'L';
			ans[index++] = 'X';
			ans[index++] = 'X';
			ans[index++] = 'X';
			break;
		case 9:
			ans[index++] = 'X';
			ans[index++] = 'C';
			break;
		default:
			break;
		}

		cur = num;
		switch (cur)
		{
		case 1:
			ans[index++] = 'I';
			break;
		case 2:
			ans[index++] = 'I';
			ans[index++] = 'I';
			break;
		case 3:
			ans[index++] = 'I';
			ans[index++] = 'I';
			ans[index++] = 'I';
			break;
		case 4:
			ans[index++] = 'I';
			ans[index++] = 'V';
			break;
		case 5:
			ans[index++] = 'V';
			break;
		case 6:
			ans[index++] = 'V';
			ans[index++] = 'I';
			break;
		case 7:
			ans[index++] = 'V';
			ans[index++] = 'I';
			ans[index++] = 'I';
			break;
		case 8:
			ans[index++] = 'V';
			ans[index++] = 'I';
			ans[index++] = 'I';
			ans[index++] = 'I';
			break;
		case 9:
			ans[index++] = 'I';
			ans[index++] = 'X';
			break;
		default:
			break;
		}

		ans[index] = '\0';
		return string(ans);
	}
};

//int main(){
//	Solution s;
//	cout << s.intToRoman(2893).c_str() << endl;
//	return 0;
//}

//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

//I:1
//V:5
//X:10
//L:50
//C:100
//D:500
//M:1000
