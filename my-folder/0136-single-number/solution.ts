function singleNumber(nums: number[]): number {
    let i = 0;
    for(const num of nums){
        i^=num;
    }
    return i;
};
