class Solution {
public:
    /*
    Here, variable c is carry, and ans is return value. Denote ^ is xor operation.

    Proof: the loop invariant of the while loop above code is: if there is no carry in any ith bit of a + b exists, a ^ b must equal to a + b: let's consider a example: 2 in 2 base is 10, and 1 in 2 base is 01, there is no carry in any bit of (2 + 1), that's the time (2+1) = (2^1) exists. Otherwise, if we know a ^ b and carry for each bit of a + b, let's say c, then (a ^ b) + (c<<1) must equal to a + b; Here is an example: 3 in 2 base is 11, while 1 in 2 base is 01, obviously, carry is 01 corresponding to each bit, therefore, 3+1 = 3^1+(1<<1) holds (3^1 = 2, 1<<1 = 2).

    in the beginning, "c = a & b" and "c != 0" used to check if there is any carry for a + b exists: if not, then we got result directly (case 2 + 1), if there is any carry bit (case 3+1), then "c <<= 1" used to shift and "ans ^ c" used to calculate new "bit adding result", after new adding result is calculate, we have two situation: if the result is final result, then new carry must be zero, otherwise not (according to loop invariant); so carry is updated for each bit "c = ans & c". After above step, the ans keeps the xor result of ans and carry c, carry c holds the result of new carry for each bit of (previous ans + previous c<<1), till carry is gone, then ans holds final result
    */
    
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = a&b;
        
        while(carry != 0)
        {
            carry <<= 1;
            int ans_temp = sum^carry;
            carry = sum&carry;
            sum = ans_temp;
        }
        
        return sum;
    }
};