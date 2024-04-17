class Solution {
public:
   bool isPalindrome(long long x) {
	if (x < 0)
		return false;
	if (x < 10)
		return true;
	long long tmp = x;
	long long reversed = 0;

	while (tmp > 0) {
		reversed = reversed * 10 + tmp % 10;
		tmp /= 10;
	}
	return reversed == x;
}
};
