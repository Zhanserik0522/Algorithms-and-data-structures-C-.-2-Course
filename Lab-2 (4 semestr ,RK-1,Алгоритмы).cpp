#include <iostream>
using namespace std;

class Solution_67_Add_Binary {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0; 
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result += sum % 2 + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


class Solution_29_Divide_Two_Integers{
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long dvd = abs(static_cast<long long>(dividend));
        long long dvs = abs(static_cast<long long>(divisor));
        long long result = 0;

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long mul = 1;

            
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                mul <<= 1;
            }

           
            dvd -= temp;

           
            result += mul;
        }

        return sign * result;
    }
};



class Solution_190_Reverse_Bits {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

class Solution_191_Number_of_1_Bits {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        while (n != 0) {

            if (n & 1) {
                counter++;
            }

            n >>= 1;
        }
        return counter;
    }
};


double exp(int a, int n) {
    double b = 1.0;

    for (int i = 0; i < abs(n); i++) {
        b = a * b;
    }

    return (n < 0) ? 1.0 / b : b;
}


double exp_2(int a, int n) {

    if (n == 0) {
        return 1;
    }
    if (n % 2 != 0) {
        return a * exp_2(a, n - 1);
    }
    if (n % 2 == 0) {
        double c = (exp_2(a, n / 2));
        return c * c;
    }
}


double exp_3(int a, int n) {
    double ans = 1.0;
    int exponent = abs(n); 

    while (exponent > 0) {
        if (exponent & 1) {
            ans *= a;
        }
        a *= a; 
        exponent >>= 1; 
    }

    return (n < 0) ? 1.0 / ans : ans;
}

int main()
{
    cout << exp(2, -4) << endl;
    cout << exp_2(2, 10) << endl;
    cout << exp_3(2, 10);
    return 0;

}
