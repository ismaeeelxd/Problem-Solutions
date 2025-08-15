function areOccurrencesEqual(s: string): boolean {
    const freq = new Array(26).fill(0);
    const base = 'a'.charCodeAt(0);
    for(const ch of s){
        const index = ch.charCodeAt(0) - base;
        freq[index]++;
    }

    const t = freq[s[0].charCodeAt(0) - base];
    for(const fr of s){
        if(t !== freq[fr.charCodeAt(0) - base]) return false;
    }

    return true;
};
