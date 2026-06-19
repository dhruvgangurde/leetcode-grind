class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i: nums){
            totalSum += i;
        }
        int leftSum = 0;
        for(int i = 0; i < n; i++){
            int rightSum = totalSum - leftSum - nums[i];
            int curr = abs(rightSum - leftSum);
            leftSum += nums[i];
            nums[i] = curr;
        }
        return nums;
    }
};
#pragma GCC optimize("Ofast")
static constexpr size_t BUFFER_SIZE = 64ull << 20;
alignas(std::max_align_t)
static unsigned char BUFFER[BUFFER_SIZE];
static unsigned char* ptr = BUFFER;
void* operator new(std::size_t n) {
    constexpr size_t A = alignof(std::max_align_t);
    n = (n + A - 1) & ~(A - 1);
    if (ptr + n > BUFFER + BUFFER_SIZE)throw std::bad_alloc();
    void* r = ptr;    ptr += n;
    return r;
}
void* operator new[](std::size_t n) {
    return operator new(n);
}
void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, std::size_t) noexcept {}
void operator delete[](void*, std::size_t) noexcept {}