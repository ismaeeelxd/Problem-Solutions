function lengthOfLastWord(s: string): number {
    
    if(s.length === 0) return 0;

    let index = s.length - 1;
    let end = -1;
    let start = -1;
    for(let i = index; i >= 0; --i){
        if(s[i] === ' ' && end === -1) continue;
        else if(s[i] === ' ' && end != -1){
            start = i+1;
            return end - start + 1;
        } 
        if(end === -1) end = i;
    }
    return start != -1 ? end - start + 1 : end + 1;
};
