package golang

func getSortedKey(s string) [26]int32 {
	t := [26]int32{}

	for _, c := range s {
		t[c-'a']++
	}

	return t
}

func getProduct(str string) int {
	result := 1

	for i := 0; i < len(str); i++ {
		result *= int(str[i])
	}

	return result
}

func findAnagrams(s string, p string) []int {
	sn := len(s)
	pn := len(p)

	var result []int

	if sn == 0 || pn == 0 || pn > sn {
		return nil
	}

	pp := getProduct(p)

	for i := 0; i <= sn-pn; i++ {
		if getProduct(s[i:i+pn]) == pp {
			result = append(result, i)
		}
	}

	return result
}

func findAnagramsV2(s string, p string) []int {
	sArr, pArr := [26]int{}, [26]int{}

	var result []int

	for _, v := range p {
		pArr[v-'a']++
	}

	for i, v := range s {
		if i >= len(p) {
			sArr[s[i-len(p)]-'a']--
		}

		sArr[v-'a']++
		if sArr == pArr {
			result = append(result, i-len(p)+1)
		}
	}

	return result
}

func findAnagramsV3(s string, p string) []int {
	if len(s) < len(p) {
		return nil
	}

	var pat, mem [26]int
	// filling hashmaps
	for i := range p {
		pat[p[i]-'a']++
		mem[s[i]-'a']++
	}

	var result []int

	for i := 0; i <= len(s)-len(p); i++ {
		if pat == mem {
			result = append(result, i)
		}

		// sliding window, no need to change at last iteration
		if i+len(p) < len(s) {
			mem[s[i]-'a']--
			mem[s[i+len(p)]-'a']++
		}
	}

	return result
}

func findAnagramsV4(s string, p string) []int {
	ana := map[byte]int{}
	length := len(p)

	var result []int

	for _, r := range []byte(p) {
		ana[r]++
	}

	for idx, r := range []byte(s) {
		ana[r]--

		if ana[r] == 0 {
			delete(ana, r)
		}

		if idx-length >= 0 {
			ana[s[idx-length]]++
			if ana[s[idx-length]] == 0 {
				delete(ana, s[idx-length])
			}
		}

		if len(ana) == 0 {
			result = append(result, idx-length+1)
		}
	}

	return result
}
