function removeElement(nums: number[], val: number): number {
    for(let i = 0; i < nums.length; ++i){
        let lastIndex = nums.length - 1;
        if(nums[i] === val){
            nums[i] = nums[lastIndex]; 
            nums.pop();
            i--;
        }
    }

    return nums.length;
};
